
`include "defines.svh"

// 5-stage pipelined single RV32I core: IF -> ID -> EX -> MEM -> WB
//
// Hazard handling:
//   - Data hazards resolved by EX/MEM and MEM/WB forwarding
//   - Load-use hazards resolved by a one cycle stall
//   - Control hazards resolved by redirecting in EX and flushing IF/ID + ID/EX
//
// Exceptions are precise. A faulting instruction is detected in the stage that
// can see the fault, the flag travels with it down the pipeline, and the trap
// is only taken when that instruction reaches WB. Everything older has already
// committed and everything younger is discarded.The trap latches a sticky halt
// (see the 'trapped' flag): once a trap is taken the core parks its PC at the
// faulting instruction and commits nothing further until reset, so the halt is
// permanent rather than a single cycle.
//
// ============================================================================
// TABLE OF CONTENTS
// ============================================================================
// This file is organized in two halves: every signal is declared first
// (grouped by pipeline stage, in pipeline order), then every stage's logic is
// implemented below (in the same order), so the declarations and the
// implementation can each be read top-to-bottom without jumping around.
//
//   SIGNAL DECLARATIONS
//     - Cross-Stage Control Signals      (stall, control_taken/target)
//     - IF   : Instruction Fetch
//     - IF/ID: Pipeline Register
//     - ID   : Instruction Decode
//     - ID/EX: Pipeline Register
//     - EX   : Execute
//     - EX/MEM: Pipeline Register
//     - MEM  : Memory Access
//     - MEM/WB: Pipeline Register
//     - WB   : Writeback
//
//   STAGE IMPLEMENTATION
//     - IF   : PC update, instruction memory, branch prediction
//     - IF/ID Pipeline Register
//     - ID   : Decode, register file, exception detection, hazard unit
//     - ID/EX Pipeline Register
//     - EX   : Forwarding, ALU, branch/JAL/JALR resolution, misprediction
//     - EX/MEM Pipeline Register
//     - MEM  : Data memory, fault detection, load extraction/extension
//     - MEM/WB Pipeline Register
//     - WB   : Writeback mux
//     - Trap Reporting
// ============================================================================

module cpu_top(
    input logic clk,
    input logic reset,

    // Trap interface
    output logic        trap_valid,
    output logic [3:0]  trap_cause,
    output logic [31:0] trap_pc
);

///////////////////////////////////////////
// Cross-Stage Control Signals
///////////////////////////////////////////

// Pipeline stall signal
logic stall;

// control_taken is asserted when a control instruction takes effect -- JAL,
// a taken branch, or JALR -- and redirects the PC.
// control_target is the target address to jump to.
logic control_taken;
logic [31:0] control_target;

///////////////////////////////////////////
// Instruction Fetch (IF) Signals
///////////////////////////////////////////

// Program counter, holds the address of the instruction
// currently being fetched.
logic [31:0] pc;

// PC+4 for the next instruction, if no control instruction
// redirects it first.
logic [31:0] pc_plus_4;

// Instruction fetched from instruction memory.
logic [31:0] instr;

// IF-stage prediction signals: used to predict whether a branch is taken
// and, along with JAL, to compute its PC-relative target before decode.
logic           if_is_branch;
logic           if_is_jal;
logic [31:0]    if_imm_b;
logic [31:0]    if_imm_j;
logic [31:0]    if_pc_rel_target;
logic           bht_predict_taken;
logic           predict_taken;
logic [31:0]    predict_target;
logic [31:0]    next_pc;

// Processor halt. trap_valid is only asserted for the single cycle the faulting
// instruction sits in WB, so freezing anything on trap_valid alone lasts one
// cycle and the pipeline resumes the moment it drops. 'trapped' latches on the
// first trap and clears only on reset, so the core stays halted. trap_hold is
// the OR of the two: true on the trap cycle itself and every cycle after.
logic           trapped;
logic           trap_hold;
assign trap_hold = trap_valid || trapped;

///////////////////////////////////////////
// IF/ID Pipeline Register Signals
///////////////////////////////////////////

// Instruction pipelined from IF to ID stage.
logic [31:0] if_id_instr;

// PC of the instruction pipelined into ID.
// Needed for branch/JAL target calculation later.
logic [31:0] if_id_pc;

// PC+4 of the instruction pipelined into ID.
logic [31:0]    if_id_pc_plus_4;
logic           if_id_valid; // 0 means there is a bubble injected by a reset/flush
logic           if_id_predict_taken;
logic [31:0]    if_id_predict_target;

///////////////////////////////////////////
// Instruction Decode (ID) Signals
///////////////////////////////////////////

// Raw decoded instruction fields.
logic [6:0] opcode;
logic [2:0] funct3;

// Source registers 1 & 2 (rs1, rs2)
// and register destination (rd).
logic [4:0] rd, rs1, rs2;

// Decoded sign-extended immediate value.
logic [31:0] imm;

// ALU operation selected by decode.
logic [3:0] alu_ctrl;
logic       illegal_instr;

// Instruction classification flags from decode.
// These describe what type of instruction is currently in ID.
logic is_load, is_store, is_branch;
logic is_itype;
logic is_jal, is_jalr, is_lui, is_auipc;
logic is_ecall, is_ebreak;

// Source-register usage flags. Prevent false stalls/forwarding
// on instructions that do not actually read rs1/rs2.
logic uses_rs1, uses_rs2;
logic reg_write;

logic [1:0] mem_size;
logic       mem_unsigned;

// Register file read data for rs1 and rs2.
logic [31:0] rd1, rd2;

// Exception raised in ID. Only meaningful for a real instruction, so it is
// qualified with the validity of the IF/ID slot.
logic id_exception;
logic [3:0] id_cause;

///////////////////////////////////////////
// ID/EX Pipeline Register Signals
///////////////////////////////////////////

// Instruction and PC carried into EX.
// id_ex_pc is required for branch/JAL PC-relative target calculation.
logic [31:0] id_ex_instr;
logic [31:0] id_ex_pc;

// PC+4 of the instruction pipelined into EX.
logic [31:0] id_ex_pc_plus_4;

// Whether ID/EX holds a valid instruction or is a bubble.
logic   id_ex_valid;

// Register operand values pipelined from ID to EX.
logic [31:0] id_ex_rd1, id_ex_rd2;

// Immediate value pipelined into EX.
logic [31:0] id_ex_imm;

// Register indexes carried into EX, needed for forwarding
// decisions and writeback destination tracking.
logic [4:0] id_ex_rd, id_ex_rs1, id_ex_rs2;

// Opcode/funct/control values carried into EX.
logic [6:0] id_ex_opcode;
logic [2:0] id_ex_funct3;
logic [3:0] id_ex_alu_ctrl;

// Instruction type flags carried into EX.
// These signals are needed in the EX stage to drive its decisions.
logic id_ex_is_itype, id_ex_is_load, id_ex_is_store;
logic id_ex_is_branch, id_ex_is_jal, id_ex_is_jalr;
logic id_ex_is_lui, id_ex_is_auipc;

// Pipelined source-usage flags.
// Used by forwarding to avoid checking unused source operands.
logic id_ex_uses_rs1, id_ex_uses_rs2;
logic id_ex_reg_write;

logic [1:0]  id_ex_mem_size;
logic        id_ex_mem_unsigned;

logic        id_ex_exception;
logic [3:0]  id_ex_cause;
logic        id_ex_predict_taken;
logic [31:0] id_ex_predict_target;

///////////////////////////////////////////
// EX Stage Signals
///////////////////////////////////////////

logic [1:0] forward_a_sel, forward_b_sel;
logic [31:0] forward_a, forward_b;

// ALU operands and result.
logic [31:0] alu_operand_a, alu_operand_b;
logic [31:0] alu_result;

// Selects whether ALU operand B comes from an immediate or forwarded rs2.
// Used for I-type, LW/SW address calculation, JALR target calculation, and LUI.
logic ex_use_imm;
logic ex_use_pc;

// Control decision signals from branch_control.
logic branch_cond_taken;
logic jal_taken;
logic jalr_taken;
logic actual_taken;
logic [31:0] actual_target;

// Branch predictor bookkeeping.
logic bp_update_en;
logic mispredict;

///////////////////////////////////////////
// EX/MEM Pipeline Register Signals
///////////////////////////////////////////

// Instruction carried into MEM.
logic [31:0] ex_mem_instr;
logic [31:0] ex_mem_pc;
logic ex_mem_valid;

// ALU result carried into MEM.
// For LW/SW, this is the effective memory address.
// For ALU/LUI instructions, this is the value eventually written back.
logic [31:0] ex_mem_result;

// Store data carried into MEM.
// This must use forwarded rs2 data so stores can write recently produced values.
logic [31:0] ex_mem_store_data;

// PC+4 carried into MEM.
// Used for JAL/JALR link writeback and forwarding.
logic [31:0] ex_mem_pc_plus_4;

// Destination register and opcode carried into MEM.
logic [4:0] ex_mem_rd;
logic [6:0] ex_mem_opcode;

// True when the instruction is JAL or JALR.
// These instructions write PC+4 instead of ALU/memory data.
logic ex_mem_is_link;

// Signals whether the instruction is valid and (separately) whether it has a
// value that can be forwarded to a younger instruction this cycle.
logic ex_mem_reg_write;
logic ex_mem_can_forward;
logic ex_mem_is_load, ex_mem_is_store;

logic [1:0] ex_mem_mem_size;
logic ex_mem_mem_unsigned;

// Signals whether there is an exception in flight, and its cause.
logic ex_mem_exception;
logic [3:0] ex_mem_cause;

// Data forwarded out of this pipeline register.
logic [31:0] ex_mem_forward_data;

///////////////////////////////////////////
// MEM Stage Signals
///////////////////////////////////////////

// Data memory control signals: write enable and read enable.
logic mem_we;
logic mem_re;

// Data read from data memory during a load.
logic [31:0] mem_read_data;

// Load value after field extraction + sign/zero extension.
logic [31:0] mem_load_extended;

// Signals whether the access is misaligned or out of the memory window.
logic mem_misaligned;
logic mem_out_of_range;

// Signals whether there is an exception this cycle, and its cause.
logic mem_exception;
logic [3:0] mem_cause;

///////////////////////////////////////////
// MEM/WB Pipeline Register Signals
///////////////////////////////////////////

// Instruction carried into WB.
logic [31:0] mem_wb_instr;

// PC and PC+4 carried into WB (the latter for JAL/JALR).
logic [31:0] mem_wb_pc;
logic [31:0] mem_wb_pc_plus_4;

// Whether the instruction is valid in the pipeline.
logic mem_wb_valid;

// Final non-link result carried into WB.
// For loads, this is the extended memory data.
// For ALU/LUI instructions, this is the ALU result.
logic [31:0] mem_wb_result;
logic [31:0] mem_wb_read_data;

// Destination register and opcode carried into WB.
logic [4:0] mem_wb_rd;
logic [6:0] mem_wb_opcode;

// True when WB should write PC+4 because the instruction was JAL/JALR.
logic mem_wb_is_link;

logic mem_wb_reg_write;
logic mem_wb_is_load;

logic mem_wb_exception;
logic [3:0] mem_wb_cause;

///////////////////////////////////////////
// WB Stage Signals
///////////////////////////////////////////

// Register file write enable.
logic wb_we;

// Destination register and data written into the register file.
logic [31:0]    wb_data;
logic [4:0]     wb_rd;


// ============================================================================
// STAGE IMPLEMENTATION
// ============================================================================

///////////////////////////////////////////
// Instruction Fetch (IF) Stage
///////////////////////////////////////////

// PC of the next sequential instruction.
assign pc_plus_4 = pc + 32'd4;

// Instruction memory instance.
instruction_memory imem_inst(
    .addr(pc),
    .instr(instr)
);

///////////////////////////////////////////
// Branch Predictor
//
// Enough of the fetched word is examined here to recognize a branch or JAL
// and rebuild its PC-relative target. No branch target buffer is required;
// only the direction needs predicting. JALR is register-relative, so it is
// left to EX to resolve.

assign if_is_branch = (instr[6:0] == OPCODE_BRANCH);
assign if_is_jal = (instr[6:0] == OPCODE_JAL);

assign if_imm_b = { {19{instr[31]}}, instr[31], instr[7],
                    instr[30:25], instr[11:8], 1'b0 };
assign if_imm_j = { {11{instr[31]}}, instr[31], instr[19:12],
                    instr[20], instr[30:21], 1'b0 };

assign if_pc_rel_target = pc + (if_is_jal ? if_imm_j : if_imm_b);

branch_predictor bp(
    .clk(clk),
    .reset(reset),

    .query_pc(pc),
    .predict_taken(bht_predict_taken),

    .update_en(bp_update_en),
    .update_pc(id_ex_pc),
    .update_taken(branch_cond_taken)
);

// JAL is unconditional, so it is always predicted taken. A conditional
// branch follows the history table.
assign predict_taken = if_is_jal || (if_is_branch && bht_predict_taken);
assign predict_target = if_pc_rel_target;

// Next-PC priority: a resolved misprediction in EX always wins over a
// speculative prediction in IF, because EX is working with real operands.
always_comb begin
    if (control_taken)
        next_pc = control_target;
    else if (predict_taken)
        next_pc = predict_target;
    else
        next_pc = pc_plus_4;
end

// Processor halt latch. Set on the first trap and held until reset, so the core
// stays stopped instead of resuming the cycle after trap_valid drops.
always_ff @(posedge clk) begin
    if (reset)
        trapped <= 1'b0;
    else if (trap_valid)
        trapped <= 1'b1;
end


// Once a trap is taken the core stops fetching. A full implementation would
// vector to a handler here; this core halts so the trap is observable. The
// freeze is gated on trap_hold (not trap_valid) so it persists past the single
// commit cycle and the PC stays parked at the faulting instruction.
always_ff @(posedge clk) begin
    if (reset)
        pc <= 32'd0;
    else if (trap_hold)
        pc <= pc;          // hold at the faulting point
    else if (!stall || control_taken)
        pc <= next_pc;
end

///////////////////////////////////////////
// IF/ID Pipeline Register
///////////////////////////////////////////

// IF/ID holds the fetched instruction and its PC.
// On redirects, IF/ID is flushed.
// On stalls, IF/ID holds its current instruction value.
always_ff @(posedge clk) begin
    if (reset) begin
        if_id_instr          <= 32'd0;
        if_id_pc             <= 32'd0;
        if_id_pc_plus_4      <= 32'd0;
        if_id_valid          <= 1'b0;
        if_id_predict_taken  <= 1'b0;
        if_id_predict_target <= 32'd0;
    end
    else if (control_taken || trap_hold) begin
        if_id_instr          <= 32'd0;
        if_id_pc             <= 32'd0;
        if_id_pc_plus_4      <= 32'd0;
        if_id_valid          <= 1'b0;
        if_id_predict_taken  <= 1'b0;
        if_id_predict_target <= 32'd0;
    end
    else if (!stall) begin
        if_id_instr          <= instr;
        if_id_pc             <= pc;
        if_id_pc_plus_4      <= pc_plus_4;
        if_id_valid          <= 1'b1;
        if_id_predict_taken  <= predict_taken;
        if_id_predict_target <= predict_target;
    end
end

///////////////////////////////////////////
// Instruction Decode (ID) and Register Read
///////////////////////////////////////////

decode dec(
    .instr(if_id_instr),

    .opcode(opcode),
    .funct3(funct3),
    .rd(rd),
    .rs1(rs1),
    .rs2(rs2),

    .imm(imm),

    .is_load(is_load),
    .is_store(is_store),
    .is_branch(is_branch),
    .is_itype(is_itype),
    .is_jal(is_jal),
    .is_jalr(is_jalr),
    .is_lui(is_lui),
    .is_auipc(is_auipc),
    .is_ecall(is_ecall),
    .is_ebreak(is_ebreak),

    .uses_rs1(uses_rs1),
    .uses_rs2(uses_rs2),
    .reg_write(reg_write),

    .mem_size(mem_size),
    .mem_unsigned(mem_unsigned),

    .alu_ctrl(alu_ctrl),
    .illegal_instr(illegal_instr)
);

// Register file instance.
register_file rf(
    .clk(clk),
    .we(wb_we),
    .rs1(rs1),
    .rs2(rs2),
    .rd(wb_rd),
    .wd(wb_data),
    .rd1(rd1),
    .rd2(rd2)
);

// Exceptions visible at decode time. Environment calls are reported here too,
// since they are defined to trap unconditionally.
always_comb begin
    id_exception = 1'b0;
    id_cause = CAUSE_NONE;

    if (if_id_valid) begin
        if (illegal_instr) begin
            id_exception = 1'b1;
            id_cause = CAUSE_ILLEGAL_INSTR;
        end
        else if (is_ecall) begin
            id_exception = 1'b1;
            id_cause = CAUSE_ECALL;
        end
        else if (is_ebreak) begin
            id_exception = 1'b1;
            id_cause = CAUSE_BREAKPOINT;
        end
    end
end

///////////////////////////////////////////
// Hazard Unit - Load-Use Stall Detection
///////////////////////////////////////////

// Detects load-use hazards between the instruction in EX and the instruction
// in ID. If ID uses the destination of a load currently in EX, stall one cycle.
hazard_unit hazard_unit_inst(
    .id_ex_is_load(id_ex_is_load),
    .id_ex_rd(id_ex_rd),

    .id_rs1(rs1),
    .id_rs2(rs2),

    .id_uses_rs1(uses_rs1),
    .id_uses_rs2(uses_rs2),

    .stall(stall)
);

///////////////////////////////////////////
// ID/EX Pipeline Register
///////////////////////////////////////////

// ID/EX is cleared on reset, control redirect, stall, or trap.
// Clearing on stall inserts a bubble into EX while IF/ID are held frozen.
// Clearing on control_taken removes the wrong-path instruction in decode.
// trap_hold (not trap_valid) keeps EX starved for every cyccle after a trap
always_ff @(posedge clk) begin
    if (reset || control_taken || stall || trap_hold) begin
        id_ex_instr     <= 32'd0;
        id_ex_pc        <= 32'd0;
        id_ex_pc_plus_4 <= 32'd0;
        id_ex_valid     <= 1'b0;

        id_ex_opcode    <= 7'd0;
        id_ex_funct3    <= 3'd0;

        id_ex_rd           <= 5'd0;
        id_ex_rs1          <= 5'd0;
        id_ex_rs2          <= 5'd0;
        id_ex_rd1          <= 32'd0;
        id_ex_rd2          <= 32'd0;
        id_ex_imm          <= 32'd0;

        id_ex_alu_ctrl  <= ALU_NOP;

        id_ex_is_itype  <= 1'b0;
        id_ex_is_load   <= 1'b0;
        id_ex_is_store  <= 1'b0;
        id_ex_is_branch <= 1'b0;
        id_ex_is_jal    <= 1'b0;
        id_ex_is_jalr   <= 1'b0;
        id_ex_is_lui    <= 1'b0;
        id_ex_is_auipc  <= 1'b0;

        id_ex_uses_rs1  <= 1'b0;
        id_ex_uses_rs2  <= 1'b0;
        id_ex_reg_write <= 1'b0;

        id_ex_mem_size     <= MEM_SZ_WORD;
        id_ex_mem_unsigned <= 1'b0;

        id_ex_exception <= 1'b0;
        id_ex_cause     <= CAUSE_NONE;

        id_ex_predict_taken  <= 1'b0;
        id_ex_predict_target <= 32'd0;
    end
    else begin
        // Same-cycle writeback-to-decode bypass, so a register read in ID is
        // never stale when the same register is written back this cycle.
        id_ex_rd1 <= (wb_we && (wb_rd == rs1)) ? wb_data : rd1;
        id_ex_rd2 <= (wb_we && (wb_rd == rs2)) ? wb_data : rd2;

        // Pipeline the decoded instruction into EX.
        id_ex_instr     <= if_id_instr;
        id_ex_pc        <= if_id_pc;
        id_ex_pc_plus_4 <= if_id_pc_plus_4;
        id_ex_valid     <= if_id_valid;

        id_ex_opcode <= opcode;
        id_ex_funct3 <= funct3;

        id_ex_rd  <= rd;
        id_ex_rs1 <= rs1;
        id_ex_rs2 <= rs2;

        id_ex_imm      <= imm;
        id_ex_alu_ctrl <= alu_ctrl;

        id_ex_is_itype  <= is_itype;
        id_ex_is_load   <= is_load;
        id_ex_is_store  <= is_store;
        id_ex_is_branch <= is_branch;
        id_ex_is_jal    <= is_jal;
        id_ex_is_jalr   <= is_jalr;
        id_ex_is_lui    <= is_lui;
        id_ex_is_auipc  <= is_auipc;

        id_ex_uses_rs1 <= uses_rs1;
        id_ex_uses_rs2 <= uses_rs2;

        // A faulting instruction must not write architectural state.
        id_ex_reg_write <= reg_write && if_id_valid && !id_exception;

        id_ex_mem_size     <= mem_size;
        id_ex_mem_unsigned <= mem_unsigned;

        id_ex_exception <= id_exception;
        id_ex_cause     <= id_cause;

        id_ex_predict_taken  <= if_id_predict_taken;
        id_ex_predict_target <= if_id_predict_target;
    end
end

///////////////////////////////////////////
// Forwarding Unit
///////////////////////////////////////////

// Produces forwarding select values for EX-stage operands.
// The actual muxing stays in this file so the datapath flow is visible.
forwarding_unit fwd_unit(

    .id_ex_rs1(id_ex_rs1),
    .id_ex_rs2(id_ex_rs2),

    .id_ex_uses_rs1(id_ex_uses_rs1),
    .id_ex_uses_rs2(id_ex_uses_rs2),

    .ex_mem_rd(ex_mem_rd),
    .ex_mem_reg_write(ex_mem_can_forward),

    .mem_wb_rd(mem_wb_rd),
    .mem_wb_reg_write(mem_wb_reg_write),

    .forward_a_sel(forward_a_sel),
    .forward_b_sel(forward_b_sel)
);

///////////////////////////////////////////
// Forwarding Muxes
///////////////////////////////////////////

// Select the final ALU/branch operands; priority is already encoded upstream.
//   00 = ID/EX register value
//   01 = MEM/WB forwarding
//   10 = EX/MEM forwarding
always_comb begin

    case (forward_a_sel)
        2'b10:   forward_a = ex_mem_forward_data;
        2'b01:   forward_a = wb_data;
        default: forward_a = id_ex_rd1;
    endcase

    case (forward_b_sel)
        2'b10:   forward_b = ex_mem_forward_data;
        2'b01:   forward_b = wb_data;
        default: forward_b = id_ex_rd2;
    endcase
end

///////////////////////////////////////////
// EX Stage - ALU Control Flow
///////////////////////////////////////////

// AUIPC adds the upper immediate to its own PC, so operand A comes from the
// pipeline rather than the register file.
assign ex_use_pc = id_ex_is_auipc;

// Determines whether operand B should be an immediate or forwarded register
// data. JAL does not need this path because its target is computed inside
// branch_control using PC + immediate.
assign ex_use_imm =
    id_ex_is_itype ||
    id_ex_is_load  ||
    id_ex_is_store ||
    id_ex_is_jalr  ||
    id_ex_is_lui   ||
    id_ex_is_auipc;

assign alu_operand_a = ex_use_pc ? id_ex_pc : forward_a;
assign alu_operand_b = ex_use_imm ? id_ex_imm : forward_b;

// Branch/JAL/JALR control unit.
// Produces the redirect decision, redirect target, and debug-visible status
// signals.
branch_control branch_ctrl(

    .id_ex_is_branch(id_ex_is_branch),
    .id_ex_is_jal(id_ex_is_jal),
    .id_ex_is_jalr(id_ex_is_jalr),

    .id_ex_funct3(id_ex_funct3),

    .id_ex_pc(id_ex_pc),
    .id_ex_imm(id_ex_imm),

    .forward_a(forward_a),
    .forward_b(forward_b),

    .branch_cond_taken(branch_cond_taken),
    .jal_taken(jal_taken),
    .jalr_taken(jalr_taken),

    .control_taken(actual_taken),
    .control_target(actual_target)
);

// ALU instance.
alu alu_inst(
    .a(alu_operand_a),
    .b(alu_operand_b),
    .alu_ctrl(id_ex_alu_ctrl),
    .result(alu_result)
);

///////////////////////////////////////////
// Branch Resolution
//
// EX knows the true outcome, so the pipeline is only redirected when that
// disagrees with what IF predicted. When a prediction was correct, it costs
// nothing instead of the two flushed cycles a naive design would pay.
//
// The three ways to mispredict are:
//   - predicted not taken, actually taken
//   - predicted taken, actually not taken
//   - predicted taken to the wrong address
//
// JALR is never predicted, so it always falls into the first case.

assign mispredict = id_ex_valid &&
                    ((actual_taken != id_ex_predict_taken) ||
                     (actual_taken && (actual_target != id_ex_predict_target)));

assign control_taken = mispredict;
assign control_target = actual_taken ? actual_target : id_ex_pc_plus_4;

// The history table only learns from conditional branches. JAL and JALR are
// unconditional and would just bias the counters.
assign bp_update_en = id_ex_valid && id_ex_is_branch;

// These signals do not drive the datapath. They are retained because the
// instruction trace and waveform debugging depend on them.
logic unused_debug_signals;
assign unused_debug_signals = |{jal_taken, jalr_taken,
                                mem_wb_instr, mem_wb_opcode};

///////////////////////////////////////////
// EX/MEM Pipeline Register
///////////////////////////////////////////

// Carries EX results into MEM.
// Store data uses forward_b, so a store can write a recently computed value.
// On trap_hold the register is frozen: instructions younger than the faulting
// one are still in EX/MEM when the trap commits, and letting them advance to
// MEM/WB would let them write back after the trap. Holding EX/MEM parks them
// so nothing younger than the trap ever reaches WB.
always_ff @(posedge clk) begin
    if (reset) begin
        ex_mem_instr      <= 32'd0;
        ex_mem_pc         <= 32'd0;
        ex_mem_pc_plus_4  <= 32'd0;
        ex_mem_valid      <= 1'b0;

        ex_mem_result     <= 32'd0;
        ex_mem_store_data <= 32'd0;

        ex_mem_rd     <= 5'd0;
        ex_mem_opcode <= 7'd0;

        ex_mem_reg_write <= 1'b0;
        ex_mem_is_link   <= 1'b0;
        ex_mem_is_load   <= 1'b0;
        ex_mem_is_store  <= 1'b0;

        ex_mem_mem_size     <= MEM_SZ_WORD;
        ex_mem_mem_unsigned <= 1'b0;

        ex_mem_exception <= 1'b0;
        ex_mem_cause     <= CAUSE_NONE;
    end
    else if  (trap_hold) begin
        // Freeze in place, hold every field, advance nothing into MEM/WB
        ex_mem_valid      <= 1'b0;
        ex_mem_reg_write <= 1'b0;
        ex_mem_is_load   <= 1'b0;
        ex_mem_is_store  <= 1'b0;

        
    end
    else begin
        ex_mem_instr     <= id_ex_instr;
        ex_mem_pc        <= id_ex_pc;
        ex_mem_pc_plus_4 <= id_ex_pc_plus_4;
        ex_mem_valid     <= id_ex_valid;

        ex_mem_result     <= alu_result;
        ex_mem_store_data <= forward_b;

        ex_mem_rd     <= id_ex_rd;
        ex_mem_opcode <= id_ex_opcode;

        ex_mem_reg_write <= id_ex_reg_write;
        ex_mem_is_link   <= id_ex_is_jal || id_ex_is_jalr;

        // A faulting instruction must not reach memory.
        ex_mem_is_load  <= id_ex_is_load  && id_ex_valid && !id_ex_exception;
        ex_mem_is_store <= id_ex_is_store && id_ex_valid && !id_ex_exception;

        ex_mem_mem_size     <= id_ex_mem_size;
        ex_mem_mem_unsigned <= id_ex_mem_unsigned;

        ex_mem_exception <= id_ex_exception;
        ex_mem_cause     <= id_ex_cause;
    end
end

// For normal instructions, forward the ALU result.
// For JAL/JALR, forward PC+4, since that is the writeback value.
assign ex_mem_forward_data = ex_mem_is_link ? ex_mem_pc_plus_4 : ex_mem_result;

// Forward-enable is narrower than the general write-enable. A load will
// write a register, but its data does not exist until the MEM access
// completes, so EX/MEM must never offer it as a forwarding source. The
// load-use stall already keeps a dependent instruction out of EX for that
// cycle; this exists too so a bug in the stall logic could not silently
// forward an incorrect value.
assign ex_mem_can_forward = ex_mem_reg_write && !ex_mem_is_load;

///////////////////////////////////////////
// MEM Stage
///////////////////////////////////////////

// Determine whether the EX/MEM instruction accesses data memory.
assign mem_re = ex_mem_is_load;
assign mem_we = ex_mem_is_store;

// For loads/stores, ex_mem_result is the effective memory address.
// When neither mem_re nor mem_we is asserted, it is just an ordinary
// ALU result and nothing is written to data_memory.
data_memory dmem(
    .clk(clk),

    .mem_we(mem_we),
    .mem_re(mem_re),

    .addr(ex_mem_result),
    .write_data(ex_mem_store_data),
    .mem_size(ex_mem_mem_size),

    .read_data(mem_read_data),

    .misaligned(mem_misaligned),
    .out_of_range(mem_out_of_range)
);

// Faults detected here are merged with any exception already in flight.
// An earlier exception wins, since it belongs to the same instruction and
// was raised at an earlier stage.
always_comb begin
    mem_exception = ex_mem_exception;
    mem_cause     = ex_mem_cause;

    if (!ex_mem_exception && (mem_re || mem_we)) begin
        if (mem_misaligned) begin
            mem_exception = 1'b1;
            mem_cause     = mem_re ? CAUSE_LOAD_MISALIGN : CAUSE_STORE_MISALIGN;
        end
        else if (mem_out_of_range) begin
            mem_exception = 1'b1;
            mem_cause     = mem_re ? CAUSE_LOAD_FAULT : CAUSE_STORE_FAULT;
        end
    end
end

// Sub-word extraction and extension.
// The memory returns the containing word; the requested field is selected by
// the low address bits and then sign- or zero-extended.
logic [7:0]  load_byte;
logic [15:0] load_half;

always_comb begin
    case (ex_mem_result[1:0])
        2'b00: load_byte = mem_read_data[7:0];
        2'b01: load_byte = mem_read_data[15:8];
        2'b10: load_byte = mem_read_data[23:16];
        default: load_byte = mem_read_data[31:24];
    endcase

    load_half = ex_mem_result[1] ? mem_read_data[31:16] : mem_read_data[15:0];
end

always_comb begin
    case (ex_mem_mem_size)
        MEM_SZ_BYTE: mem_load_extended = ex_mem_mem_unsigned
                        ? {24'd0, load_byte}
                        : {{24{load_byte[7]}}, load_byte};

        MEM_SZ_HALF: mem_load_extended = ex_mem_mem_unsigned
                        ? {16'd0, load_half}
                        : {{16{load_half[15]}}, load_half};

        default: mem_load_extended = mem_read_data;
    endcase
end

///////////////////////////////////////////
// MEM/WB Pipeline Register
///////////////////////////////////////////

// Carries the final writeback value into WB.
// For loads, the WB result comes from memory.
// For everything else, it comes from the EX/MEM ALU result.
// JAL/JALR still resolve to PC+4 via mem_wb_is_link.
// On trap_hold the faulting instruction is held in WB rather than displaced by
// a bubble, so trap_valid/trap_cause/trap_pc stay asserted for as long as the
// core is halted instead of pulsing for a single cycle.
always_ff @(posedge clk) begin
    if (reset) begin
        mem_wb_instr     <= 32'd0;
        mem_wb_pc        <= 32'd0;
        mem_wb_pc_plus_4 <= 32'd0;
        mem_wb_valid     <= 1'b0;

        mem_wb_result    <= 32'd0;
        mem_wb_read_data <= 32'd0;

        mem_wb_rd     <= 5'd0;
        mem_wb_opcode <= 7'd0;

        mem_wb_reg_write <= 1'b0;
        mem_wb_is_link   <= 1'b0;
        mem_wb_is_load   <= 1'b0;

        mem_wb_exception <= 1'b0;
        mem_wb_cause     <= CAUSE_NONE;
    end
    else if (trap_hold) begin
        // Hold the faulting instruction in place. Every field keeps its value,
        // so mem_wb_exception (and thus trap_valid) stays asserted while halted.

        mem_wb_instr     <= mem_wb_instr;
        mem_wb_pc        <= mem_wb_pc;
        mem_wb_pc_plus_4 <= mem_wb_pc_plus_4;
        mem_wb_valid     <= mem_wb_valid;

        mem_wb_result    <= mem_wb_result;
        mem_wb_read_data <= mem_wb_read_data;

        mem_wb_rd     <= mem_wb_rd;
        mem_wb_opcode <= mem_wb_opcode;

        // A memory fault cancels the write.
        mem_wb_reg_write <= mem_wb_reg_write;
        mem_wb_is_link   <= mem_wb_is_link;
        mem_wb_is_load   <= mem_wb_is_load;

        mem_wb_exception <= mem_wb_exception;
        mem_wb_cause     <= mem_wb_cause;
    end
    else begin
        mem_wb_instr     <= ex_mem_instr;
        mem_wb_pc        <= ex_mem_pc;
        mem_wb_pc_plus_4 <= ex_mem_pc_plus_4;
        mem_wb_valid     <= ex_mem_valid;

        mem_wb_result    <= ex_mem_result;
        mem_wb_read_data <= mem_load_extended;

        mem_wb_rd     <= ex_mem_rd;
        mem_wb_opcode <= ex_mem_opcode;

        // A memory fault cancels the write.
        mem_wb_reg_write <= ex_mem_reg_write && !mem_exception;
        mem_wb_is_link   <= ex_mem_is_link;
        mem_wb_is_load   <= ex_mem_is_load;

        mem_wb_exception <= mem_exception;
        mem_wb_cause     <= mem_cause;
    end
end

///////////////////////////////////////////
// WB Stage
///////////////////////////////////////////

// Writeback source is the loaded value for a load, PC+4 for a link, and the
// ALU result otherwise.
always_comb begin
    if (mem_wb_is_load)
        wb_data = mem_wb_read_data;
    else if (mem_wb_is_link)
        wb_data = mem_wb_pc_plus_4;
    else
        wb_data = mem_wb_result;
end

assign wb_rd = mem_wb_rd;

// x0 is excluded here as well, since the register file architecturally
// discards writes to it -- this keeps the write-enable signal meaning one
// thing rather than two.
assign wb_we = mem_wb_reg_write && mem_wb_valid &&
                !mem_wb_exception && (mem_wb_rd != 5'd0);

///////////////////////////////////////////
// Trap Reporting
///////////////////////////////////////////

// Taken at the commit point so the trap is precise: every older instruction
// has already written back, and nothing younger has.
assign trap_valid = mem_wb_valid && mem_wb_exception;
assign trap_cause = mem_wb_cause;
assign trap_pc    = mem_wb_pc;

endmodule
