// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cpu.h for the primary calling header

#include "Vtb_cpu__pch.h"
#include "Vtb_cpu___024root.h"

VL_ATTR_COLD void Vtb_cpu___024root___eval_initial__TOP(Vtb_cpu___024root* vlSelf);
VlCoroutine Vtb_cpu___024root___eval_initial__TOP__Vtiming__0(Vtb_cpu___024root* vlSelf);
VlCoroutine Vtb_cpu___024root___eval_initial__TOP__Vtiming__1(Vtb_cpu___024root* vlSelf);

void Vtb_cpu___024root___eval_initial(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_initial\n"); );
    // Body
    Vtb_cpu___024root___eval_initial__TOP(vlSelf);
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
    vlSelf->tb_cpu__DOT__cycle = 0U;
    co_await vlSelf->__VdlySched.delay(0xaULL, nullptr, 
                                       "../tb/tb_cpu.sv", 
                                       26);
    vlSelf->tb_cpu__DOT__reset = 0U;
    co_await vlSelf->__VdlySched.delay(0x64ULL, nullptr, 
                                       "../tb/tb_cpu.sv", 
                                       29);
    VL_FINISH_MT("../tb/tb_cpu.sv", 30, "");
}

VL_INLINE_OPT VlCoroutine Vtb_cpu___024root___eval_initial__TOP__Vtiming__1(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(5ULL, nullptr, 
                                           "../tb/tb_cpu.sv", 
                                           16);
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
    // Init
    IData/*31:0*/ __Vdly__tb_cpu__DOT__cycle;
    __Vdly__tb_cpu__DOT__cycle = 0;
    CData/*4:0*/ __Vdlyvdim0__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0;
    __Vdlyvdim0__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0;
    __Vdlyvval__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0;
    __Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 0;
    // Body
    __Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 0U;
    __Vdly__tb_cpu__DOT__cycle = vlSelf->tb_cpu__DOT__cycle;
    if ((((0x13U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)) 
          | (0x33U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) 
         & (0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd)))) {
        __Vdlyvval__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 
            = vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result;
        __Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 1U;
        __Vdlyvdim0__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 
            = vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd;
    }
    vlSelf->tb_cpu__DOT__uut__DOT__pc = ((IData)(vlSelf->tb_cpu__DOT__reset)
                                          ? 0U : ((IData)(4U) 
                                                  + vlSelf->tb_cpu__DOT__uut__DOT__pc));
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_cpu__DOT__reset))))) {
        __Vdly__tb_cpu__DOT__cycle = ((IData)(1U) + vlSelf->tb_cpu__DOT__cycle);
        VL_WRITEF("C=%0# | IF=%x | ID=%x | EX(rs1=%0# rs2=%0#) | RAW(rd1=%0# rd2=%0#) | FWD_A=%0# FWD_B=%0# | SEL_A=%b SEL_B=%b | EX_OUT=%0# | WB(rd=%0# data=%0#)\n",
                  32,vlSelf->tb_cpu__DOT__cycle,32,
                  vlSelf->tb_cpu__DOT__uut__DOT__instr,
                  32,vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr,
                  5,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1),
                  5,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2,
                  32,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1,
                  32,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2,
                  32,vlSelf->tb_cpu__DOT__uut__DOT__forward_a,
                  32,vlSelf->tb_cpu__DOT__uut__DOT__forward_b,
                  2,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel),
                  2,vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel,
                  32,vlSelf->tb_cpu__DOT__uut__DOT__alu_result,
                  5,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd),
                  32,vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result);
    }
    if (vlSelf->tb_cpu__DOT__reset) {
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1 = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2 = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1 = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2 = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr = 0U;
    } else {
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm = 
            (((- (IData)((vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                          >> 0x1fU))) << 0xcU) | (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                  >> 0x14U));
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode 
            = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1 = 
            vlSelf->tb_cpu__DOT__uut__DOT__rf__DOT__regs
            [(0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                       >> 0xfU))];
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2 = 
            vlSelf->tb_cpu__DOT__uut__DOT__rf__DOT__regs
            [(0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                       >> 0x14U))];
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1 = 
            (0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                      >> 0xfU));
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2 = 
            (0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                      >> 0x14U));
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result 
            = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode 
            = vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result 
            = vlSelf->tb_cpu__DOT__uut__DOT__alu_result;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd = vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode 
            = (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr);
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd = (0x1fU 
                                                   & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                      >> 7U));
        vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
            = vlSelf->tb_cpu__DOT__uut__DOT__instr;
    }
    vlSelf->tb_cpu__DOT__cycle = __Vdly__tb_cpu__DOT__cycle;
    if (__Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0) {
        vlSelf->tb_cpu__DOT__uut__DOT__rf__DOT__regs[__Vdlyvdim0__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0] 
            = __Vdlyvval__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0;
    }
    vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel = 0U;
    if ((((0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd)) 
          & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd) 
             == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1))) 
         & ((0x13U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)) 
            | (0x33U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode))))) {
        vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel = 2U;
    } else if ((((0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd)) 
                 & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd) 
                    == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1))) 
                & ((0x13U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)) 
                   | (0x33U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))))) {
        vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel = 1U;
    }
    vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel = 0U;
    if ((((0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd)) 
          & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd) 
             == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2))) 
         & ((0x13U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)) 
            | (0x33U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode))))) {
        vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel = 2U;
    } else if ((((0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd)) 
                 & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd) 
                    == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2))) 
                & ((0x13U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)) 
                   | (0x33U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))))) {
        vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel = 1U;
    }
    vlSelf->tb_cpu__DOT__uut__DOT__forward_a = ((2U 
                                                 == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel))
                                                 ? vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result
                                                 : 
                                                ((1U 
                                                  == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel))
                                                  ? vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result
                                                  : vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1));
    vlSelf->tb_cpu__DOT__uut__DOT__forward_b = ((2U 
                                                 == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel))
                                                 ? vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result
                                                 : 
                                                ((1U 
                                                  == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel))
                                                  ? vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result
                                                  : vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2));
    vlSelf->tb_cpu__DOT__uut__DOT__alu_result = (vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                                                 + 
                                                 ((0x13U 
                                                   == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode))
                                                   ? vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm
                                                   : vlSelf->tb_cpu__DOT__uut__DOT__forward_b));
    vlSelf->tb_cpu__DOT__uut__DOT__instr = vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem
        [(0xffU & (vlSelf->tb_cpu__DOT__uut__DOT__pc 
                   >> 2U))];
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
