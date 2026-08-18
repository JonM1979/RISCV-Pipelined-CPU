// Property checks for the pipeline.
//
// Bound into cpu_top rather than instantiated, so the design carries no
// assertion logic into synthesis while simulation checks every invariant on
// every cycle. Enabled with Verilator's --assert flag.
//
// Four groups:
//   1. Architectural guarantees (x0, alignment, trap precision)
//   2. Control invariants (stall vs redirect, flush behaviour)
//   3. Forwarding correctness (selects, priority, mux agreement)
//   4. Encoding sanity (no undefined control value reaches the datapath)

`include "defines.svh"

module cpu_assertions (
    input logic clk,
    input logic reset,

    input logic [31:0] pc,
    input logic        stall,
    input logic        control_taken,
    input logic [31:0] control_target,

    input logic        predict_taken,
    input logic [31:0] predict_target,
    input logic        actual_taken,
    input logic [31:0] actual_target,
    input logic        bp_update_en,
    input logic        id_ex_is_branch,
    input logic        id_ex_predict_taken,
    input logic [31:0] id_ex_predict_target,

    input logic        if_id_valid,

    input logic [4:0]  rs1,
    input logic [4:0]  rs2,
    input logic        uses_rs1,
    input logic        uses_rs2,

    input logic        id_ex_valid,
    input logic        id_ex_is_load,
    input logic        id_ex_uses_rs1,
    input logic        id_ex_uses_rs2,
    input logic [4:0]  id_ex_rd,
    input logic [4:0]  id_ex_rs1,
    input logic [4:0]  id_ex_rs2,
    input logic [3:0]  id_ex_alu_ctrl,
    input logic [1:0]  id_ex_mem_size,

    input logic [1:0]  forward_a_sel,
    input logic [1:0]  forward_b_sel,
    input logic [31:0] forward_a,
    input logic [31:0] forward_b,
    input logic [31:0] id_ex_rd1,
    input logic [31:0] id_ex_rd2,
    input logic [31:0] ex_mem_forward_data,

    input logic [4:0]  ex_mem_rd,
    input logic        ex_mem_can_forward,
    input logic        ex_mem_is_load,
    input logic        ex_mem_is_store,

    input logic        mem_re,
    input logic        mem_we,

    input logic        mem_wb_valid,
    input logic        mem_wb_exception,

    input logic        wb_we,
    input logic [4:0]  wb_rd,
    input logic [31:0] wb_data,

    input logic        trap_valid,
    input logic [3:0]  trap_cause,

    input logic        trapped
);

///////////////////////////////////////////////////////////////////////////
// 1. Architectural guarantees
///////////////////////////////////////////////////////////////////////////

// x0 is hardwired to zero, so the register file must never be told to write it.
a_x0_never_written: assert property (@(posedge clk) disable iff (reset)
    wb_we |-> (wb_rd != 5'd0))
else $error("Register file write targeted x0");

// Instruction fetch is always word aligned.
a_pc_word_aligned: assert property (@(posedge clk) disable iff (reset)
    pc[1:0] == 2'b00)
else $error("PC 0x%08h is not word aligned", pc);

// Every redirect lands on a word boundary. JALR clears bit 0 in hardware, so
// a misaligned target here would indicate a target-computation bug.
a_redirect_aligned: assert property (@(posedge clk) disable iff (reset)
    control_taken |-> (control_target[1:0] == 2'b00))
else $error("Redirect target 0x%08h is not word aligned", control_target);

// The property that makes the trap precise: a trapping instruction commits
// nothing.
a_trap_suppresses_write: assert property (@(posedge clk) disable iff (reset)
    trap_valid |-> !wb_we)
else $error("Register write committed on the same cycle as a trap");

// A reported trap always carries a cause the core actually defines.
a_trap_cause_defined: assert property (@(posedge clk) disable iff (reset)
    trap_valid |-> ((trap_cause == CAUSE_ILLEGAL_INSTR)  ||
                    (trap_cause == CAUSE_BREAKPOINT)     ||
                    (trap_cause == CAUSE_ECALL)          ||
                    (trap_cause == CAUSE_LOAD_MISALIGN)  ||
                    (trap_cause == CAUSE_STORE_MISALIGN) ||
                    (trap_cause == CAUSE_LOAD_FAULT)     ||
                    (trap_cause == CAUSE_STORE_FAULT)))
else $error("Trap raised with undefined cause %0d", trap_cause);
 
// A faulting instruction is never allowed to write back.
a_exception_blocks_write: assert property (@(posedge clk) disable iff (reset)
    (mem_wb_valid && mem_wb_exception) |-> !wb_we)
else $error("Faulting instruction wrote back");
 
// The halt is sticky, not a one-cycle pulse. Once the core has trapped, no
// instruction younger than the faulting one may ever commit a register write
// -- this is the invariant that a naive one-cycle trap freeze violates,
// because the pipeline drains and resumes the cycle after trap_valid drops.
a_trapped_blocks_all_writes: assert property (@(posedge clk) disable iff (reset)
    trapped |-> !wb_we)
else $error("Register write committed after the core had already trapped");
 
// Once trapped, the PC is parked at the faulting instruction and never moves
// again (until reset). Guards against the freeze wearing off after a cycle.
a_trapped_freezes_pc: assert property (@(posedge clk) disable iff (reset)
    trapped |=> ($stable(pc)))
else $error("PC advanced after the core had already trapped");
 
// A bubble never claims to write a register.
a_bubble_no_write: assert property (@(posedge clk) disable iff (reset)
    !mem_wb_valid |-> !wb_we)
else $error("An invalid pipeline slot attempted a register write");

///////////////////////////////////////////////////////////////////////////
// 2. Control invariants
///////////////////////////////////////////////////////////////////////////

// A stall comes from a load in EX; a redirect comes from a branch or jump in
// EX. One instruction cannot be both, so these must never coincide -- if they
// did, the PC update priority would be ambiguous.
a_no_stall_and_redirect: assert property (@(posedge clk) disable iff (reset)
    !(stall && control_taken))
else $error("Stall and redirect asserted in the same cycle");

// A redirect empties decode on the following cycle.
a_redirect_flushes_id: assert property (@(posedge clk) disable iff (reset)
    control_taken |=> !if_id_valid)
else $error("IF/ID not flushed after a redirect");

// A redirect empties execute on the following cycle.
a_redirect_flushes_ex: assert property (@(posedge clk) disable iff (reset)
    control_taken |=> !id_ex_valid)
else $error("ID/EX not flushed after a redirect");

// A stall injects a bubble rather than duplicating an instruction.
a_stall_injects_bubble: assert property (@(posedge clk) disable iff (reset)
    stall |=> !id_ex_valid)
else $error("Stall did not inject a bubble into EX");

// With no stall, no redirect, no trap and no taken prediction, fetch must
// simply advance sequentially.
a_pc_advances: assert property (@(posedge clk) disable iff (reset)
    (!stall && !control_taken && !trap_valid && !predict_taken)
    |=> (pc == $past(pc) + 32'd4))
else $error("PC failed to advance when it should have");

// A taken prediction must actually steer fetch to the predicted target.
a_prediction_steers_fetch: assert property (@(posedge clk) disable iff (reset)
    (predict_taken && !control_taken && !trap_valid && !stall)
    |=> (pc == $past(predict_target)))
else $error("Predicted-taken branch did not steer fetch to the predicted target");

// A resolved misprediction always overrides a speculative prediction.
a_resolve_beats_predict: assert property (@(posedge clk) disable iff (reset)
    (control_taken && !trap_valid) |=> (pc == $past(control_target)))
else $error("Resolved redirect did not take priority over the prediction");

// Predicted targets are word aligned, like every other fetch address.
a_predict_target_aligned: assert property (@(posedge clk) disable iff (reset)
    predict_taken |-> (predict_target[1:0] == 2'b00))
else $error("Predicted target 0x%08h is not word aligned", predict_target);

// The core must never redirect when the prediction was already correct --
// that would be a wasted flush.
a_no_spurious_redirect: assert property (@(posedge clk) disable iff (reset)
    (id_ex_valid && (actual_taken == id_ex_predict_taken) &&
     (!actual_taken || (actual_target == id_ex_predict_target)))
    |-> !control_taken)
else $error("Pipeline flushed despite a correct prediction");

// Only conditional branches train the history table.
a_bp_update_branch_only: assert property (@(posedge clk) disable iff (reset)
    bp_update_en |-> id_ex_is_branch)
else $error("History table updated by a non-branch instruction");

// A stall is always justified by a real load-use dependency.
a_stall_is_load_use: assert property (@(posedge clk) disable iff (reset)
    stall |-> (id_ex_is_load && (id_ex_rd != 5'd0) &&
               ((uses_rs1 && (id_ex_rd == rs1)) ||
                (uses_rs2 && (id_ex_rd == rs2)))))
else $error("Stall asserted without a load-use hazard");

// The converse: an unhandled load-use dependency never slips through.
a_load_use_always_stalls: assert property (@(posedge clk) disable iff (reset)
    (id_ex_is_load && id_ex_valid && (id_ex_rd != 5'd0) && if_id_valid &&
     ((uses_rs1 && (id_ex_rd == rs1)) || (uses_rs2 && (id_ex_rd == rs2))))
    |-> stall)
else $error("Load-use hazard did not produce a stall");

///////////////////////////////////////////////////////////////////////////
// 3. Forwarding correctness
///////////////////////////////////////////////////////////////////////////

// 2'b11 is not a defined select value.
a_fwd_a_sel_legal: assert property (@(posedge clk) disable iff (reset)
    forward_a_sel != 2'b11)
else $error("forward_a_sel reached illegal value 2'b11");

a_fwd_b_sel_legal: assert property (@(posedge clk) disable iff (reset)
    forward_b_sel != 2'b11)
else $error("forward_b_sel reached illegal value 2'b11");

// Forwarding never engages for an operand the instruction does not read.
a_no_forward_unused_a: assert property (@(posedge clk) disable iff (reset)
    (forward_a_sel != 2'b00) |-> id_ex_uses_rs1)
else $error("Forwarded into operand A of an instruction that does not read rs1");

a_no_forward_unused_b: assert property (@(posedge clk) disable iff (reset)
    (forward_b_sel != 2'b00) |-> id_ex_uses_rs2)
else $error("Forwarded into operand B of an instruction that does not read rs2");

// Forwarding is never requested into x0.
a_no_forward_to_x0_a: assert property (@(posedge clk) disable iff (reset)
    (forward_a_sel != 2'b00) |-> (id_ex_rs1 != 5'd0))
else $error("Forwarded into x0 on operand A");

a_no_forward_to_x0_b: assert property (@(posedge clk) disable iff (reset)
    (forward_b_sel != 2'b00) |-> (id_ex_rs2 != 5'd0))
else $error("Forwarded into x0 on operand B");

// EX/MEM takes priority over MEM/WB: when the nearer stage is a valid
// producer for this source, the select must choose it. Getting this backwards
// silently returns a stale value.
a_fwd_a_priority: assert property (@(posedge clk) disable iff (reset)
    (id_ex_uses_rs1 && ex_mem_can_forward &&
     (ex_mem_rd != 5'd0) && (ex_mem_rd == id_ex_rs1))
    |-> (forward_a_sel == 2'b10))
else $error("Operand A did not take EX/MEM priority");

a_fwd_b_priority: assert property (@(posedge clk) disable iff (reset)
    (id_ex_uses_rs2 && ex_mem_can_forward &&
     (ex_mem_rd != 5'd0) && (ex_mem_rd == id_ex_rs2))
    |-> (forward_b_sel == 2'b10))
else $error("Operand B did not take EX/MEM priority");

// The mux output must agree with its select. This catches a select/mux
// mismatch, the failure mode that silently produces wrong arithmetic.
a_fwd_a_mux_ex_mem: assert property (@(posedge clk) disable iff (reset)
    (forward_a_sel == 2'b10) |-> (forward_a == ex_mem_forward_data))
else $error("Operand A select says EX/MEM but the mux disagrees");

a_fwd_a_mux_mem_wb: assert property (@(posedge clk) disable iff (reset)
    (forward_a_sel == 2'b01) |-> (forward_a == wb_data))
else $error("Operand A select says MEM/WB but the mux disagrees");

a_fwd_a_mux_regfile: assert property (@(posedge clk) disable iff (reset)
    (forward_a_sel == 2'b00) |-> (forward_a == id_ex_rd1))
else $error("Operand A select says register file but the mux disagrees");

a_fwd_b_mux_ex_mem: assert property (@(posedge clk) disable iff (reset)
    (forward_b_sel == 2'b10) |-> (forward_b == ex_mem_forward_data))
else $error("Operand B select says EX/MEM but the mux disagrees");

a_fwd_b_mux_mem_wb: assert property (@(posedge clk) disable iff (reset)
    (forward_b_sel == 2'b01) |-> (forward_b == wb_data))
else $error("Operand B select says MEM/WB but the mux disagrees");

a_fwd_b_mux_regfile: assert property (@(posedge clk) disable iff (reset)
    (forward_b_sel == 2'b00) |-> (forward_b == id_ex_rd2))
else $error("Operand B select says register file but the mux disagrees");

// A load's result is not ready in EX/MEM, so it must never be forwarded from
// there. This is exactly the invariant the load-use stall exists to preserve.
a_no_forward_from_load: assert property (@(posedge clk) disable iff (reset)
    ex_mem_is_load |-> !ex_mem_can_forward)
else $error("Attempted to forward a load result out of EX/MEM");

///////////////////////////////////////////////////////////////////////////
// 4. Encoding and datapath sanity
///////////////////////////////////////////////////////////////////////////

// Memory is never read and written in the same cycle.
a_mem_not_both: assert property (@(posedge clk) disable iff (reset)
    !(mem_re && mem_we))
else $error("Data memory read and write asserted together");

// Memory is only accessed by an actual load or store.
a_mem_access_justified: assert property (@(posedge clk) disable iff (reset)
    (mem_re || mem_we) |-> (ex_mem_is_load || ex_mem_is_store))
else $error("Memory accessed by a non memory instruction");

// The access width is always defined.
a_mem_size_legal: assert property (@(posedge clk) disable iff (reset)
    (id_ex_mem_size == MEM_SZ_BYTE) ||
    (id_ex_mem_size == MEM_SZ_HALF) ||
    (id_ex_mem_size == MEM_SZ_WORD))
else $error("Undefined memory access size %0d", id_ex_mem_size);

// The ALU control is always a code the ALU implements. Reaching the datapath
// with an unrecognised code means the decoder produced garbage.
a_alu_ctrl_legal: assert property (@(posedge clk) disable iff (reset)
    (id_ex_alu_ctrl == ALU_ADD)  || (id_ex_alu_ctrl == ALU_SUB)  ||
    (id_ex_alu_ctrl == ALU_SLL)  || (id_ex_alu_ctrl == ALU_SLT)  ||
    (id_ex_alu_ctrl == ALU_SLTU) || (id_ex_alu_ctrl == ALU_XOR)  ||
    (id_ex_alu_ctrl == ALU_SRL)  || (id_ex_alu_ctrl == ALU_SRA)  ||
    (id_ex_alu_ctrl == ALU_OR)   || (id_ex_alu_ctrl == ALU_AND)  ||
    (id_ex_alu_ctrl == ALU_COPY_B) || (id_ex_alu_ctrl == ALU_NOP))
else $error("Undefined ALU control code %0d", id_ex_alu_ctrl);

///////////////////////////////////////////////////////////////////////////
// Coverage
//
// A property that never fires proves nothing, so the interesting scenarios
// are covered explicitly to confirm the tests actually reach them.
///////////////////////////////////////////////////////////////////////////

c_stall_occurs:      cover property (@(posedge clk) disable iff (reset) stall);
c_redirect_occurs:   cover property (@(posedge clk) disable iff (reset) control_taken);
c_fwd_from_ex_mem:   cover property (@(posedge clk) disable iff (reset) forward_a_sel == 2'b10);
c_fwd_from_mem_wb:   cover property (@(posedge clk) disable iff (reset) forward_a_sel == 2'b01);
c_both_operands_fwd: cover property (@(posedge clk) disable iff (reset)
                                     (forward_a_sel != 2'b00) && (forward_b_sel != 2'b00));
c_byte_access:       cover property (@(posedge clk) disable iff (reset)
                                     (mem_re || mem_we) && (id_ex_mem_size == MEM_SZ_BYTE));
c_half_access:       cover property (@(posedge clk) disable iff (reset)
                                     (mem_re || mem_we) && (id_ex_mem_size == MEM_SZ_HALF));
c_trap_taken:        cover property (@(posedge clk) disable iff (reset) trap_valid);

c_predict_taken:     cover property (@(posedge clk) disable iff (reset) predict_taken);
c_predict_correct:   cover property (@(posedge clk) disable iff (reset)
                                     id_ex_valid && id_ex_is_branch && !control_taken);
c_predict_wrong:     cover property (@(posedge clk) disable iff (reset)
                                     id_ex_valid && id_ex_is_branch && control_taken);

endmodule


// Bind the checker into the core. cpu_top needs no edit.
bind cpu_top cpu_assertions u_assert (
    .clk(clk),
    .reset(reset),

    .pc(pc),
    .stall(stall),
    .control_taken(control_taken),
    .control_target(control_target),

    .predict_taken(predict_taken),
    .predict_target(predict_target),
    .actual_taken(actual_taken),
    .actual_target(actual_target),
    .bp_update_en(bp_update_en),
    .id_ex_is_branch(id_ex_is_branch),
    .id_ex_predict_taken(id_ex_predict_taken),
    .id_ex_predict_target(id_ex_predict_target),

    .if_id_valid(if_id_valid),

    .rs1(rs1),
    .rs2(rs2),
    .uses_rs1(uses_rs1),
    .uses_rs2(uses_rs2),

    .id_ex_valid(id_ex_valid),
    .id_ex_is_load(id_ex_is_load),
    .id_ex_uses_rs1(id_ex_uses_rs1),
    .id_ex_uses_rs2(id_ex_uses_rs2),
    .id_ex_rd(id_ex_rd),
    .id_ex_rs1(id_ex_rs1),
    .id_ex_rs2(id_ex_rs2),
    .id_ex_alu_ctrl(id_ex_alu_ctrl),
    .id_ex_mem_size(id_ex_mem_size),

    .forward_a_sel(forward_a_sel),
    .forward_b_sel(forward_b_sel),
    .forward_a(forward_a),
    .forward_b(forward_b),
    .id_ex_rd1(id_ex_rd1),
    .id_ex_rd2(id_ex_rd2),
    .ex_mem_forward_data(ex_mem_forward_data),

    .ex_mem_rd(ex_mem_rd),
    .ex_mem_can_forward(ex_mem_can_forward),
    .ex_mem_is_load(ex_mem_is_load),
    .ex_mem_is_store(ex_mem_is_store),

    .mem_re(mem_re),
    .mem_we(mem_we),

    .mem_wb_valid(mem_wb_valid),
    .mem_wb_exception(mem_wb_exception),

    .wb_we(wb_we),
    .wb_rd(wb_rd),
    .wb_data(wb_data),

    .trap_valid(trap_valid),
    .trap_cause(trap_cause),

    .trapped(trapped)
);
