// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_trap_halt.h for the primary calling header

#include "Vtb_trap_halt__pch.h"
#include "Vtb_trap_halt__Syms.h"
#include "Vtb_trap_halt___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_trap_halt___024root___eval_initial__TOP__Vtiming__0(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    CData/*0:0*/ tb_trap_halt__DOT__seen_trap;
    tb_trap_halt__DOT__seen_trap = 0;
    IData/*31:0*/ tb_trap_halt__DOT__errors;
    tb_trap_halt__DOT__errors = 0;
    IData/*31:0*/ tb_trap_halt__DOT__cycles_after_trap;
    tb_trap_halt__DOT__cycles_after_trap = 0;
    // Body
    tb_trap_halt__DOT__seen_trap = 0U;
    tb_trap_halt__DOT__errors = 0U;
    tb_trap_halt__DOT__cycles_after_trap = 0U;
    vlSelf->tb_trap_halt__DOT__reset = 1U;
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       61);
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       61);
    vlSelf->tb_trap_halt__DOT__reset = 0U;
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    co_await vlSelf->__VtrigSched_h13638d1d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_trap_halt.clk)", 
                                                       "../rtl/../tb/tb_trap_halt.sv", 
                                                       66);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "../rtl/../tb/tb_trap_halt.sv", 
                                       67);
    if (((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
         & (~ (IData)(tb_trap_halt__DOT__seen_trap)))) {
        tb_trap_halt__DOT__seen_trap = 1U;
        vlSelf->tb_trap_halt__DOT__pc_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__cause_at_trap = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        if (VL_UNLIKELY((0xbU != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause)))) {
            VL_WRITEF("FAIL: expected ECALL cause 11, got %0#\n",
                      4,vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    } else if (tb_trap_halt__DOT__seen_trap) {
        tb_trap_halt__DOT__cycles_after_trap = ((IData)(1U) 
                                                + tb_trap_halt__DOT__cycles_after_trap);
        if (VL_UNLIKELY((vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                         != vlSelf->tb_trap_halt__DOT__pc_at_trap))) {
            VL_WRITEF("FAIL: PC moved after trap (0x%08x -> 0x%08x)\n",
                      32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                      32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__trap_valid))))) {
            VL_WRITEF("FAIL: trap_valid dropped %0d cycles after trap\n",
                      32,tb_trap_halt__DOT__cycles_after_trap);
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause) 
                         != (IData)(vlSelf->tb_trap_halt__DOT__cause_at_trap)))) {
            VL_WRITEF("FAIL: trap_cause changed after trap (%0# -> %0#)\n",
                      4,vlSelf->tb_trap_halt__DOT__cause_at_trap,
                      4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
            tb_trap_halt__DOT__errors = ((IData)(1U) 
                                         + tb_trap_halt__DOT__errors);
        }
    }
    if (VL_UNLIKELY((0U != vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                     [0xaU]))) {
        VL_WRITEF("FAIL: x10 = %0# (younger instruction committed after trap)\n",
                  32,vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                  [0xaU]);
        tb_trap_halt__DOT__errors = ((IData)(1U) + tb_trap_halt__DOT__errors);
    }
    if (VL_UNLIKELY((0U != vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                     [0xbU]))) {
        VL_WRITEF("FAIL: x11 = %0# (younger instruction committed after trap)\n",
                  32,vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                  [0xbU]);
        tb_trap_halt__DOT__errors = ((IData)(1U) + tb_trap_halt__DOT__errors);
    }
    if (VL_UNLIKELY((0U != vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                     [0xcU]))) {
        VL_WRITEF("FAIL: x12 = %0# (younger instruction committed after trap)\n",
                  32,vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                  [0xcU]);
        tb_trap_halt__DOT__errors = ((IData)(1U) + tb_trap_halt__DOT__errors);
    }
    if (VL_UNLIKELY((0U != vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                     [0xdU]))) {
        VL_WRITEF("FAIL: x13 = %0# (younger instruction committed after trap)\n",
                  32,vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                  [0xdU]);
        tb_trap_halt__DOT__errors = ((IData)(1U) + tb_trap_halt__DOT__errors);
    }
    if (VL_UNLIKELY((5U != vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                     [1U]))) {
        VL_WRITEF("FAIL: x1 = %0#, expected 5 (older instruction should commit)\n",
                  32,vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                  [1U]);
        tb_trap_halt__DOT__errors = ((IData)(1U) + tb_trap_halt__DOT__errors);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(tb_trap_halt__DOT__seen_trap))))) {
        VL_WRITEF("FAIL: trap was never raised\n");
        tb_trap_halt__DOT__errors = ((IData)(1U) + tb_trap_halt__DOT__errors);
    }
    VL_WRITEF("\n==================== TRAP-HALT TEST ====================\n");
    if ((0U == tb_trap_halt__DOT__errors)) {
        VL_WRITEF("PASS: core halted correctly on trap\n  - PC parked at 0x%08x\n  - trap_valid held for %0d observed cycles\n  - no younger instruction (x10-x13) committed\n  - older instruction (x1) committed normally\n",
                  32,vlSelf->tb_trap_halt__DOT__pc_at_trap,
                  32,tb_trap_halt__DOT__cycles_after_trap);
    } else {
        VL_WRITEF("FAIL: %0d halt-behaviour error(s) detected\n",
                  32,tb_trap_halt__DOT__errors);
    }
    VL_WRITEF("=======================================================\n\n");
    if (VL_UNLIKELY((0U != tb_trap_halt__DOT__errors))) {
        VL_WRITEF("[%0t] %%Fatal: tb_trap_halt.sv:146: Assertion failed in %Ntb_trap_halt: trap-halt regression failed\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("../rtl/../tb/tb_trap_halt.sv", 146, "");
    }
    VL_FINISH_MT("../rtl/../tb/tb_trap_halt.sv", 147, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trap_halt___024root___dump_triggers__act(Vtb_trap_halt___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_trap_halt___024root___eval_triggers__act(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_trap_halt__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_trap_halt__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_trap_halt__DOT__clk__0 
        = vlSelf->tb_trap_halt__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_trap_halt___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*0:0*/, 256> Vtb_trap_halt__ConstPool__TABLE_h246a8395_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vtb_trap_halt__ConstPool__TABLE_h535cfbdd_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vtb_trap_halt__ConstPool__TABLE_hbc1849bd_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_trap_halt__ConstPool__TABLE_hfcff80f4_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_trap_halt__ConstPool__TABLE_hf2dcfc1f_0;
extern const VlUnpacked<CData/*0:0*/, 16384> Vtb_trap_halt__ConstPool__TABLE_h8b25f60c_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vtb_trap_halt__ConstPool__TABLE_hd161f257_0;
extern const VlUnpacked<CData/*3:0*/, 16> Vtb_trap_halt__ConstPool__TABLE_heb27db18_0;

VL_INLINE_OPT void Vtb_trap_halt___024root___nba_sequent__TOP__0(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__is_ecall;
    tb_trap_halt__DOT__uut__DOT__is_ecall = 0;
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__is_ebreak;
    tb_trap_halt__DOT__uut__DOT__is_ebreak = 0;
    IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__alu_operand_a;
    tb_trap_halt__DOT__uut__DOT__alu_operand_a = 0;
    IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__alu_operand_b;
    tb_trap_halt__DOT__uut__DOT__alu_operand_b = 0;
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__mem_misaligned;
    tb_trap_halt__DOT__uut__DOT__mem_misaligned = 0;
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__mem_out_of_range;
    tb_trap_halt__DOT__uut__DOT__mem_out_of_range = 0;
    IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__dec__DOT__imm_i;
    tb_trap_halt__DOT__uut__DOT__dec__DOT__imm_i = 0;
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__dec__DOT__legal_encoding;
    tb_trap_halt__DOT__uut__DOT__dec__DOT__legal_encoding = 0;
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgExtracted_h91cc8459__0;
    tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgExtracted_h91cc8459__0 = 0;
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h92ba0c04__0;
    tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h92ba0c04__0 = 0;
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h2f683b0d__0;
    tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h2f683b0d__0 = 0;
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__branch_ctrl__DOT____VdfgTmp_hf7257586__0;
    tb_trap_halt__DOT__uut__DOT__branch_ctrl__DOT____VdfgTmp_hf7257586__0 = 0;
    CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__dmem__DOT__access_ok;
    tb_trap_halt__DOT__uut__DOT__dmem__DOT__access_ok = 0;
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*7:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    SData/*13:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    IData/*31:0*/ __Vdly__tb_trap_halt__DOT__uut__DOT__pc;
    __Vdly__tb_trap_halt__DOT__uut__DOT__pc = 0;
    CData/*4:0*/ __Vdly__tb_trap_halt__DOT__uut__DOT__mem_wb_rd;
    __Vdly__tb_trap_halt__DOT__uut__DOT__mem_wb_rd = 0;
    SData/*8:0*/ __Vdly__tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index;
    __Vdly__tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index = 0;
    CData/*7:0*/ __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0;
    __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0 = 0;
    CData/*1:0*/ __Vdlyvval__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0;
    __Vdlyvval__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v1;
    __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v1;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v1 = 0;
    CData/*4:0*/ __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0;
    __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0;
    __Vdlyvval__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0;
    __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0;
    __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0;
    __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1;
    __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1;
    __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1;
    __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1 = 0;
    SData/*9:0*/ __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2;
    __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2;
    __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2 = 0;
    CData/*7:0*/ __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2;
    __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2 = 0;
    SData/*9:0*/ __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3;
    __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3;
    __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3 = 0;
    CData/*7:0*/ __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3;
    __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3 = 0;
    // Body
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__trap_valid)) 
                                   | (((((((2U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_cause)) 
                                           | (3U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_cause))) 
                                          | (0xbU == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_cause))) 
                                         | (4U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_cause))) 
                                        | (6U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_cause))) 
                                       | (5U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_cause))) 
                                      | (7U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_cause))))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:114: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_trap_cause_defined: Trap raised with undefined cause %0#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause));
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 114, "");
            }
        }
    }
    __Vdly__tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index;
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__predict_taken)) 
                                   | (0U == (3U & vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__predict_target)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:187: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_predict_target_aligned: Predicted target 0x%08x is not word aligned\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_trap_halt__DOT__uut__DOT__predict_target);
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 187, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__trap_valid)) 
                                   | (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_we)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:103: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_trap_suppresses_write: Register write committed on the same cycle as a trap\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 103, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_valid) 
                                   | (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_we)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:138: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_bubble_no_write: An invalid pipeline slot attempted a register write\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 138, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_valid) 
                                       & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_exception))) 
                                   | (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_we)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:119: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_exception_blocks_write: Faulting instruction wrote back\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 119, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | (0U == (3U & vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__pc))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:91: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_pc_word_aligned: PC 0x%08x is not word aligned\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 91, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken)) 
                                   | (0U == (3U & vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_target)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:97: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_redirect_aligned: Redirect target 0x%08x is not word aligned\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->tb_trap_halt__DOT__uut__DOT__control_target);
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 97, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | (3U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b_sel))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:227: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_b_sel_legal: forward_b_sel reached illegal value 2'b11\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 227, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | (3U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a_sel))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:223: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_a_sel_legal: forward_a_sel reached illegal value 2'b11\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 223, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__stall) 
                                      & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:149: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_no_stall_and_redirect: Stall and redirect asserted in the same cycle\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 149, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_we)) 
                                   | (0U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_rd)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:86: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_x0_never_written: Register file write targeted x0\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 86, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__trapped)) 
                                   | (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_we)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:127: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_trapped_blocks_all_writes: Register write committed after the core had already trapped\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 127, "");
            }
        }
    }
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0 = 0U;
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((2U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b_sel)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b 
                                      == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:278: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_b_mux_ex_mem: Operand B select says EX/MEM but the mux disagrees\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 278, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((1U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b_sel)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b 
                                      == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_data))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:282: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_b_mux_mem_wb: Operand B select says MEM/WB but the mux disagrees\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 282, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_9_0)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__pc 
                                      == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_10_0))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:182: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_resolve_beats_predict: Resolved redirect did not take priority over the prediction\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 182, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((2U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a_sel)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a 
                                      == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:266: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_a_mux_ex_mem: Operand A select says EX/MEM but the mux disagrees\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 266, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((1U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a_sel)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a 
                                      == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_data))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:270: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_a_mux_mem_wb: Operand A select says MEM/WB but the mux disagrees\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 270, "");
            }
        }
    }
    __Vdly__tb_trap_halt__DOT__uut__DOT__pc = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | (((0U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_mem_size)) 
                                    | (1U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_mem_size))) 
                                   | (2U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_mem_size)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:313: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_mem_size_legal: Undefined memory access size %0#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),2,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_mem_size));
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 313, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((((((((((((0U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl)) 
                                             | (1U 
                                                == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                            | (2U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                           | (3U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                          | (4U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                         | (5U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                        | (6U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                       | (7U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                      | (8U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                     | (9U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                    | (0xaU == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))) 
                                   | (0xfU == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:324: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_alu_ctrl_legal: Undefined ALU control code %0#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),4,(IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl));
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 324, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_7_0)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__pc 
                                      == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_8_0))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:177: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_prediction_steers_fetch: Predicted-taken branch did not steer fetch to the predicted target\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 177, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_5_0)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__pc 
                                      == ((IData)(4U) 
                                          + vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_6_0)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:171: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_pc_advances: PC failed to advance when it should have\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 171, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_0_0)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_1_0 
                                      == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__pc))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:133: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_trapped_freezes_pc: PC advanced after the core had already trapped\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 133, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_2_0)) 
                                   | (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_valid)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:154: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_redirect_flushes_id: IF/ID not flushed after a redirect\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 154, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((0U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b_sel)) 
                                   | (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs2))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:236: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_no_forward_unused_b: Forwarded into operand B of an instruction that does not read rs2\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 236, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((0U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a_sel)) 
                                   | (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs1))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:232: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_no_forward_unused_a: Forwarded into operand A of an instruction that does not read rs1\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 232, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_4_0)) 
                                   | (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_valid)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:164: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_stall_injects_bubble: Stall did not inject a bubble into EX\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 164, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_3_0)) 
                                   | (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_valid)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:159: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_redirect_flushes_ex: ID/EX not flushed after a redirect\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 159, "");
            }
        }
    }
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0 = 0U;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1 = 0U;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2 = 0U;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3 = 0U;
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((0U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b_sel)) 
                                   | (0U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rs2)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:245: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_no_forward_to_x0_b: Forwarded into x0 on operand B\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 245, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((0U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a_sel)) 
                                   | (0U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rs1)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:241: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_no_forward_to_x0_a: Forwarded into x0 on operand A\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 241, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((0U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b_sel)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b 
                                      == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd2))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:286: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_b_mux_regfile: Operand B select says register file but the mux disagrees\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 286, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((0U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a_sel)) 
                                   | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a 
                                      == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd1))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:274: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_a_mux_regfile: Operand A select says register file but the mux disagrees\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 274, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_is_branch) 
                                       & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_valid))) 
                                   | (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_is_branch))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:200: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_bp_update_branch_only: History table updated by a non-branch instruction\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 200, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_valid) 
                                        & ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__actual_taken) 
                                           == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_predict_taken))) 
                                       & ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__actual_taken)) 
                                          | (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__actual_target 
                                             == vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_predict_target)))) 
                                   | (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:195: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_no_spurious_redirect: Pipeline flushed despite a correct prediction\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 195, "");
            }
        }
    }
    __Vdly__tb_trap_halt__DOT__uut__DOT__mem_wb_rd 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0 = 0U;
    __Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v1 = 0U;
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_load)) 
                                   | (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:292: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_no_forward_from_load: Attempted to forward a load result out of EX/MEM\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 292, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__stall)) 
                                   | (((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_is_load) 
                                       & (0U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd))) 
                                      & (((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__uses_rs1) 
                                          & ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd) 
                                             == (0x1fU 
                                                 & (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                    >> 0xfU)))) 
                                         | ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__uses_rs2) 
                                            & ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd) 
                                               == (0x1fU 
                                                   & (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                      >> 0x14U)))))))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:207: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_stall_is_load_use: Stall asserted without a load-use hazard\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 207, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ ((((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs2) 
                                         & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward)) 
                                        & (0U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_rd))) 
                                       & ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_rd) 
                                          == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rs2)))) 
                                   | (2U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b_sel)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:260: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_b_priority: Operand B did not take EX/MEM priority\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 260, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ ((((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs1) 
                                         & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward)) 
                                        & (0U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_rd))) 
                                       & ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_rd) 
                                          == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rs1)))) 
                                   | (2U == (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a_sel)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:254: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_fwd_a_priority: Operand A did not take EX/MEM priority\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 254, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ (((((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_is_load) 
                                          & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_valid)) 
                                         & (0U != (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd))) 
                                        & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_valid)) 
                                       & (((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__uses_rs1) 
                                           & ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd) 
                                              == (0x1fU 
                                                  & (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                     >> 0xfU)))) 
                                          | ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__uses_rs2) 
                                             & ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd) 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                    >> 0x14U))))))) 
                                   | (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__stall))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:214: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_load_use_always_stalls: Load-use hazard did not produce a stall\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 214, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_load) 
                                      & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_store)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:301: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_mem_not_both: Data memory read and write asserted together\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 301, "");
            }
        }
    }
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset) 
                                | ((~ ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_load) 
                                       | (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_store))) 
                                   | ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_load) 
                                      | (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_store)))))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[%0t] %%Error: cpu_assertions.sv:306: Assertion failed in %Ntb_trap_halt.uut.u_assert.a_mem_access_justified: Memory accessed by a non memory instruction\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("../rtl/../rtl/cpu_assertions.sv", 306, "");
            }
        }
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_exception 
        = ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__reset))) 
           && ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)
                ? (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_exception)
                : (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_exception)));
    if (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__wb_we) 
         & (0U != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd)))) {
        __Vdlyvval__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__wb_data;
        __Vdlyvset__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0 = 1U;
        __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd;
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_valid 
        = ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__reset))) 
           && ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)
                ? (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_valid)
                : (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_valid)));
    if ((1U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__byte_en))) {
        __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0 
            = (0xffU & vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__store_word);
        __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0 = 1U;
        __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0 = 0U;
        __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0 
            = (0x3ffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result 
                         >> 2U));
    }
    if ((2U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__byte_en))) {
        __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1 
            = (0xffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__store_word 
                        >> 8U));
        __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1 = 1U;
        __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1 = 8U;
        __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1 
            = (0x3ffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result 
                         >> 2U));
    }
    if ((4U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__byte_en))) {
        __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2 
            = (0xffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__store_word 
                        >> 0x10U));
        __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2 = 1U;
        __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2 = 0x10U;
        __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2 
            = (0x3ffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result 
                         >> 2U));
    }
    if ((8U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__byte_en))) {
        __Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3 
            = (vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__store_word 
               >> 0x18U);
        __Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3 = 1U;
        __Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3 = 0x18U;
        __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3 
            = (0x3ffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result 
                         >> 2U));
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_reg_write 
        = ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__reset))) 
           && ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)
                ? (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_reg_write)
                : ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_reg_write) 
                   & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_exception)))));
    if ((0x100U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index))) {
        if (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_branch) 
             & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_valid))) {
            __Vdlyvval__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0 
                = (3U & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__branch_cond_taken)
                          ? ((3U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__current))
                              ? 3U : ((IData)(1U) + (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__current)))
                          : ((0U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__current))
                              ? 0U : ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__current) 
                                      - (IData)(1U)))));
            __Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0 = 1U;
            __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0 
                = (0xffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc 
                            >> 2U));
        }
    } else {
        __Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v1 = 1U;
        __Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v1 
            = (0xffU & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index));
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_link 
        = ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__reset))) 
           && ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)
                ? (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_link)
                : (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_link)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_load 
        = ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__reset))) 
           && ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)
                ? (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_load)
                : (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_itype 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (0x13U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_lui 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (0x37U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_auipc 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (0x17U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_10_0 
        = vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_target;
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_9_0 
        = ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset)) 
           & ((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken) 
              & (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__trap_valid))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_8_0 
        = vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__predict_target;
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_7_0 
        = ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset)) 
           & ((((IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__predict_taken) 
                & (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken))) 
               & (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__trap_valid))) 
              & (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__stall))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_6_0 
        = vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__pc;
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_5_0 
        = (1U & ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset)) 
                 & ((((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__stall)) 
                      & (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken))) 
                     & (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__trap_valid))) 
                    & (~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__predict_taken)))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_1_0 
        = vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__pc;
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_0_0 
        = ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset)) 
           & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__trapped));
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_2_0 
        = ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset)) 
           & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken));
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_4_0 
        = ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset)) 
           & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__stall));
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_3_0 
        = ((~ (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__reset)) 
           & (IData)(vlSelf->__Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken));
    if (__Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem[__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0))) 
                & vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem
                [__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0) 
                                   << (IData)(__Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v0))));
    }
    if (__Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem[__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1))) 
                & vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem
                [__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1) 
                                   << (IData)(__Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v1))));
    }
    if (__Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem[__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2))) 
                & vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem
                [__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2) 
                                   << (IData)(__Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v2))));
    }
    if (__Vdlyvset__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem[__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3))) 
                & vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem
                [__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3) 
                                   << (IData)(__Vdlyvlsb__tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem__v3))));
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_predict_taken 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_taken));
    if (((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
           | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
          | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
         | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_imm = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_funct3 = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl = 0xfU;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd2 = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd1 = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_predict_target = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs2 = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs1 = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc = 0U;
    } else {
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_imm 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__imm;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_funct3 
            = (7U & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                     >> 0xcU));
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__alu_ctrl;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd2 
            = (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__wb_we) 
                & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd) 
                   == (0x1fU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                >> 0x14U)))) ? vlSelf->tb_trap_halt__DOT__uut__DOT__wb_data
                : ((0U == (0x1fU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                    >> 0x14U))) ? 0U
                    : vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                   [(0x1fU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                              >> 0x14U))]));
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd1 
            = (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__wb_we) 
                & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd) 
                   == (0x1fU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                >> 0xfU)))) ? vlSelf->tb_trap_halt__DOT__uut__DOT__wb_data
                : ((0U == (0x1fU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                    >> 0xfU))) ? 0U
                    : vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs
                   [(0x1fU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                              >> 0xfU))]));
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_predict_target 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_target;
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs2 
            = (0x1fU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                        >> 0x14U));
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs1 
            = (0x1fU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                        >> 0xfU));
        vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc;
    }
    if (vlSelf->tb_trap_halt__DOT__reset) {
        __Vdly__tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause = 0U;
        __Vdly__tb_trap_halt__DOT__uut__DOT__pc = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_result = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_read_data = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_pc_plus_4 = 0U;
        __Vdly__tb_trap_halt__DOT__uut__DOT__mem_wb_rd = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_cause = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_done)))) {
            __Vdly__tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index)));
        }
        if (vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
            __Vdly__tb_trap_halt__DOT__uut__DOT__pc 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_result 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_result;
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_read_data 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_read_data;
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_pc_plus_4 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_pc_plus_4;
            __Vdly__tb_trap_halt__DOT__uut__DOT__mem_wb_rd 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd;
        } else {
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__mem_cause;
            if ((1U & ((~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)))) {
                __Vdly__tb_trap_halt__DOT__uut__DOT__pc 
                    = vlSelf->tb_trap_halt__DOT__uut__DOT__next_pc;
            }
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_result 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result;
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_read_data 
                = ((0U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size))
                    ? ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_unsigned)
                        ? (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__load_byte)
                        : (((- (IData)((1U & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__load_byte) 
                                              >> 7U)))) 
                            << 8U) | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__load_byte)))
                    : ((1U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size))
                        ? ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_unsigned)
                            ? (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__load_half)
                            : (((- (IData)((1U & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__load_half) 
                                                  >> 0xfU)))) 
                                << 0x10U) | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__load_half)))
                        : vlSelf->tb_trap_halt__DOT__uut__DOT__mem_read_data));
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_pc_plus_4 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_pc_plus_4;
            __Vdly__tb_trap_halt__DOT__uut__DOT__mem_wb_rd 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_rd;
        }
        if ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b;
            vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_cause 
                = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_cause;
        }
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_cause 
        = (((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
              | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
             | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
            | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))
            ? 0U : (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_cause));
    if (vlSelf->tb_trap_halt__DOT__reset) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_exception = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_unsigned = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size = 2U;
    } else if ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_exception 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_exception;
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__alu_result;
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_unsigned 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_mem_unsigned;
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_mem_size;
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_mem_size 
        = (((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
              | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
             | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
            | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))
            ? 2U : (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_size));
    if (vlSelf->tb_trap_halt__DOT__reset) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_pc_plus_4 = 0U;
    } else if ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_pc_plus_4 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc_plus_4;
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc_plus_4 
        = (((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
              | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
             | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
            | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))
            ? 0U : vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc_plus_4);
    if (vlSelf->tb_trap_halt__DOT__reset) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_rd = 0U;
    } else if ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_rd 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd;
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd = 
        (((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
            | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
           | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
          | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))
          ? 0U : (0x1fU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                           >> 7U)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index 
        = __Vdly__tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index;
    if (__Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__counters[__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0] 
            = __Vdlyvval__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v0;
    }
    if (__Vdlyvset__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v1) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__counters[__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__bp__DOT__counters__v1] = 1U;
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs2 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs2));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs1 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs1));
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_store 
        = ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))) 
               && (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_store) 
                    & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_valid)) 
                   & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_exception)))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_valid 
        = ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))) 
               && (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_valid)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_reg_write 
        = ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))) 
               && (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_reg_write)));
    if (__Vdlyvset__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs[__Vdlyvdim0__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0] 
            = __Vdlyvval__tb_trap_halt__DOT__uut__DOT__rf__DOT__regs__v0;
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd 
        = __Vdly__tb_trap_halt__DOT__uut__DOT__mem_wb_rd;
    vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_done 
        = (1U & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index) 
                 >> 8U));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_branch 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (0x63U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__wb_data = 
        ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_load)
          ? vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_read_data
          : ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_link)
              ? vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_pc_plus_4
              : vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_result));
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load 
        = ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))) 
               && (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_load) 
                    & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_valid)) 
                   & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_exception)))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__wb_we = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_reg_write) 
                                                  & ((~ 
                                                      ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_exception) 
                                                       | (0U 
                                                          == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd)))) 
                                                     & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_valid)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_store 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (0x23U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    if (vlSelf->tb_trap_halt__DOT__reset) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_link = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__trapped = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_link 
                = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jal) 
                   | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jalr));
        }
        if (vlSelf->tb_trap_halt__DOT__trap_valid) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__trapped = 1U;
        }
    }
    vlSelf->tb_trap_halt__DOT__trap_valid = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_exception) 
                                             & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_valid));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_mem_unsigned 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_unsigned));
    vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__store_word 
        = ((0U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size))
            ? ((vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data 
                << 0x18U) | ((0xff0000U & (vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data 
                                           << 0x10U)) 
                             | ((0xff00U & (vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data 
                                            << 8U)) 
                                | (0xffU & vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data))))
            : ((1U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size))
                ? ((vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data 
                    << 0x10U) | (0xffffU & vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data))
                : vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data));
    tb_trap_halt__DOT__uut__DOT__mem_misaligned = (1U 
                                                   & ((1U 
                                                       == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size))
                                                       ? vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result
                                                       : 
                                                      ((2U 
                                                        == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size)) 
                                                       && (0U 
                                                           != 
                                                           (3U 
                                                            & vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result)))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_reg_write 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__reg_write) 
                & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_valid)) 
               & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_exception))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__current 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__counters
        [(0xffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc 
                   >> 2U))];
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data 
        = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_link)
            ? vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_pc_plus_4
            : vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jalr 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__is_jalr));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jal 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (0x6fU == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    tb_trap_halt__DOT__uut__DOT__mem_out_of_range = 
        (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load) 
          | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_store)) 
         & (0x1000U <= vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result));
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward 
        = ((~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load)) 
           & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_reg_write));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_exception 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_exception));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_valid 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_valid));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_load 
        = ((1U & (~ ((((IData)(vlSelf->tb_trap_halt__DOT__reset) 
                       | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)) 
                      | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)) 
                     | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold)))) 
           && (3U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    if (vlSelf->tb_trap_halt__DOT__reset) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_target = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_taken = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc_plus_4 = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_valid = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr = 0U;
    } else if (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken) 
                | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold))) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_target = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_taken = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc_plus_4 = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_valid = 0U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr = 0U;
    } else if ((1U & (~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__stall)))) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_target 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__predict_target;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_taken 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__predict_taken;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__pc;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc_plus_4 
            = ((IData)(4U) + vlSelf->tb_trap_halt__DOT__uut__DOT__pc);
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_valid = 1U;
        vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
            = vlSelf->tb_trap_halt__DOT__uut__DOT__instr;
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_exception 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_exception;
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_cause 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_cause;
    if (((~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_exception)) 
         & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load) 
            | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_store)))) {
        if (tb_trap_halt__DOT__uut__DOT__mem_misaligned) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_exception = 1U;
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_cause 
                = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load)
                    ? 4U : 6U);
        } else if (tb_trap_halt__DOT__uut__DOT__mem_out_of_range) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_exception = 1U;
            vlSelf->tb_trap_halt__DOT__uut__DOT__mem_cause 
                = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load)
                    ? 5U : 7U);
        }
    }
    tb_trap_halt__DOT__uut__DOT__dmem__DOT__access_ok 
        = (1U & ((~ (IData)(tb_trap_halt__DOT__uut__DOT__mem_misaligned)) 
                 & (~ (IData)(tb_trap_halt__DOT__uut__DOT__mem_out_of_range))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b_sel = 0U;
    if (vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs2) {
        if ((((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward) 
              & (0U != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_rd))) 
             & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_rd) 
                == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs2)))) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b_sel = 2U;
        } else if ((((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_reg_write) 
                     & (0U != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd))) 
                    & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd) 
                       == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs2)))) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b_sel = 1U;
        }
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a_sel = 0U;
    if (vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs1) {
        if ((((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward) 
              & (0U != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_rd))) 
             & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_rd) 
                == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs1)))) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a_sel = 2U;
        } else if ((((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_reg_write) 
                     & (0U != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd))) 
                    & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd) 
                       == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs1)))) {
            vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a_sel = 1U;
        }
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__byte_en = 0U;
    if (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_store) 
         & (IData)(tb_trap_halt__DOT__uut__DOT__dmem__DOT__access_ok))) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__byte_en 
            = (0xfU & ((0U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size))
                        ? ((IData)(1U) << (3U & vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result))
                        : ((1U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size))
                            ? ((IData)(3U) << (3U & vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result))
                            : ((2U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size))
                                ? 0xfU : 0U))));
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_read_data 
        = (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load) 
            & (IData)(tb_trap_halt__DOT__uut__DOT__dmem__DOT__access_ok))
            ? vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem
           [(0x3ffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result 
                       >> 2U))] : 0U);
    vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b 
        = ((2U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b_sel))
            ? vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data
            : ((1U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b_sel))
                ? vlSelf->tb_trap_halt__DOT__uut__DOT__wb_data
                : vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd2));
    vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a 
        = ((2U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a_sel))
            ? vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data
            : ((1U == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a_sel))
                ? vlSelf->tb_trap_halt__DOT__uut__DOT__wb_data
                : vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd1));
    vlSelf->tb_trap_halt__DOT__uut__DOT__pc = __Vdly__tb_trap_halt__DOT__uut__DOT__pc;
    vlSelf->tb_trap_halt__DOT__uut__DOT__load_byte 
        = (0xffU & ((0U == (3U & vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result))
                     ? vlSelf->tb_trap_halt__DOT__uut__DOT__mem_read_data
                     : ((1U == (3U & vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result))
                         ? (vlSelf->tb_trap_halt__DOT__uut__DOT__mem_read_data 
                            >> 8U) : ((2U == (3U & vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result))
                                       ? (vlSelf->tb_trap_halt__DOT__uut__DOT__mem_read_data 
                                          >> 0x10U)
                                       : (vlSelf->tb_trap_halt__DOT__uut__DOT__mem_read_data 
                                          >> 0x18U)))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__load_half 
        = (0xffffU & ((2U & vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result)
                       ? (vlSelf->tb_trap_halt__DOT__uut__DOT__mem_read_data 
                          >> 0x10U) : vlSelf->tb_trap_halt__DOT__uut__DOT__mem_read_data));
    tb_trap_halt__DOT__uut__DOT__alu_operand_b = (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_itype) 
                                                   | ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_load) 
                                                      | ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_store) 
                                                         | ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jalr) 
                                                            | ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_auipc) 
                                                               | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_lui))))))
                                                   ? vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_imm
                                                   : vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b);
    tb_trap_halt__DOT__uut__DOT__alu_operand_a = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_auipc)
                                                   ? vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc
                                                   : vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a);
    vlSelf->tb_trap_halt__DOT__uut__DOT__branch_cond_taken = 0U;
    if (vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_branch) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__branch_cond_taken 
            = ((4U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_funct3))
                ? ((2U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_funct3))
                    ? ((1U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_funct3))
                        ? (vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a 
                           >= vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b)
                        : (vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a 
                           < vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b))
                    : ((1U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_funct3))
                        ? VL_GTES_III(32, vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a, vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b)
                        : VL_LTS_III(32, vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a, vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b)))
                : ((1U & (~ ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_funct3) 
                             >> 1U))) && ((1U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_funct3))
                                           ? (vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a 
                                              != vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b)
                                           : (vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a 
                                              == vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b))));
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold 
        = ((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
           | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trapped));
    vlSelf->tb_trap_halt__DOT__uut__DOT__instr = vlSelf->tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__mem
        [(0x3ffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                    >> 2U))];
    vlSelf->tb_trap_halt__DOT__uut__DOT__alu_result 
        = ((8U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
            ? ((4U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                ? 0U : ((2U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                         ? ((1U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                             ? 0U : tb_trap_halt__DOT__uut__DOT__alu_operand_b)
                         : ((1U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                             ? (tb_trap_halt__DOT__uut__DOT__alu_operand_a 
                                & tb_trap_halt__DOT__uut__DOT__alu_operand_b)
                             : (tb_trap_halt__DOT__uut__DOT__alu_operand_a 
                                | tb_trap_halt__DOT__uut__DOT__alu_operand_b))))
            : ((4U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                ? ((2U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                    ? ((1U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                        ? VL_SHIFTRS_III(32,32,5, tb_trap_halt__DOT__uut__DOT__alu_operand_a, 
                                         (0x1fU & tb_trap_halt__DOT__uut__DOT__alu_operand_b))
                        : (tb_trap_halt__DOT__uut__DOT__alu_operand_a 
                           >> (0x1fU & tb_trap_halt__DOT__uut__DOT__alu_operand_b)))
                    : ((1U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                        ? (tb_trap_halt__DOT__uut__DOT__alu_operand_a 
                           ^ tb_trap_halt__DOT__uut__DOT__alu_operand_b)
                        : ((tb_trap_halt__DOT__uut__DOT__alu_operand_a 
                            < tb_trap_halt__DOT__uut__DOT__alu_operand_b)
                            ? 1U : 0U))) : ((2U & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                                             ? ((1U 
                                                 & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                                                 ? 
                                                (VL_LTS_III(32, tb_trap_halt__DOT__uut__DOT__alu_operand_a, tb_trap_halt__DOT__uut__DOT__alu_operand_b)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                (tb_trap_halt__DOT__uut__DOT__alu_operand_a 
                                                 << 
                                                 (0x1fU 
                                                  & tb_trap_halt__DOT__uut__DOT__alu_operand_b)))
                                             : ((1U 
                                                 & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl))
                                                 ? 
                                                (tb_trap_halt__DOT__uut__DOT__alu_operand_a 
                                                 - tb_trap_halt__DOT__uut__DOT__alu_operand_b)
                                                 : 
                                                (tb_trap_halt__DOT__uut__DOT__alu_operand_a 
                                                 + tb_trap_halt__DOT__uut__DOT__alu_operand_b)))));
    tb_trap_halt__DOT__uut__DOT__branch_ctrl__DOT____VdfgTmp_hf7257586__0 
        = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__branch_cond_taken) 
           | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jal));
    __Vtableidx3 = (((0U == (7U & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                   >> 0xcU))) << 7U) 
                    | (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr));
    vlSelf->tb_trap_halt__DOT__uut__DOT__reg_write 
        = Vtb_trap_halt__ConstPool__TABLE_h246a8395_0
        [__Vtableidx3];
    vlSelf->tb_trap_halt__DOT__uut__DOT__is_jalr = (IData)(
                                                           (0x67U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    tb_trap_halt__DOT__uut__DOT__dec__DOT__imm_i = 
        (((- (IData)((vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                      >> 0x1fU))) << 0xcU) | (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                              >> 0x14U));
    __Vtableidx4 = (((0x23U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)) 
                     << 4U) | ((0xeU & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                        >> 0xbU)) | 
                               (3U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_size = 
        Vtb_trap_halt__ConstPool__TABLE_h535cfbdd_0
        [__Vtableidx4];
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_unsigned 
        = Vtb_trap_halt__ConstPool__TABLE_hbc1849bd_0
        [__Vtableidx4];
    __Vtableidx2 = (((0U == (7U & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                   >> 0xcU))) << 7U) 
                    | (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr));
    vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs1 = 
        Vtb_trap_halt__ConstPool__TABLE_hfcff80f4_0
        [__Vtableidx2];
    vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs2 = 
        Vtb_trap_halt__ConstPool__TABLE_hf2dcfc1f_0
        [__Vtableidx2];
    tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgExtracted_h91cc8459__0 
        = ((0U == (7U & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                         >> 0xcU))) | ((1U == (7U & 
                                               (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                >> 0xcU))) 
                                       | (2U == (7U 
                                                 & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                    >> 0xcU)))));
    tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h2f683b0d__0 
        = ((0U == (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                   >> 0x19U)) | (0x20U == (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                           >> 0x19U)));
    tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h92ba0c04__0 
        = (IData)((0x73U == (0x707fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__predict_target 
        = (vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
           + ((0x6fU == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__instr))
               ? (((- (IData)((vlSelf->tb_trap_halt__DOT__uut__DOT__instr 
                               >> 0x1fU))) << 0x15U) 
                  | ((0x100000U & (vlSelf->tb_trap_halt__DOT__uut__DOT__instr 
                                   >> 0xbU)) | ((0xff000U 
                                                 & vlSelf->tb_trap_halt__DOT__uut__DOT__instr) 
                                                | ((0x800U 
                                                    & (vlSelf->tb_trap_halt__DOT__uut__DOT__instr 
                                                       >> 9U)) 
                                                   | (0x7feU 
                                                      & (vlSelf->tb_trap_halt__DOT__uut__DOT__instr 
                                                         >> 0x14U))))))
               : (((- (IData)((vlSelf->tb_trap_halt__DOT__uut__DOT__instr 
                               >> 0x1fU))) << 0xdU) 
                  | ((0x1000U & (vlSelf->tb_trap_halt__DOT__uut__DOT__instr 
                                 >> 0x13U)) | ((0x800U 
                                                & (vlSelf->tb_trap_halt__DOT__uut__DOT__instr 
                                                   << 4U)) 
                                               | ((0x7e0U 
                                                   & (vlSelf->tb_trap_halt__DOT__uut__DOT__instr 
                                                      >> 0x14U)) 
                                                  | (0x1eU 
                                                     & (vlSelf->tb_trap_halt__DOT__uut__DOT__instr 
                                                        >> 7U))))))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__predict_taken 
        = ((0x6fU == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__instr)) 
           | ((0x63U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__instr)) 
              & (vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__counters
                 [(0xffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                            >> 2U))] >> 1U)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__actual_taken 
        = ((IData)(tb_trap_halt__DOT__uut__DOT__branch_ctrl__DOT____VdfgTmp_hf7257586__0) 
           | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jalr));
    vlSelf->tb_trap_halt__DOT__uut__DOT__actual_target 
        = ((IData)(tb_trap_halt__DOT__uut__DOT__branch_ctrl__DOT____VdfgTmp_hf7257586__0)
            ? (vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_imm 
               + vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc)
            : ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jalr)
                ? (0xfffffffeU & (vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a 
                                  + vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_imm))
                : 0U));
    vlSelf->tb_trap_halt__DOT__uut__DOT__alu_ctrl = 
        ((0x33U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr))
          ? ((0x4000U & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
              ? ((0x2000U & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                  ? ((0x1000U & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                      ? 9U : 8U) : ((0x1000U & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                     ? ((0x20U == (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                   >> 0x19U))
                                         ? 7U : 6U)
                                     : 5U)) : ((0x2000U 
                                                & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                    ? 4U
                                                    : 3U)
                                                : (
                                                   (0x1000U 
                                                    & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                    ? 2U
                                                    : 
                                                   ((0x20U 
                                                     == 
                                                     (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                      >> 0x19U))
                                                     ? 1U
                                                     : 0U))))
          : ((0x13U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr))
              ? ((0x4000U & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                  ? ((0x2000U & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                      ? ((0x1000U & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                          ? 9U : 8U) : ((0x1000U & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                         ? ((0x20U 
                                             == (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                 >> 0x19U))
                                             ? 7U : 6U)
                                         : 5U)) : (
                                                   (0x2000U 
                                                    & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                    ? 
                                                   ((0x1000U 
                                                     & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                     ? 4U
                                                     : 3U)
                                                    : 
                                                   ((0x1000U 
                                                     & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                     ? 2U
                                                     : 0U)))
              : (((3U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)) 
                  | ((0x23U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)) 
                     | ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__is_jalr) 
                        | (0x17U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)))))
                  ? 0U : ((0x37U == (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr))
                           ? 0xaU : 0xfU))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__imm = ((0x40U 
                                                 & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                 ? 
                                                ((0x20U 
                                                  & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                  ? 
                                                 ((0x10U 
                                                   & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                   ? 0U
                                                   : 
                                                  ((8U 
                                                    & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                    ? 
                                                   ((4U 
                                                     & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                    >> 0x1fU))) 
                                                        << 0x15U) 
                                                       | ((0x100000U 
                                                           & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                              >> 0xbU)) 
                                                          | ((0xff000U 
                                                              & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr) 
                                                             | ((0x800U 
                                                                 & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                    >> 9U)) 
                                                                | (0x7feU 
                                                                   & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                      >> 0x14U))))))
                                                       : 0U)
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       ? tb_trap_halt__DOT__uut__DOT__dec__DOT__imm_i
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                    >> 0x1fU))) 
                                                        << 0xdU) 
                                                       | ((0x1000U 
                                                           & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                              >> 0x13U)) 
                                                          | ((0x800U 
                                                              & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                 << 4U)) 
                                                             | ((0x7e0U 
                                                                 & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                    >> 0x14U)) 
                                                                | (0x1eU 
                                                                   & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                      >> 7U))))))
                                                       : 0U)
                                                      : 0U))))
                                                  : 0U)
                                                 : 
                                                ((0x20U 
                                                  & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                  ? 
                                                 ((0x10U 
                                                   & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                   ? 
                                                  ((8U 
                                                    & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       ? 
                                                      (0xfffff000U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       : 0U)
                                                      : 0U)
                                                     : 0U))
                                                   : 
                                                  ((8U 
                                                    & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                    >> 0x1fU))) 
                                                        << 0xcU) 
                                                       | ((0xfe0U 
                                                           & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                              >> 0x14U)) 
                                                          | (0x1fU 
                                                             & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                >> 7U))))
                                                       : 0U)
                                                      : 0U))))
                                                  : 
                                                 ((0x10U 
                                                   & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                   ? 
                                                  ((8U 
                                                    & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       ? 
                                                      (0xfffff000U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       ? tb_trap_halt__DOT__uut__DOT__dec__DOT__imm_i
                                                       : 0U)
                                                      : 0U)))
                                                   : 
                                                  ((8U 
                                                    & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)
                                                       ? tb_trap_halt__DOT__uut__DOT__dec__DOT__imm_i
                                                       : 0U)
                                                      : 0U))))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__stall = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_load) 
                                                  & ((0U 
                                                      != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd)) 
                                                     & (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs1) 
                                                         & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd) 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                >> 0xfU)))) 
                                                        | ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs2) 
                                                           & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd) 
                                                              == 
                                                              (0x1fU 
                                                               & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                                  >> 0x14U)))))));
    tb_trap_halt__DOT__uut__DOT__is_ecall = ((IData)(tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h92ba0c04__0) 
                                             & (0U 
                                                == 
                                                (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                 >> 0x14U)));
    tb_trap_halt__DOT__uut__DOT__is_ebreak = ((IData)(tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h92ba0c04__0) 
                                              & (1U 
                                                 == 
                                                 (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                  >> 0x14U)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__control_target 
        = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__actual_taken)
            ? vlSelf->tb_trap_halt__DOT__uut__DOT__actual_target
            : vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc_plus_4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken 
        = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_valid) 
           & (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__actual_taken) 
               != (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_predict_taken)) 
              | ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__actual_taken) 
                 & (vlSelf->tb_trap_halt__DOT__uut__DOT__actual_target 
                    != vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_predict_target))));
    __Vtableidx5 = ((((IData)(tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgExtracted_h91cc8459__0) 
                      | ((4U == (7U & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                       >> 0xcU))) | 
                         (5U == (7U & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                       >> 0xcU))))) 
                     << 0xdU) | ((((1U == (7U & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                 >> 0xcU)))
                                    ? (0U == (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                              >> 0x19U))
                                    : (IData)(((0x5000U 
                                                != 
                                                (0x7000U 
                                                 & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)) 
                                               | (IData)(tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h2f683b0d__0)))) 
                                  << 0xcU) | (((IData)(tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgExtracted_h91cc8459__0) 
                                               << 0xbU) 
                                              | (((((0U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                         >> 0xcU))) 
                                                    | (5U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                           >> 0xcU))))
                                                    ? (IData)(tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h2f683b0d__0)
                                                    : 
                                                   (0U 
                                                    == 
                                                    (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                     >> 0x19U))) 
                                                  << 0xaU) 
                                                 | ((((2U 
                                                       != 
                                                       (7U 
                                                        & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                           >> 0xcU))) 
                                                      & (3U 
                                                         != 
                                                         (7U 
                                                          & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                             >> 0xcU)))) 
                                                     << 9U) 
                                                    | (((0U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                                             >> 0xcU))) 
                                                        << 8U) 
                                                       | ((((IData)(tb_trap_halt__DOT__uut__DOT__is_ecall) 
                                                            | (IData)(tb_trap_halt__DOT__uut__DOT__is_ebreak)) 
                                                           << 7U) 
                                                          | (0x7fU 
                                                             & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr))))))));
    tb_trap_halt__DOT__uut__DOT__dec__DOT__legal_encoding 
        = Vtb_trap_halt__ConstPool__TABLE_h8b25f60c_0
        [__Vtableidx5];
    vlSelf->tb_trap_halt__DOT__uut__DOT__next_pc = 
        ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)
          ? vlSelf->tb_trap_halt__DOT__uut__DOT__control_target
          : ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__predict_taken)
              ? vlSelf->tb_trap_halt__DOT__uut__DOT__predict_target
              : ((IData)(4U) + vlSelf->tb_trap_halt__DOT__uut__DOT__pc)));
    __Vtableidx1 = (((IData)(tb_trap_halt__DOT__uut__DOT__is_ebreak) 
                     << 3U) | (((IData)(tb_trap_halt__DOT__uut__DOT__is_ecall) 
                                << 2U) | ((2U & ((~ (IData)(tb_trap_halt__DOT__uut__DOT__dec__DOT__legal_encoding)) 
                                                 << 1U)) 
                                          | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_valid))));
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_exception 
        = Vtb_trap_halt__ConstPool__TABLE_hd161f257_0
        [__Vtableidx1];
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_cause = 
        Vtb_trap_halt__ConstPool__TABLE_heb27db18_0
        [__Vtableidx1];
}
