// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_trap_halt.h for the primary calling header

#include "Vtb_trap_halt__pch.h"
#include "Vtb_trap_halt___024root.h"

VL_ATTR_COLD void Vtb_trap_halt___024root___eval_initial__TOP(Vtb_trap_halt___024root* vlSelf);
VlCoroutine Vtb_trap_halt___024root___eval_initial__TOP__Vtiming__0(Vtb_trap_halt___024root* vlSelf);
VlCoroutine Vtb_trap_halt___024root___eval_initial__TOP__Vtiming__1(Vtb_trap_halt___024root* vlSelf);

void Vtb_trap_halt___024root___eval_initial(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_initial\n"); );
    // Body
    Vtb_trap_halt___024root___eval_initial__TOP(vlSelf);
    Vtb_trap_halt___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_trap_halt___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_trap_halt__DOT__clk__0 
        = vlSelf->tb_trap_halt__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vtb_trap_halt___024root___eval_initial__TOP__Vtiming__1(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "../rtl/../tb/tb_trap_halt.sv", 
                                           46);
        vlSelf->tb_trap_halt__DOT__clk = (1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__clk)));
    }
}

void Vtb_trap_halt___024root___eval_act(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_act\n"); );
}

void Vtb_trap_halt___024root___nba_sequent__TOP__0(Vtb_trap_halt___024root* vlSelf);

void Vtb_trap_halt___024root___eval_nba(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_trap_halt___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtb_trap_halt___024root___timing_resume(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h13638d1d__0.resume("@(posedge tb_trap_halt.clk)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_trap_halt___024root___timing_commit(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h13638d1d__0.commit("@(posedge tb_trap_halt.clk)");
    }
}

void Vtb_trap_halt___024root___eval_triggers__act(Vtb_trap_halt___024root* vlSelf);

bool Vtb_trap_halt___024root___eval_phase__act(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_trap_halt___024root___eval_triggers__act(vlSelf);
    Vtb_trap_halt___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_trap_halt___024root___timing_resume(vlSelf);
        Vtb_trap_halt___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_trap_halt___024root___eval_phase__nba(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_trap_halt___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trap_halt___024root___dump_triggers__nba(Vtb_trap_halt___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trap_halt___024root___dump_triggers__act(Vtb_trap_halt___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_trap_halt___024root___eval(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval\n"); );
    // Init
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset 
        = vlSelf->tb_trap_halt__DOT__reset;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__trap_valid 
        = vlSelf->tb_trap_halt__DOT__trap_valid;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_cause 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__predict_taken 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__predict_taken;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__predict_target 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__predict_target;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_we 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__wb_we;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_valid 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_valid;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_exception 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_exception;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__pc 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_target 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__control_target;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b_sel 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b_sel;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a_sel 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a_sel;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__stall 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__stall;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_rd 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__trapped 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__trapped;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_data 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__wb_data;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_9_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_9_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_10_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_10_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_mem_size 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_mem_size;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_7_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_7_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_8_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_8_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_5_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_5_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_6_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_6_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_0_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_0_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_1_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_1_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_2_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_2_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_valid 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_valid;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs2 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs2;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs1 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs1;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_4_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_4_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_valid 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_valid;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_3_0 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_3_0;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rs2 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs2;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rs1 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs1;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd2 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd2;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd1 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd1;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_is_branch 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_branch;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__actual_taken 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__actual_taken;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_predict_taken 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_predict_taken;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__actual_target 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__actual_target;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_predict_target 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_predict_target;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_load 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_is_load 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_load;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__uses_rs1 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs1;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_instr 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__uses_rs2 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs2;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_rd 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_rd;
    vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_store 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_store;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_trap_halt___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/../tb/tb_trap_halt.sv", 30, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_trap_halt___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/../tb/tb_trap_halt.sv", 30, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_trap_halt___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_trap_halt___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_trap_halt___024root___eval_debug_assertions(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
