// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_TRAP_HALT__SYMS_H_
#define VERILATED_VTB_TRAP_HALT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_trap_halt.h"

// INCLUDE MODULE CLASSES
#include "Vtb_trap_halt___024root.h"
#include "Vtb_trap_halt___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_trap_halt__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_trap_halt* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_trap_halt___024root        TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_trap_halt;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_alu_ctrl_legal;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_bp_update_branch_only;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_bubble_no_write;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_exception_blocks_write;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_mux_ex_mem;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_mux_mem_wb;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_mux_regfile;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_priority;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_a_sel_legal;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_mux_ex_mem;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_mux_mem_wb;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_mux_regfile;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_priority;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_fwd_b_sel_legal;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_load_use_always_stalls;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_mem_access_justified;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_mem_not_both;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_mem_size_legal;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_from_load;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_to_x0_a;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_to_x0_b;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_unused_a;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_no_forward_unused_b;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_no_spurious_redirect;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_no_stall_and_redirect;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_pc_advances;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_pc_word_aligned;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_predict_target_aligned;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_prediction_steers_fetch;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_redirect_aligned;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_redirect_flushes_ex;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_redirect_flushes_id;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_resolve_beats_predict;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_stall_injects_bubble;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_stall_is_load_use;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_trap_cause_defined;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_trap_suppresses_write;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_trapped_blocks_all_writes;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_trapped_freezes_pc;
    VerilatedScope __Vscope_tb_trap_halt__uut__u_assert__a_x0_never_written;

    // CONSTRUCTORS
    Vtb_trap_halt__Syms(VerilatedContext* contextp, const char* namep, Vtb_trap_halt* modelp);
    ~Vtb_trap_halt__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
