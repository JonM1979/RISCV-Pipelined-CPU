// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_trap_halt__pch.h"
#include "Vtb_trap_halt.h"
#include "Vtb_trap_halt___024root.h"
#include "Vtb_trap_halt___024unit.h"

// FUNCTIONS
Vtb_trap_halt__Syms::~Vtb_trap_halt__Syms()
{
}

Vtb_trap_halt__Syms::Vtb_trap_halt__Syms(VerilatedContext* contextp, const char* namep, Vtb_trap_halt* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_trap_halt.configure(this, name(), "tb_trap_halt", "tb_trap_halt", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert.configure(this, name(), "tb_trap_halt.uut.u_assert", "u_assert", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_alu_ctrl_legal.configure(this, name(), "tb_trap_halt.uut.u_assert.a_alu_ctrl_legal", "a_alu_ctrl_legal", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_bp_update_branch_only.configure(this, name(), "tb_trap_halt.uut.u_assert.a_bp_update_branch_only", "a_bp_update_branch_only", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_bubble_no_write.configure(this, name(), "tb_trap_halt.uut.u_assert.a_bubble_no_write", "a_bubble_no_write", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_exception_blocks_write.configure(this, name(), "tb_trap_halt.uut.u_assert.a_exception_blocks_write", "a_exception_blocks_write", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_mux_ex_mem.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_a_mux_ex_mem", "a_fwd_a_mux_ex_mem", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_mux_mem_wb.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_a_mux_mem_wb", "a_fwd_a_mux_mem_wb", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_mux_regfile.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_a_mux_regfile", "a_fwd_a_mux_regfile", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_priority.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_a_priority", "a_fwd_a_priority", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_sel_legal.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_a_sel_legal", "a_fwd_a_sel_legal", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_mux_ex_mem.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_b_mux_ex_mem", "a_fwd_b_mux_ex_mem", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_mux_mem_wb.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_b_mux_mem_wb", "a_fwd_b_mux_mem_wb", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_mux_regfile.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_b_mux_regfile", "a_fwd_b_mux_regfile", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_priority.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_b_priority", "a_fwd_b_priority", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_sel_legal.configure(this, name(), "tb_trap_halt.uut.u_assert.a_fwd_b_sel_legal", "a_fwd_b_sel_legal", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_load_use_always_stalls.configure(this, name(), "tb_trap_halt.uut.u_assert.a_load_use_always_stalls", "a_load_use_always_stalls", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_mem_access_justified.configure(this, name(), "tb_trap_halt.uut.u_assert.a_mem_access_justified", "a_mem_access_justified", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_mem_not_both.configure(this, name(), "tb_trap_halt.uut.u_assert.a_mem_not_both", "a_mem_not_both", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_mem_size_legal.configure(this, name(), "tb_trap_halt.uut.u_assert.a_mem_size_legal", "a_mem_size_legal", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_from_load.configure(this, name(), "tb_trap_halt.uut.u_assert.a_no_forward_from_load", "a_no_forward_from_load", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_to_x0_a.configure(this, name(), "tb_trap_halt.uut.u_assert.a_no_forward_to_x0_a", "a_no_forward_to_x0_a", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_to_x0_b.configure(this, name(), "tb_trap_halt.uut.u_assert.a_no_forward_to_x0_b", "a_no_forward_to_x0_b", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_unused_a.configure(this, name(), "tb_trap_halt.uut.u_assert.a_no_forward_unused_a", "a_no_forward_unused_a", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_unused_b.configure(this, name(), "tb_trap_halt.uut.u_assert.a_no_forward_unused_b", "a_no_forward_unused_b", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_no_spurious_redirect.configure(this, name(), "tb_trap_halt.uut.u_assert.a_no_spurious_redirect", "a_no_spurious_redirect", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_no_stall_and_redirect.configure(this, name(), "tb_trap_halt.uut.u_assert.a_no_stall_and_redirect", "a_no_stall_and_redirect", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_pc_advances.configure(this, name(), "tb_trap_halt.uut.u_assert.a_pc_advances", "a_pc_advances", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_pc_word_aligned.configure(this, name(), "tb_trap_halt.uut.u_assert.a_pc_word_aligned", "a_pc_word_aligned", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_predict_target_aligned.configure(this, name(), "tb_trap_halt.uut.u_assert.a_predict_target_aligned", "a_predict_target_aligned", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_prediction_steers_fetch.configure(this, name(), "tb_trap_halt.uut.u_assert.a_prediction_steers_fetch", "a_prediction_steers_fetch", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_redirect_aligned.configure(this, name(), "tb_trap_halt.uut.u_assert.a_redirect_aligned", "a_redirect_aligned", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_redirect_flushes_ex.configure(this, name(), "tb_trap_halt.uut.u_assert.a_redirect_flushes_ex", "a_redirect_flushes_ex", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_redirect_flushes_id.configure(this, name(), "tb_trap_halt.uut.u_assert.a_redirect_flushes_id", "a_redirect_flushes_id", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_resolve_beats_predict.configure(this, name(), "tb_trap_halt.uut.u_assert.a_resolve_beats_predict", "a_resolve_beats_predict", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_stall_injects_bubble.configure(this, name(), "tb_trap_halt.uut.u_assert.a_stall_injects_bubble", "a_stall_injects_bubble", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_stall_is_load_use.configure(this, name(), "tb_trap_halt.uut.u_assert.a_stall_is_load_use", "a_stall_is_load_use", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_trap_cause_defined.configure(this, name(), "tb_trap_halt.uut.u_assert.a_trap_cause_defined", "a_trap_cause_defined", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_trap_suppresses_write.configure(this, name(), "tb_trap_halt.uut.u_assert.a_trap_suppresses_write", "a_trap_suppresses_write", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_trapped_blocks_all_writes.configure(this, name(), "tb_trap_halt.uut.u_assert.a_trapped_blocks_all_writes", "a_trapped_blocks_all_writes", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_trapped_freezes_pc.configure(this, name(), "tb_trap_halt.uut.u_assert.a_trapped_freezes_pc", "a_trapped_freezes_pc", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_trap_halt__uut__u_assert__a_x0_never_written.configure(this, name(), "tb_trap_halt.uut.u_assert.a_x0_never_written", "a_x0_never_written", -9, VerilatedScope::SCOPE_OTHER);
}
