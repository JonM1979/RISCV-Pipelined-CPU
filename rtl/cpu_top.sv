
`include "defines.svh"

module cpu_top(
    input logic clk,
    input logic reset
);

// Pipeline stall signal
logic stall;

// control_taken is asserted when a control instruction takes effect,
// like JAL, branch, or JALR, and redirects the PC 
// control_target is the target address to jump to
logic control_taken;
logic [31:0] control_target;


// ---------------------STAGE SIGNALS BELOW----------------------------

///////////////////////////////////////////
// Instruction Fetch (IF) Signals
///////////////////////////////////////////

// Program counter, holds the address of the insturction
// currently being fetched 
logic [31:0] pc;

// Program counter of the next instruction 
logic [31:0] next_pc;

// Instruction fetched from instruction memory
logic [31:0] instr;

///////////////////////////////////////////
// IF/ID Pipeline Register Signals
///////////////////////////////////////////

// instruction pipelined from IF to ID stage
logic [31:0] if_id_instr;

// PC of the instruction pipelined into ID 
// Needed for branch/JAL target calc later
logic [31:0] if_id_pc;

// PC of the next instruction pipelined into ID
logic [31:0] if_id_next_pc;

///////////////////////////////////////////
// Instruction Decode (ID) Signals 
///////////////////////////////////////////

// Raw decoded instruction fields 
logic [6:0] opcode;
logic [2:0] funct3;
logic [6:0] funct7;

// source registers 1 & 2 (rs1, rs2)
// and register destination (rd)
logic [4:0] rs1;
logic [4:0] rs2;
logic [4:0] rd;

// Decoded sign-extended/immediate value
logic [31:0] imm;

// ALU operation selected by decode
logic [3:0] alu_ctrl;

// Instruction classification flags from decode
// These describe what type of isntruction is currently in ID 
logic is_load;
logic is_store;
logic is_branch;
logic is_rtype;
logic is_itype;
logic is_jal;
logic is_jalr;
logic is_lui;

// Source-register flags that prevent false stalls/forwarding 
// on instructions that do not use rs1/rs2
logic uses_rs1;
logic uses_rs2;

// Register file read data for rs1 and rs2
logic [31:0] rd1;
logic [31:0] rd2;

///////////////////////////////////////////
// ID/EX Pipeline Register Signals 
///////////////////////////////////////////

// Instruction and PC carried into EX
// id_ex_pc is required for branch/JAL PC relative target calculation
logic [31:0] id_ex_instr;
logic [31:0] id_ex_pc;

// PC of the next instruction pipelined into EX
logic [31:0] id_ex_next_pc;

// Register operand values pipelined from ID to EX
logic [31:0] id_ex_rd1;
logic [31:0] id_ex_rd2;

// Immediate value pipelined into EX
logic [31:0] id_ex_imm;

// Register indexes corried into EX, needed for fowarding 
// decisions and writeback destination tracking
logic [4:0] id_ex_rs1;
logic [4:0] id_ex_rs2;
logic [4:0] id_ex_rd;

// Opcode/funct/control values carried into EX
logic [6:0] id_ex_opcode;
logic [2:0] id_ex_funct3;
logic [3:0] id_ex_alu_ctrl;

// Instruction type flags carried into EX
// These signals are needed in EX-stage to control decisions
logic id_ex_is_itype;
logic id_ex_is_load;
logic id_ex_is_store;
logic id_ex_is_branch;
logic id_ex_is_jal;
logic id_ex_is_jalr;
logic id_ex_is_lui;

// Pipelined source usage flags 
// Used by forwarding to avoid checking unused source operands
logic id_ex_uses_rs1;
logic id_ex_uses_rs2;

///////////////////////////////////////////
// Forwarding Signals 
///////////////////////////////////////////

// Final values pipelined into the ALU/Branch logic after forwarding 
logic [31:0] forward_a;
logic [31:0] forward_b;

// Forward select logic:
// 00 = use ID/EX register value
// 01 = forward from MEM/WB
// 10 = forward from EX/MEM
logic [1:0] forward_a_sel;
logic [1:0] forward_b_sel;

// Indicates whether the EX/MEM and MEM/WB instructions
// write a register
logic ex_mem_regwrite;
logic mem_wb_regwrite;

// Actual values available for forwarding 
// For normal ALU/LUI instructions this is the result
// For JAL/JALR, this is PC+4
logic [31:0] ex_mem_forward_data;
logic [31:0] mem_wb_forward_data;

///////////////////////////////////////////
// EX Stage Signals 
///////////////////////////////////////////

// ALU's result
logic [31:0] alu_result;

// Selects whether ALU operand B comes from an immediate or forwarded rs2
// Used for I-type, LW/SWs address calcs, JALR calcs, and LUI 
logic ex_use_imm;

// PC+4 for instruction currently in EX
// Used as the link value for JAL/JALR
logic [31:0] ex_pc_plus_4;

// Control decision signals from branch_control
logic branch_cond_taken;
logic jal_taken;
logic jalr_taken;

///////////////////////////////////////////
// EX/MEM Pipeline Register Signals
///////////////////////////////////////////

// Instruction carried into MEM
logic [31:0] ex_mem_instr;

// ALU result carried into MEM
// For LW/SWs, this is the effective memory address
// For ALU/LUI instructions, this is the value eventually written back
logic [31:0] ex_mem_result;

// Store data carried into MEM
// This must use forwarded rs2 data so stores can write recently produced values
logic [31:0] ex_mem_store_data;

// PC+4 carried into MEM
// Used for JAL/JALR link writeback and forwarding
logic [31:0] ex_mem_pc_plus_4;

// Destination register and opcode carreid into MEM
logic [4:0] ex_mem_rd;
logic [6:0] ex_mem_opcode;

// True when the instruction is JAL or JALR
// These instructions write PC+4 instead of ALU/memory data
logic ex_mem_is_link;

///////////////////////////////////////////
// MEM Stage Signals
///////////////////////////////////////////

// Data memory control signals
// MEM write enable and read enable
logic mem_we;
logic mem_re;

// Flags based on EX/MEM opcode
logic is_mem_load;
logic is_mem_store;

// Data read from data memory during LW.
logic [31:0] mem_read_data;

///////////////////////////////////////////
// MEM/WB Pipeline Register Signals
///////////////////////////////////////////

// Instruction carried into WB
logic [31:0] mem_wb_instr;

// Final non-link result carried into WB
// For loads, this is mem data. 
// For ALU/LUI instructions, this is the ALU result
logic [31:0] mem_wb_result;

// PC+4 carried into WB for JAL/JALR
logic [31:0] mem_wb_pc_plus_4;

// Destination register and opcode carried into WB
logic [4:0] mem_wb_rd;
logic [6:0] mem_wb_opcode;

// True when WB should write PC+4 beacuase instructions was JAL/JALR
logic mem_wb_is_link;

///////////////////////////////////////////
// WB Stage Signals 
///////////////////////////////////////////

// Register file write enable
logic wb_we;

// Destination register and data written into register file
logic [31:0]    wb_data;
logic [4:0]     wb_rd; 
 
// ---------------------STAGE LOGIC UNDER-----------------------------------------------

///////////////////////////////////////////
// Instruction Fetch (IF) Stage
///////////////////////////////////////////

// Sequential Logic (updates on clock edge)
always_ff @( posedge clk ) begin
    if(reset)
        // reset program counter 
        pc <= 32'd0; 
    else if(control_taken)
        // control redirect from branch/JAL/JALR
        pc <= control_target;
    else if (!stall)
        // Only update PC if not stalling
        next_pc <= pc + 32'd4;
end

// Instantiate Instruction Memory
instruction_memory imem_inst(
    .addr(pc),
    .instr(instr)
);

///////////////////////////////////////////
// IF/ID Pipeline Register
///////////////////////////////////////////

// IF/ID holds the fetched instruction and its PC
// On redirects, IF/ID is flushed 
// On stalls, ID/ID holds its current instruction value 
always_ff @( posedge clk ) 
begin
    if(reset) begin
        // reset values if reset is on
        if_id_instr <= 0;
        if_id_pc <= 0;
        if_id_next_pc <= 0;
    end 
    else if (control_taken) begin
        // flush if control signal is on 
        if_id_instr <= 0;
        if_id_pc <= 0;
        if_id_next_pc <= 0;
    end
    else if (!stall) begin
        // Pass instruction to next stage
        if_id_instr <= instr;
        if_id_pc <= pc;
        if_id_next_pc <= next_pc;
    end
end

///////////////////////////////////////////
// Instruction Decode (ID) and Register Read
///////////////////////////////////////////

decode dec(
    .instr(if_id_instr),

    .opcode(opcode),
    .funct3(funct3),
    .funct7(funct7),
    .rd(rd),
    .rs1(rs1),
    .rs2(rs2),

    .imm(imm),

    .is_load(is_load),
    .is_store(is_store),
    .is_branch(is_branch),
    .is_rtype(is_rtype),
    .is_itype(is_itype),
    .is_jal(is_jal),
    .is_jalr(is_jalr),
    .is_lui(is_lui),
    .uses_rs1(uses_rs1),
    .uses_rs2(uses_rs2),


    .alu_ctrl(alu_ctrl)
);

// Register File instance
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

///////////////////////////////////////////
// Hazard Unit - Load-Use Stall Detection
///////////////////////////////////////////

// Detects load-use hazards between instruction in EX
// and instruction in ID. If ID uses the destination 
// of a load currently in EX, stall one cycle.
hazard_unit hazard_unit_test(
    .id_ex_opcode(id_ex_opcode),
    .id_ex_rd(id_ex_rd),

    .id_rs1(rs1),
    .id_rs2(rs2),

    .id_uses_rs1(uses_rs1),
    .id_uses_rs2(uses_rs2),

    .stall(stall)
);

///////////////////////////////////////////
// ID/EX Pipeline Logic 
///////////////////////////////////////////

// ID/EX is cleared on reset, control redirect, or stall. 
// Clearing on stall inserts a bubble into EX while IF/IF are 
// Clearing on control_taken removes wrong-path/decode-stage instruciton
always_ff @(posedge clk) begin
    if(reset || control_taken || stall) begin
        // insert bubble into EX stage
        id_ex_instr     <= 32'd0;
        id_ex_pc        <= 32'd0;
        id_ex_next_pc   <= 32'd0;
        id_ex_rd1       <= 32'd0;
        id_ex_rd2       <= 32'd0;
        id_ex_imm       <= 32'd0;

        id_ex_rs1       <= 5'd0;
        id_ex_rs2       <= 5'd0;
        id_ex_rd        <= 5'd0;

        id_ex_opcode    <= 7'd0;
        id_ex_funct3    <= 3'd0;
        id_ex_alu_ctrl  <= ALU_ADD;

        id_ex_is_itype  <= 1'b0;
        id_ex_is_load   <= 1'b0;
        id_ex_is_store  <= 1'b0;
        id_ex_is_branch <= 1'b0;
        id_ex_is_jal    <= 1'b0;
        id_ex_is_jalr   <= 1'b0;
        id_ex_is_lui    <= 1'b0;

        id_ex_uses_rs1  <= 1'b0;
        id_ex_uses_rs2  <= 1'b0;
    end
    else begin
        // Register-read bypass from WB to ID
        // This handles the case where the register file has not 
        // been calculated from the WB stage eact time ID reads it 
        id_ex_rd1 <= (wb_we &&(wb_rd != 5'd0) && (wb_rd == rs1)) ? wb_data : rd1;
        id_ex_rd2 <= (wb_we && (wb_rd != 5'd0) && (wb_rd == rs2)) ? wb_data: rd2;

        // Pipelined decoced instruction into EX
        id_ex_instr    <= if_id_instr;
        id_ex_pc       <= if_id_pc;
        id_ex_next_pc  <= if_id_next_pc;
        id_ex_imm      <= imm;
        id_ex_rs1      <= rs1;
        id_ex_rs2      <= rs2;
        id_ex_rd       <= rd;

        id_ex_opcode   <= opcode;
        id_ex_funct3   <= funct3;
        id_ex_alu_ctrl <= alu_ctrl;

        id_ex_is_itype  <= is_itype;
        id_ex_is_load   <= is_load;
        id_ex_is_store  <= is_store;
        id_ex_is_branch <= is_branch;
        id_ex_is_jal    <= is_jal;
        id_ex_is_jalr   <= is_jalr;
        id_ex_is_lui    <= is_lui;

        id_ex_uses_rs1  <= uses_rs1;
        id_ex_uses_rs2  <= uses_rs2;

    end
end

///////////////////////////////////////////
// Forwarding Unit/Logic 
///////////////////////////////////////////

// EX/MEM can forward ALU, I-type, LUI, JAL, and JALR results
// LW is excluded because load data is not avaialable until memory access completes. 
assign ex_mem_regwrite = 
    (ex_mem_opcode == OPCODE_R_TYPE) ||
    (ex_mem_opcode == OPCODE_I_TYPE) ||
    (ex_mem_opcode == OPCODE_JAL)    ||
    (ex_mem_opcode == OPCODE_JALR)   ||
    (ex_mem_opcode == OPCODE_LUI);

assign mem_wb_regwrite =
    (mem_wb_opcode == OPCODE_R_TYPE) ||
    (mem_wb_opcode == OPCODE_I_TYPE) ||
    (mem_wb_opcode == OPCODE_LOAD)   ||
    (mem_wb_opcode == OPCODE_JAL)    ||
    (mem_wb_opcode == OPCODE_JALR)   ||
    (mem_wb_opcode == OPCODE_LUI);


// Produces forwarding select values for EX-stage operands
// The actual muxing remians in this file so datapath flow is visible
forwarding_unit fwd_unit(

    .id_ex_rs1(id_ex_rs1),
    .id_ex_rs2(id_ex_rs2),

    .id_ex_uses_rs1(id_ex_uses_rs1),
    .id_ex_uses_rs2(id_ex_uses_rs2),

    .ex_mem_rd(ex_mem_rd),
    .ex_mem_reg_write(ex_mem_regwrite),

    .mem_wb_rd(mem_wb_rd),
    .mem_wb_reg_write(mem_wb_regwrite),

    .forward_a_sel(forward_a_sel),
    .forward_b_sel(forward_b_sel)

);

///////////////////////////////////////////
// Forwarding Muxes
///////////////////////////////////////////

// Select final ALU/branch operands;
// priority is already encoded
// 00 = ID/EX register value
// 01 = MEM/WB forwarding
// 10 = EX/MEM forwarding

always_comb begin
    forward_a = id_ex_rd1;
    forward_b = id_ex_rd2;

    case(forward_a_sel)
        2'b10: begin
            forward_a = ex_mem_forward_data;
        end

    2'b01: begin
            forward_a = wb_data;
        end

    default: begin 
            forward_a = id_ex_rd1;
        end
    endcase
    
    case(forward_b_sel)
        2'b10: begin
            forward_b = ex_mem_forward_data;
        end 
        
        2'b01: begin
            forward_b = wb_data;
        end

        default: begin
            forward_b = id_ex_rd2;
        end 
    endcase
end

///////////////////////////////////////////
// EX Stage - ALU Control Flow
///////////////////////////////////////////

// Determines whether operand B should be immediate or register/forwarded data
// JAL does not need the ALU imm path because target is calculated
// inside branch_control using PC+imm
assign ex_use_imm = 
    id_ex_is_itype ||
    id_ex_is_load  ||
    id_ex_is_store ||
    id_ex_is_jalr  ||
    id_ex_is_lui;

// Link value for JAL/JALR
assign ex_pc_plus_4 = id_ex_next_pc;

// Branch/JAL/JALR control unit 
// Produces redirect decision, redirect target, 
// and debug-visible status signals
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

    .control_taken(control_taken),
    .control_target(control_target)
);

// Instantiating ALU
alu alu_inst(
    .a(forward_a),
    .b(ex_use_imm ? id_ex_imm : forward_b),
    .alu_ctrl(id_ex_alu_ctrl),
    .result(alu_result)
);

///////////////////////////////////////////
// EX/MEM Pipeline Register
///////////////////////////////////////////

// For normal instructions, forward normal data
// For JAL/JALR, forward PC+4 because that is the writeback value
assign ex_mem_forward_data = 
    ex_mem_is_link ? ex_mem_pc_plus_4 : ex_mem_result;

// Carries EX results into MEM
// SW data uses forward_b so SWs can write
// a recently computed value
always_ff @(posedge clk) begin
    if(reset) begin
        ex_mem_instr      <= 32'd0;
        ex_mem_result     <= 32'd0;
        ex_mem_store_data <= 32'd0;
        ex_mem_pc_plus_4  <= 32'd0;

        ex_mem_rd         <= 5'd0;
        ex_mem_opcode     <= 7'd0;

        ex_mem_is_link    <= 1'b0;
    end
    else begin
        ex_mem_instr      <= id_ex_instr;
        ex_mem_result     <= alu_result;
        ex_mem_store_data <= forward_b;
        ex_mem_pc_plus_4  <= ex_pc_plus_4;

        ex_mem_rd         <= id_ex_rd;
        ex_mem_opcode     <= id_ex_opcode;

        // Link means JAL or JALR writes PC + 4.
        ex_mem_is_link    <= jal_taken || jalr_taken;
    end
end

///////////////////////////////////////////
// MEM Stage
///////////////////////////////////////////

// Determine whether EX/MEM instruction accesses data memory
assign is_mem_load = (ex_mem_opcode == OPCODE_LOAD);
assign is_mem_store = (ex_mem_opcode == OPCODE_STORE);

assign mem_re = is_mem_load;
assign mem_we = is_mem_store;


data_memory dmem(
    .clk(clk),

    .mem_we(mem_we),
    .mem_re(mem_re),

    .addr(ex_mem_result),
    .write_data(ex_mem_store_data),
    .read_data(mem_read_data)
);

///////////////////////////////////////////
// MEM/WB Pipeline Register
///////////////////////////////////////////

// Carries final writeback value into WB
// For LWs, WB result comes from memory
// For non-LWs, WB result comes from EX/MEM ALU result
// JAL/JALR still use PC+4 through mem_wb_is_link
always_ff @(posedge clk) begin
    if(reset) begin
        mem_wb_instr    <= 32'd0;
        mem_wb_result   <= 32'd0;
        mem_wb_pc_plus_4 <= 32'd0;

        mem_wb_rd        <= 5'd0;
        mem_wb_opcode    <= 7'd0;

        mem_wb_is_link   <= 1'b0;
    end
    else begin
        mem_wb_instr <= ex_mem_instr;

        if (is_mem_load) begin
            mem_wb_result <= mem_read_data;
        end
        else begin
            mem_wb_result <= ex_mem_result;
        end

        mem_wb_pc_plus_4 <= ex_mem_pc_plus_4;

        mem_wb_rd        <= ex_mem_rd;
        mem_wb_opcode    <= ex_mem_opcode;

        mem_wb_is_link   <= ex_mem_is_link;
    end
end

///////////////////////////////////////////
// WB Stage
///////////////////////////////////////////

// MEM/WB regwrite logic is already the same condition 
// needed for WB enable
assign wb_we = mem_wb_regwrite;

// Destination register for the register file
assign wb_rd = mem_wb_rd;

// Final writeback data. 
assign wb_data = 
    mem_wb_is_link ? mem_wb_pc_plus_4 : mem_wb_result;

endmodule
