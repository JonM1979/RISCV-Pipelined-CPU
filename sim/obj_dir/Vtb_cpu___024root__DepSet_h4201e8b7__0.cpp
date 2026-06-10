// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cpu.h for the primary calling header

#include "Vtb_cpu__pch.h"
#include "Vtb_cpu___024root.h"

VlCoroutine Vtb_cpu___024root___eval_initial__TOP__Vtiming__0(Vtb_cpu___024root* vlSelf);
VlCoroutine Vtb_cpu___024root___eval_initial__TOP__Vtiming__1(Vtb_cpu___024root* vlSelf);

void Vtb_cpu___024root___eval_initial(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_initial\n"); );
    // Body
    Vtb_cpu___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_cpu___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_cpu__DOT__clk__0 
        = vlSelf->tb_cpu__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vtb_cpu___024root___eval_initial__TOP__Vtiming__0(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb_cpu__DOT__clk = 0U;
    vlSelf->tb_cpu__DOT__reset = 1U;
    co_await vlSelf->__VdlySched.delay(0xaULL, nullptr, 
                                       "../tb/tb_cpu.sv", 
                                       24);
    vlSelf->tb_cpu__DOT__reset = 0U;
    co_await vlSelf->__VdlySched.delay(0x64ULL, nullptr, 
                                       "../tb/tb_cpu.sv", 
                                       27);
    VL_FINISH_MT("../tb/tb_cpu.sv", 29, "");
}

VL_INLINE_OPT VlCoroutine Vtb_cpu___024root___eval_initial__TOP__Vtiming__1(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(5ULL, nullptr, 
                                           "../tb/tb_cpu.sv", 
                                           15);
        vlSelf->__Vdlyvval__tb_cpu__DOT__clk__v0 = 
            (1U & (~ (IData)(vlSelf->tb_cpu__DOT__clk)));
        vlSelf->__Vdlyvset__tb_cpu__DOT__clk__v0 = 1U;
    }
}

void Vtb_cpu___024root___eval_act(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_cpu___024root___nba_sequent__TOP__0(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___nba_sequent__TOP__0\n"); );
    // Body
    VL_WRITEF("Cycle: A=%0# B=%0# RESULT=%0#\n",32,
              vlSelf->tb_cpu__DOT__uut__DOT__a,32,vlSelf->tb_cpu__DOT__uut__DOT__b,
              32,(vlSelf->tb_cpu__DOT__uut__DOT__a 
                  + vlSelf->tb_cpu__DOT__uut__DOT__b));
    if (vlSelf->tb_cpu__DOT__reset) {
        vlSelf->tb_cpu__DOT__uut__DOT__b = 0x14U;
        vlSelf->tb_cpu__DOT__uut__DOT__a = 0xaU;
    } else {
        vlSelf->tb_cpu__DOT__uut__DOT__b = ((IData)(1U) 
                                            + vlSelf->tb_cpu__DOT__uut__DOT__b);
        vlSelf->tb_cpu__DOT__uut__DOT__a = ((IData)(1U) 
                                            + vlSelf->tb_cpu__DOT__uut__DOT__a);
    }
}

VL_INLINE_OPT void Vtb_cpu___024root___nba_sequent__TOP__1(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->__Vdlyvset__tb_cpu__DOT__clk__v0) {
        vlSelf->tb_cpu__DOT__clk = vlSelf->__Vdlyvval__tb_cpu__DOT__clk__v0;
        vlSelf->__Vdlyvset__tb_cpu__DOT__clk__v0 = 0U;
    }
}

void Vtb_cpu___024root___eval_nba(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_cpu___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_cpu___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vtb_cpu___024root___timing_resume(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_cpu___024root___eval_triggers__act(Vtb_cpu___024root* vlSelf);

bool Vtb_cpu___024root___eval_phase__act(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_cpu___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_cpu___024root___timing_resume(vlSelf);
        Vtb_cpu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_cpu___024root___eval_phase__nba(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_cpu___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu___024root___dump_triggers__nba(Vtb_cpu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu___024root___dump_triggers__act(Vtb_cpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_cpu___024root___eval(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_cpu___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../tb/tb_cpu.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_cpu___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../tb/tb_cpu.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_cpu___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_cpu___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_cpu___024root___eval_debug_assertions(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
