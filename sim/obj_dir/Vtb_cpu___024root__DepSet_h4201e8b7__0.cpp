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

VL_INLINE_OPT VlCoroutine Vtb_cpu___024root___eval_initial__TOP__Vtiming__1(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(5ULL, nullptr, 
                                           "../rtl/../tb/tb_cpu.sv", 
                                           26);
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

VL_INLINE_OPT void Vtb_cpu___024root___nba_sequent__TOP__2(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___nba_sequent__TOP__2\n"); );
    // Init
    std::string __Vfunc_disasm__6__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__6__instr;
    __Vfunc_disasm__6__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__6__opcode;
    __Vfunc_disasm__6__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__6__funct3;
    __Vfunc_disasm__6__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__6__funct7;
    __Vfunc_disasm__6__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__6__rd;
    __Vfunc_disasm__6__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__6__rs1;
    __Vfunc_disasm__6__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__6__rs2;
    __Vfunc_disasm__6__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__6__imm_i;
    __Vfunc_disasm__6__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__6__imm_s;
    __Vfunc_disasm__6__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__6__imm_b;
    __Vfunc_disasm__6__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__6__imm_j;
    __Vfunc_disasm__6__imm_j = 0;
    std::string __Vfunc_disasm__7__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__7__instr;
    __Vfunc_disasm__7__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__7__opcode;
    __Vfunc_disasm__7__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__7__funct3;
    __Vfunc_disasm__7__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__7__funct7;
    __Vfunc_disasm__7__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__7__rd;
    __Vfunc_disasm__7__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__7__rs1;
    __Vfunc_disasm__7__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__7__rs2;
    __Vfunc_disasm__7__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__7__imm_i;
    __Vfunc_disasm__7__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__7__imm_s;
    __Vfunc_disasm__7__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__7__imm_b;
    __Vfunc_disasm__7__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__7__imm_j;
    __Vfunc_disasm__7__imm_j = 0;
    std::string __Vfunc_disasm__8__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__8__instr;
    __Vfunc_disasm__8__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__8__opcode;
    __Vfunc_disasm__8__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__8__funct3;
    __Vfunc_disasm__8__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__8__funct7;
    __Vfunc_disasm__8__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__8__rd;
    __Vfunc_disasm__8__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__8__rs1;
    __Vfunc_disasm__8__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__8__rs2;
    __Vfunc_disasm__8__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__8__imm_i;
    __Vfunc_disasm__8__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__8__imm_s;
    __Vfunc_disasm__8__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__8__imm_b;
    __Vfunc_disasm__8__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__8__imm_j;
    __Vfunc_disasm__8__imm_j = 0;
    std::string __Vfunc_disasm__9__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__9__instr;
    __Vfunc_disasm__9__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__9__opcode;
    __Vfunc_disasm__9__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__9__funct3;
    __Vfunc_disasm__9__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__9__funct7;
    __Vfunc_disasm__9__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__9__rd;
    __Vfunc_disasm__9__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__9__rs1;
    __Vfunc_disasm__9__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__9__rs2;
    __Vfunc_disasm__9__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__9__imm_i;
    __Vfunc_disasm__9__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__9__imm_s;
    __Vfunc_disasm__9__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__9__imm_b;
    __Vfunc_disasm__9__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__9__imm_j;
    __Vfunc_disasm__9__imm_j = 0;
    std::string __Vfunc_disasm__10__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__10__instr;
    __Vfunc_disasm__10__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__10__opcode;
    __Vfunc_disasm__10__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__10__funct3;
    __Vfunc_disasm__10__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__10__funct7;
    __Vfunc_disasm__10__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__10__rd;
    __Vfunc_disasm__10__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__10__rs1;
    __Vfunc_disasm__10__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__10__rs2;
    __Vfunc_disasm__10__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__10__imm_i;
    __Vfunc_disasm__10__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__10__imm_s;
    __Vfunc_disasm__10__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__10__imm_b;
    __Vfunc_disasm__10__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__10__imm_j;
    __Vfunc_disasm__10__imm_j = 0;
    std::string __Vfunc_disasm__12__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__12__instr;
    __Vfunc_disasm__12__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__12__opcode;
    __Vfunc_disasm__12__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__12__funct3;
    __Vfunc_disasm__12__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__12__funct7;
    __Vfunc_disasm__12__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__12__rd;
    __Vfunc_disasm__12__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__12__rs1;
    __Vfunc_disasm__12__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__12__rs2;
    __Vfunc_disasm__12__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__12__imm_i;
    __Vfunc_disasm__12__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__12__imm_s;
    __Vfunc_disasm__12__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__12__imm_b;
    __Vfunc_disasm__12__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__12__imm_j;
    __Vfunc_disasm__12__imm_j = 0;
    std::string __Vfunc_disasm__13__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__13__instr;
    __Vfunc_disasm__13__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__13__opcode;
    __Vfunc_disasm__13__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__13__funct3;
    __Vfunc_disasm__13__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__13__funct7;
    __Vfunc_disasm__13__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__13__rd;
    __Vfunc_disasm__13__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__13__rs1;
    __Vfunc_disasm__13__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__13__rs2;
    __Vfunc_disasm__13__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__13__imm_i;
    __Vfunc_disasm__13__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__13__imm_s;
    __Vfunc_disasm__13__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__13__imm_b;
    __Vfunc_disasm__13__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__13__imm_j;
    __Vfunc_disasm__13__imm_j = 0;
    std::string __Vfunc_disasm__14__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__14__instr;
    __Vfunc_disasm__14__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__14__opcode;
    __Vfunc_disasm__14__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__14__funct3;
    __Vfunc_disasm__14__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__14__funct7;
    __Vfunc_disasm__14__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__14__rd;
    __Vfunc_disasm__14__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__14__rs1;
    __Vfunc_disasm__14__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__14__rs2;
    __Vfunc_disasm__14__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__14__imm_i;
    __Vfunc_disasm__14__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__14__imm_s;
    __Vfunc_disasm__14__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__14__imm_b;
    __Vfunc_disasm__14__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__14__imm_j;
    __Vfunc_disasm__14__imm_j = 0;
    std::string __Vfunc_tb_cpu__DOT__fwd_sel_name__15__Vfuncout;
    CData/*1:0*/ __Vfunc_tb_cpu__DOT__fwd_sel_name__15__sel;
    __Vfunc_tb_cpu__DOT__fwd_sel_name__15__sel = 0;
    std::string __Vfunc_tb_cpu__DOT__fwd_sel_name__16__Vfuncout;
    CData/*1:0*/ __Vfunc_tb_cpu__DOT__fwd_sel_name__16__sel;
    __Vfunc_tb_cpu__DOT__fwd_sel_name__16__sel = 0;
    std::string __Vfunc_disasm__17__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__17__instr;
    __Vfunc_disasm__17__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__17__opcode;
    __Vfunc_disasm__17__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__17__funct3;
    __Vfunc_disasm__17__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__17__funct7;
    __Vfunc_disasm__17__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__17__rd;
    __Vfunc_disasm__17__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__17__rs1;
    __Vfunc_disasm__17__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__17__rs2;
    __Vfunc_disasm__17__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__17__imm_i;
    __Vfunc_disasm__17__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__17__imm_s;
    __Vfunc_disasm__17__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__17__imm_b;
    __Vfunc_disasm__17__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__17__imm_j;
    __Vfunc_disasm__17__imm_j = 0;
    std::string __Vfunc_disasm__18__Vfuncout;
    IData/*31:0*/ __Vfunc_disasm__18__instr;
    __Vfunc_disasm__18__instr = 0;
    CData/*6:0*/ __Vfunc_disasm__18__opcode;
    __Vfunc_disasm__18__opcode = 0;
    CData/*2:0*/ __Vfunc_disasm__18__funct3;
    __Vfunc_disasm__18__funct3 = 0;
    CData/*6:0*/ __Vfunc_disasm__18__funct7;
    __Vfunc_disasm__18__funct7 = 0;
    CData/*4:0*/ __Vfunc_disasm__18__rd;
    __Vfunc_disasm__18__rd = 0;
    CData/*4:0*/ __Vfunc_disasm__18__rs1;
    __Vfunc_disasm__18__rs1 = 0;
    CData/*4:0*/ __Vfunc_disasm__18__rs2;
    __Vfunc_disasm__18__rs2 = 0;
    IData/*31:0*/ __Vfunc_disasm__18__imm_i;
    __Vfunc_disasm__18__imm_i = 0;
    IData/*31:0*/ __Vfunc_disasm__18__imm_s;
    __Vfunc_disasm__18__imm_s = 0;
    IData/*31:0*/ __Vfunc_disasm__18__imm_b;
    __Vfunc_disasm__18__imm_b = 0;
    IData/*31:0*/ __Vfunc_disasm__18__imm_j;
    __Vfunc_disasm__18__imm_j = 0;
    double __Vfunc_tb_cpu__DOT__calc_cpi__20__Vfuncout;
    __Vfunc_tb_cpu__DOT__calc_cpi__20__Vfuncout = 0;
    double __Vfunc_tb_cpu__DOT__calc_ipc__21__Vfuncout;
    __Vfunc_tb_cpu__DOT__calc_ipc__21__Vfuncout = 0;
    double __Vfunc_tb_cpu__DOT__calc_stall_rate__22__Vfuncout;
    __Vfunc_tb_cpu__DOT__calc_stall_rate__22__Vfuncout = 0;
    double __Vfunc_tb_cpu__DOT__calc_control_redirect_rate__23__Vfuncout;
    __Vfunc_tb_cpu__DOT__calc_control_redirect_rate__23__Vfuncout = 0;
    double __Vfunc_tb_cpu__DOT__calc_memory_instruction_rate__24__Vfuncout;
    __Vfunc_tb_cpu__DOT__calc_memory_instruction_rate__24__Vfuncout = 0;
    double __Vfunc_tb_cpu__DOT__calc_cpi__25__Vfuncout;
    __Vfunc_tb_cpu__DOT__calc_cpi__25__Vfuncout = 0;
    double __Vfunc_tb_cpu__DOT__calc_ipc__26__Vfuncout;
    __Vfunc_tb_cpu__DOT__calc_ipc__26__Vfuncout = 0;
    std::string __Vtemp_1;
    std::string __Vtemp_2;
    std::string __Vtemp_3;
    std::string __Vtemp_4;
    std::string __Vtemp_5;
    std::string __Vtemp_6;
    std::string __Vtemp_7;
    std::string __Vtemp_8;
    std::string __Vtemp_9;
    std::string __Vtemp_10;
    std::string __Vtemp_11;
    std::string __Vtemp_12;
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_cpu__DOT__reset))))) {
        VL_FWRITEF(vlSelf->tb_cpu__DOT__instruction_file,"==================INSTRUCTION TRACE====================\nCycle = %0#\n",
                   32,vlSelf->tb_cpu__DOT__cycle_count);
        __Vtemp_1 = ([&]() {
                __Vfunc_disasm__6__instr = vlSelf->tb_cpu__DOT__uut__DOT__instr;
                {
                    __Vfunc_disasm__6__opcode = (0x7fU 
                                                 & __Vfunc_disasm__6__instr);
                    __Vfunc_disasm__6__funct3 = (7U 
                                                 & (__Vfunc_disasm__6__instr 
                                                    >> 0xcU));
                    __Vfunc_disasm__6__funct7 = (__Vfunc_disasm__6__instr 
                                                 >> 0x19U);
                    __Vfunc_disasm__6__rd = (0x1fU 
                                             & (__Vfunc_disasm__6__instr 
                                                >> 7U));
                    __Vfunc_disasm__6__rs1 = (0x1fU 
                                              & (__Vfunc_disasm__6__instr 
                                                 >> 0xfU));
                    __Vfunc_disasm__6__rs2 = (0x1fU 
                                              & (__Vfunc_disasm__6__instr 
                                                 >> 0x14U));
                    __Vfunc_disasm__6__imm_i = (((- (IData)(
                                                            (__Vfunc_disasm__6__instr 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | (__Vfunc_disasm__6__instr 
                                                   >> 0x14U));
                    __Vfunc_disasm__6__imm_s = (((- (IData)(
                                                            (__Vfunc_disasm__6__instr 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | ((0xfe0U 
                                                    & (__Vfunc_disasm__6__instr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (__Vfunc_disasm__6__instr 
                                                         >> 7U))));
                    __Vfunc_disasm__6__imm_b = (((- (IData)(
                                                            (__Vfunc_disasm__6__instr 
                                                             >> 0x1fU))) 
                                                 << 0xdU) 
                                                | ((0x1000U 
                                                    & (__Vfunc_disasm__6__instr 
                                                       >> 0x13U)) 
                                                   | ((0x800U 
                                                       & (__Vfunc_disasm__6__instr 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (__Vfunc_disasm__6__instr 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (__Vfunc_disasm__6__instr 
                                                               >> 7U))))));
                    __Vfunc_disasm__6__imm_j = (((- (IData)(
                                                            (__Vfunc_disasm__6__instr 
                                                             >> 0x1fU))) 
                                                 << 0x15U) 
                                                | ((0x100000U 
                                                    & (__Vfunc_disasm__6__instr 
                                                       >> 0xbU)) 
                                                   | ((0xff000U 
                                                       & __Vfunc_disasm__6__instr) 
                                                      | ((0x800U 
                                                          & (__Vfunc_disasm__6__instr 
                                                             >> 9U)) 
                                                         | (0x7feU 
                                                            & (__Vfunc_disasm__6__instr 
                                                               >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__6__instr)) {
                        __Vfunc_disasm__6__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel3;
                    }
                    if ((0x13U == __Vfunc_disasm__6__instr)) {
                        __Vfunc_disasm__6__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel3;
                    }
                    if ((0x500013U == __Vfunc_disasm__6__instr)) {
                        __Vfunc_disasm__6__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel3;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__6__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__6__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__6__opcode))) {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__6__instr) ;
                                goto __Vlabel3;
                            } else if ((8U & (IData)(__Vfunc_disasm__6__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__6__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__6__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__6__opcode))) {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__6__rd,
                                                                 32,
                                                                 __Vfunc_disasm__6__imm_j) ;
                                            goto __Vlabel3;
                                        } else {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__6__instr) ;
                                            goto __Vlabel3;
                                        }
                                    } else {
                                        __Vfunc_disasm__6__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__6__instr) ;
                                        goto __Vlabel3;
                                    }
                                } else {
                                    __Vfunc_disasm__6__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__6__instr) ;
                                    goto __Vlabel3;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__6__opcode))) {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__6__instr) ;
                                goto __Vlabel3;
                            } else if ((2U & (IData)(__Vfunc_disasm__6__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__6__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__6__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__6__funct3))) {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__6__instr) ;
                                            goto __Vlabel3;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__6__funct3))) {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__6__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__6__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__6__imm_b) ;
                                            goto __Vlabel3;
                                        } else {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__6__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__6__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__6__imm_b) ;
                                            goto __Vlabel3;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__6__funct3))) {
                                        __Vfunc_disasm__6__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__6__instr) ;
                                        goto __Vlabel3;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__6__funct3))) {
                                        __Vfunc_disasm__6__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__6__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__6__rs2),
                                                             32,
                                                             __Vfunc_disasm__6__imm_b) ;
                                        goto __Vlabel3;
                                    } else {
                                        __Vfunc_disasm__6__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__6__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__6__rs2),
                                                             32,
                                                             __Vfunc_disasm__6__imm_b) ;
                                        goto __Vlabel3;
                                    }
                                } else {
                                    __Vfunc_disasm__6__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__6__instr) ;
                                    goto __Vlabel3;
                                }
                            } else {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__6__instr) ;
                                goto __Vlabel3;
                            }
                        } else {
                            __Vfunc_disasm__6__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__6__instr) ;
                            goto __Vlabel3;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__6__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__6__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__6__opcode))) {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__6__instr) ;
                                goto __Vlabel3;
                            } else if ((4U & (IData)(__Vfunc_disasm__6__opcode))) {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__6__instr) ;
                                goto __Vlabel3;
                            } else if ((2U & (IData)(__Vfunc_disasm__6__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__6__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__6__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__6__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__6__funct3))) {
                                                __Vfunc_disasm__6__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__6__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__6__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__6__rs2) ;
                                                goto __Vlabel3;
                                            } else {
                                                __Vfunc_disasm__6__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__6__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__6__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__6__rs2) ;
                                                goto __Vlabel3;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__6__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__6__funct7))) {
                                                __Vfunc_disasm__6__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__6__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__6__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__6__rs2) ;
                                                goto __Vlabel3;
                                            } else {
                                                __Vfunc_disasm__6__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__6__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__6__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__6__rs2) ;
                                                goto __Vlabel3;
                                            }
                                        } else {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__6__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__6__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__6__rs2) ;
                                            goto __Vlabel3;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__6__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__6__funct3))) {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__6__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__6__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__6__rs2) ;
                                            goto __Vlabel3;
                                        } else {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__6__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__6__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__6__rs2) ;
                                            goto __Vlabel3;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__6__funct3))) {
                                        __Vfunc_disasm__6__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__6__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__6__rs1),
                                                             5,
                                                             __Vfunc_disasm__6__rs2) ;
                                        goto __Vlabel3;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__6__funct7))) {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__6__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__6__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__6__rs2) ;
                                            goto __Vlabel3;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__6__funct7))) {
                                            __Vfunc_disasm__6__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__6__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__6__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__6__rs2) ;
                                            goto __Vlabel3;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__6__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__6__instr) ;
                                    goto __Vlabel3;
                                }
                            } else {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__6__instr) ;
                                goto __Vlabel3;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__6__opcode))) {
                            __Vfunc_disasm__6__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__6__instr) ;
                            goto __Vlabel3;
                        } else if ((4U & (IData)(__Vfunc_disasm__6__opcode))) {
                            __Vfunc_disasm__6__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__6__instr) ;
                            goto __Vlabel3;
                        } else if ((2U & (IData)(__Vfunc_disasm__6__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__6__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__6__funct3))) {
                                    __Vfunc_disasm__6__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__6__rs2,
                                                         32,
                                                         __Vfunc_disasm__6__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__6__rs1)) ;
                                    goto __Vlabel3;
                                } else {
                                    __Vfunc_disasm__6__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__6__instr) ;
                                    goto __Vlabel3;
                                }
                            } else {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__6__instr) ;
                                goto __Vlabel3;
                            }
                        } else {
                            __Vfunc_disasm__6__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__6__instr) ;
                            goto __Vlabel3;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__6__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__6__opcode))) {
                            __Vfunc_disasm__6__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__6__instr) ;
                            goto __Vlabel3;
                        } else if ((4U & (IData)(__Vfunc_disasm__6__opcode))) {
                            __Vfunc_disasm__6__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__6__instr) ;
                            goto __Vlabel3;
                        } else if ((2U & (IData)(__Vfunc_disasm__6__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__6__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__6__funct3))) {
                                    __Vfunc_disasm__6__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__6__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__6__rs1),
                                                         32,
                                                         __Vfunc_disasm__6__imm_i) ;
                                    goto __Vlabel3;
                                } else {
                                    __Vfunc_disasm__6__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__6__instr) ;
                                    goto __Vlabel3;
                                }
                            } else {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__6__instr) ;
                                goto __Vlabel3;
                            }
                        } else {
                            __Vfunc_disasm__6__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__6__instr) ;
                            goto __Vlabel3;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__6__opcode))) {
                        __Vfunc_disasm__6__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__6__instr) ;
                        goto __Vlabel3;
                    } else if ((4U & (IData)(__Vfunc_disasm__6__opcode))) {
                        __Vfunc_disasm__6__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__6__instr) ;
                        goto __Vlabel3;
                    } else if ((2U & (IData)(__Vfunc_disasm__6__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__6__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__6__funct3))) {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__6__rd,
                                                     32,
                                                     __Vfunc_disasm__6__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__6__rs1)) ;
                                goto __Vlabel3;
                            } else {
                                __Vfunc_disasm__6__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__6__instr) ;
                                goto __Vlabel3;
                            }
                        } else {
                            __Vfunc_disasm__6__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__6__instr) ;
                            goto __Vlabel3;
                        }
                    } else {
                        __Vfunc_disasm__6__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__6__instr) ;
                        goto __Vlabel3;
                    }
                    __Vlabel3: ;
                }
            }(), __Vfunc_disasm__6__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__instruction_file," IF : %@ \n",
                   -1,&(__Vtemp_1));
        __Vtemp_2 = ([&]() {
                __Vfunc_disasm__7__instr = vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr;
                {
                    __Vfunc_disasm__7__opcode = (0x7fU 
                                                 & __Vfunc_disasm__7__instr);
                    __Vfunc_disasm__7__funct3 = (7U 
                                                 & (__Vfunc_disasm__7__instr 
                                                    >> 0xcU));
                    __Vfunc_disasm__7__funct7 = (__Vfunc_disasm__7__instr 
                                                 >> 0x19U);
                    __Vfunc_disasm__7__rd = (0x1fU 
                                             & (__Vfunc_disasm__7__instr 
                                                >> 7U));
                    __Vfunc_disasm__7__rs1 = (0x1fU 
                                              & (__Vfunc_disasm__7__instr 
                                                 >> 0xfU));
                    __Vfunc_disasm__7__rs2 = (0x1fU 
                                              & (__Vfunc_disasm__7__instr 
                                                 >> 0x14U));
                    __Vfunc_disasm__7__imm_i = (((- (IData)(
                                                            (__Vfunc_disasm__7__instr 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | (__Vfunc_disasm__7__instr 
                                                   >> 0x14U));
                    __Vfunc_disasm__7__imm_s = (((- (IData)(
                                                            (__Vfunc_disasm__7__instr 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | ((0xfe0U 
                                                    & (__Vfunc_disasm__7__instr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (__Vfunc_disasm__7__instr 
                                                         >> 7U))));
                    __Vfunc_disasm__7__imm_b = (((- (IData)(
                                                            (__Vfunc_disasm__7__instr 
                                                             >> 0x1fU))) 
                                                 << 0xdU) 
                                                | ((0x1000U 
                                                    & (__Vfunc_disasm__7__instr 
                                                       >> 0x13U)) 
                                                   | ((0x800U 
                                                       & (__Vfunc_disasm__7__instr 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (__Vfunc_disasm__7__instr 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (__Vfunc_disasm__7__instr 
                                                               >> 7U))))));
                    __Vfunc_disasm__7__imm_j = (((- (IData)(
                                                            (__Vfunc_disasm__7__instr 
                                                             >> 0x1fU))) 
                                                 << 0x15U) 
                                                | ((0x100000U 
                                                    & (__Vfunc_disasm__7__instr 
                                                       >> 0xbU)) 
                                                   | ((0xff000U 
                                                       & __Vfunc_disasm__7__instr) 
                                                      | ((0x800U 
                                                          & (__Vfunc_disasm__7__instr 
                                                             >> 9U)) 
                                                         | (0x7feU 
                                                            & (__Vfunc_disasm__7__instr 
                                                               >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__7__instr)) {
                        __Vfunc_disasm__7__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel4;
                    }
                    if ((0x13U == __Vfunc_disasm__7__instr)) {
                        __Vfunc_disasm__7__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel4;
                    }
                    if ((0x500013U == __Vfunc_disasm__7__instr)) {
                        __Vfunc_disasm__7__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel4;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__7__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__7__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__7__opcode))) {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__7__instr) ;
                                goto __Vlabel4;
                            } else if ((8U & (IData)(__Vfunc_disasm__7__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__7__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__7__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__7__opcode))) {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__7__rd,
                                                                 32,
                                                                 __Vfunc_disasm__7__imm_j) ;
                                            goto __Vlabel4;
                                        } else {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__7__instr) ;
                                            goto __Vlabel4;
                                        }
                                    } else {
                                        __Vfunc_disasm__7__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__7__instr) ;
                                        goto __Vlabel4;
                                    }
                                } else {
                                    __Vfunc_disasm__7__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__7__instr) ;
                                    goto __Vlabel4;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__7__opcode))) {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__7__instr) ;
                                goto __Vlabel4;
                            } else if ((2U & (IData)(__Vfunc_disasm__7__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__7__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__7__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__7__funct3))) {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__7__instr) ;
                                            goto __Vlabel4;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__7__funct3))) {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__7__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__7__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__7__imm_b) ;
                                            goto __Vlabel4;
                                        } else {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__7__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__7__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__7__imm_b) ;
                                            goto __Vlabel4;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__7__funct3))) {
                                        __Vfunc_disasm__7__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__7__instr) ;
                                        goto __Vlabel4;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__7__funct3))) {
                                        __Vfunc_disasm__7__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__7__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__7__rs2),
                                                             32,
                                                             __Vfunc_disasm__7__imm_b) ;
                                        goto __Vlabel4;
                                    } else {
                                        __Vfunc_disasm__7__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__7__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__7__rs2),
                                                             32,
                                                             __Vfunc_disasm__7__imm_b) ;
                                        goto __Vlabel4;
                                    }
                                } else {
                                    __Vfunc_disasm__7__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__7__instr) ;
                                    goto __Vlabel4;
                                }
                            } else {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__7__instr) ;
                                goto __Vlabel4;
                            }
                        } else {
                            __Vfunc_disasm__7__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__7__instr) ;
                            goto __Vlabel4;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__7__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__7__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__7__opcode))) {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__7__instr) ;
                                goto __Vlabel4;
                            } else if ((4U & (IData)(__Vfunc_disasm__7__opcode))) {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__7__instr) ;
                                goto __Vlabel4;
                            } else if ((2U & (IData)(__Vfunc_disasm__7__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__7__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__7__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__7__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__7__funct3))) {
                                                __Vfunc_disasm__7__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__7__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__7__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__7__rs2) ;
                                                goto __Vlabel4;
                                            } else {
                                                __Vfunc_disasm__7__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__7__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__7__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__7__rs2) ;
                                                goto __Vlabel4;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__7__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__7__funct7))) {
                                                __Vfunc_disasm__7__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__7__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__7__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__7__rs2) ;
                                                goto __Vlabel4;
                                            } else {
                                                __Vfunc_disasm__7__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__7__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__7__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__7__rs2) ;
                                                goto __Vlabel4;
                                            }
                                        } else {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__7__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__7__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__7__rs2) ;
                                            goto __Vlabel4;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__7__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__7__funct3))) {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__7__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__7__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__7__rs2) ;
                                            goto __Vlabel4;
                                        } else {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__7__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__7__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__7__rs2) ;
                                            goto __Vlabel4;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__7__funct3))) {
                                        __Vfunc_disasm__7__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__7__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__7__rs1),
                                                             5,
                                                             __Vfunc_disasm__7__rs2) ;
                                        goto __Vlabel4;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__7__funct7))) {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__7__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__7__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__7__rs2) ;
                                            goto __Vlabel4;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__7__funct7))) {
                                            __Vfunc_disasm__7__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__7__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__7__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__7__rs2) ;
                                            goto __Vlabel4;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__7__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__7__instr) ;
                                    goto __Vlabel4;
                                }
                            } else {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__7__instr) ;
                                goto __Vlabel4;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__7__opcode))) {
                            __Vfunc_disasm__7__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__7__instr) ;
                            goto __Vlabel4;
                        } else if ((4U & (IData)(__Vfunc_disasm__7__opcode))) {
                            __Vfunc_disasm__7__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__7__instr) ;
                            goto __Vlabel4;
                        } else if ((2U & (IData)(__Vfunc_disasm__7__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__7__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__7__funct3))) {
                                    __Vfunc_disasm__7__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__7__rs2,
                                                         32,
                                                         __Vfunc_disasm__7__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__7__rs1)) ;
                                    goto __Vlabel4;
                                } else {
                                    __Vfunc_disasm__7__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__7__instr) ;
                                    goto __Vlabel4;
                                }
                            } else {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__7__instr) ;
                                goto __Vlabel4;
                            }
                        } else {
                            __Vfunc_disasm__7__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__7__instr) ;
                            goto __Vlabel4;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__7__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__7__opcode))) {
                            __Vfunc_disasm__7__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__7__instr) ;
                            goto __Vlabel4;
                        } else if ((4U & (IData)(__Vfunc_disasm__7__opcode))) {
                            __Vfunc_disasm__7__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__7__instr) ;
                            goto __Vlabel4;
                        } else if ((2U & (IData)(__Vfunc_disasm__7__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__7__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__7__funct3))) {
                                    __Vfunc_disasm__7__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__7__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__7__rs1),
                                                         32,
                                                         __Vfunc_disasm__7__imm_i) ;
                                    goto __Vlabel4;
                                } else {
                                    __Vfunc_disasm__7__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__7__instr) ;
                                    goto __Vlabel4;
                                }
                            } else {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__7__instr) ;
                                goto __Vlabel4;
                            }
                        } else {
                            __Vfunc_disasm__7__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__7__instr) ;
                            goto __Vlabel4;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__7__opcode))) {
                        __Vfunc_disasm__7__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__7__instr) ;
                        goto __Vlabel4;
                    } else if ((4U & (IData)(__Vfunc_disasm__7__opcode))) {
                        __Vfunc_disasm__7__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__7__instr) ;
                        goto __Vlabel4;
                    } else if ((2U & (IData)(__Vfunc_disasm__7__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__7__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__7__funct3))) {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__7__rd,
                                                     32,
                                                     __Vfunc_disasm__7__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__7__rs1)) ;
                                goto __Vlabel4;
                            } else {
                                __Vfunc_disasm__7__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__7__instr) ;
                                goto __Vlabel4;
                            }
                        } else {
                            __Vfunc_disasm__7__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__7__instr) ;
                            goto __Vlabel4;
                        }
                    } else {
                        __Vfunc_disasm__7__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__7__instr) ;
                        goto __Vlabel4;
                    }
                    __Vlabel4: ;
                }
            }(), __Vfunc_disasm__7__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__instruction_file," ID : %@ \n",
                   -1,&(__Vtemp_2));
        __Vtemp_3 = ([&]() {
                __Vfunc_disasm__8__instr = vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr;
                {
                    __Vfunc_disasm__8__opcode = (0x7fU 
                                                 & __Vfunc_disasm__8__instr);
                    __Vfunc_disasm__8__funct3 = (7U 
                                                 & (__Vfunc_disasm__8__instr 
                                                    >> 0xcU));
                    __Vfunc_disasm__8__funct7 = (__Vfunc_disasm__8__instr 
                                                 >> 0x19U);
                    __Vfunc_disasm__8__rd = (0x1fU 
                                             & (__Vfunc_disasm__8__instr 
                                                >> 7U));
                    __Vfunc_disasm__8__rs1 = (0x1fU 
                                              & (__Vfunc_disasm__8__instr 
                                                 >> 0xfU));
                    __Vfunc_disasm__8__rs2 = (0x1fU 
                                              & (__Vfunc_disasm__8__instr 
                                                 >> 0x14U));
                    __Vfunc_disasm__8__imm_i = (((- (IData)(
                                                            (__Vfunc_disasm__8__instr 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | (__Vfunc_disasm__8__instr 
                                                   >> 0x14U));
                    __Vfunc_disasm__8__imm_s = (((- (IData)(
                                                            (__Vfunc_disasm__8__instr 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | ((0xfe0U 
                                                    & (__Vfunc_disasm__8__instr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (__Vfunc_disasm__8__instr 
                                                         >> 7U))));
                    __Vfunc_disasm__8__imm_b = (((- (IData)(
                                                            (__Vfunc_disasm__8__instr 
                                                             >> 0x1fU))) 
                                                 << 0xdU) 
                                                | ((0x1000U 
                                                    & (__Vfunc_disasm__8__instr 
                                                       >> 0x13U)) 
                                                   | ((0x800U 
                                                       & (__Vfunc_disasm__8__instr 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (__Vfunc_disasm__8__instr 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (__Vfunc_disasm__8__instr 
                                                               >> 7U))))));
                    __Vfunc_disasm__8__imm_j = (((- (IData)(
                                                            (__Vfunc_disasm__8__instr 
                                                             >> 0x1fU))) 
                                                 << 0x15U) 
                                                | ((0x100000U 
                                                    & (__Vfunc_disasm__8__instr 
                                                       >> 0xbU)) 
                                                   | ((0xff000U 
                                                       & __Vfunc_disasm__8__instr) 
                                                      | ((0x800U 
                                                          & (__Vfunc_disasm__8__instr 
                                                             >> 9U)) 
                                                         | (0x7feU 
                                                            & (__Vfunc_disasm__8__instr 
                                                               >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__8__instr)) {
                        __Vfunc_disasm__8__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel5;
                    }
                    if ((0x13U == __Vfunc_disasm__8__instr)) {
                        __Vfunc_disasm__8__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel5;
                    }
                    if ((0x500013U == __Vfunc_disasm__8__instr)) {
                        __Vfunc_disasm__8__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel5;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__8__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__8__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__8__opcode))) {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__8__instr) ;
                                goto __Vlabel5;
                            } else if ((8U & (IData)(__Vfunc_disasm__8__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__8__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__8__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__8__opcode))) {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__8__rd,
                                                                 32,
                                                                 __Vfunc_disasm__8__imm_j) ;
                                            goto __Vlabel5;
                                        } else {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__8__instr) ;
                                            goto __Vlabel5;
                                        }
                                    } else {
                                        __Vfunc_disasm__8__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__8__instr) ;
                                        goto __Vlabel5;
                                    }
                                } else {
                                    __Vfunc_disasm__8__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__8__instr) ;
                                    goto __Vlabel5;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__8__opcode))) {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__8__instr) ;
                                goto __Vlabel5;
                            } else if ((2U & (IData)(__Vfunc_disasm__8__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__8__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__8__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__8__funct3))) {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__8__instr) ;
                                            goto __Vlabel5;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__8__funct3))) {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__8__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__8__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__8__imm_b) ;
                                            goto __Vlabel5;
                                        } else {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__8__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__8__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__8__imm_b) ;
                                            goto __Vlabel5;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__8__funct3))) {
                                        __Vfunc_disasm__8__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__8__instr) ;
                                        goto __Vlabel5;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__8__funct3))) {
                                        __Vfunc_disasm__8__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__8__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__8__rs2),
                                                             32,
                                                             __Vfunc_disasm__8__imm_b) ;
                                        goto __Vlabel5;
                                    } else {
                                        __Vfunc_disasm__8__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__8__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__8__rs2),
                                                             32,
                                                             __Vfunc_disasm__8__imm_b) ;
                                        goto __Vlabel5;
                                    }
                                } else {
                                    __Vfunc_disasm__8__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__8__instr) ;
                                    goto __Vlabel5;
                                }
                            } else {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__8__instr) ;
                                goto __Vlabel5;
                            }
                        } else {
                            __Vfunc_disasm__8__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__8__instr) ;
                            goto __Vlabel5;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__8__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__8__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__8__opcode))) {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__8__instr) ;
                                goto __Vlabel5;
                            } else if ((4U & (IData)(__Vfunc_disasm__8__opcode))) {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__8__instr) ;
                                goto __Vlabel5;
                            } else if ((2U & (IData)(__Vfunc_disasm__8__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__8__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__8__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__8__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__8__funct3))) {
                                                __Vfunc_disasm__8__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__8__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__8__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__8__rs2) ;
                                                goto __Vlabel5;
                                            } else {
                                                __Vfunc_disasm__8__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__8__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__8__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__8__rs2) ;
                                                goto __Vlabel5;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__8__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__8__funct7))) {
                                                __Vfunc_disasm__8__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__8__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__8__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__8__rs2) ;
                                                goto __Vlabel5;
                                            } else {
                                                __Vfunc_disasm__8__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__8__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__8__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__8__rs2) ;
                                                goto __Vlabel5;
                                            }
                                        } else {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__8__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__8__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__8__rs2) ;
                                            goto __Vlabel5;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__8__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__8__funct3))) {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__8__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__8__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__8__rs2) ;
                                            goto __Vlabel5;
                                        } else {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__8__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__8__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__8__rs2) ;
                                            goto __Vlabel5;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__8__funct3))) {
                                        __Vfunc_disasm__8__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__8__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__8__rs1),
                                                             5,
                                                             __Vfunc_disasm__8__rs2) ;
                                        goto __Vlabel5;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__8__funct7))) {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__8__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__8__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__8__rs2) ;
                                            goto __Vlabel5;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__8__funct7))) {
                                            __Vfunc_disasm__8__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__8__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__8__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__8__rs2) ;
                                            goto __Vlabel5;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__8__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__8__instr) ;
                                    goto __Vlabel5;
                                }
                            } else {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__8__instr) ;
                                goto __Vlabel5;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__8__opcode))) {
                            __Vfunc_disasm__8__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__8__instr) ;
                            goto __Vlabel5;
                        } else if ((4U & (IData)(__Vfunc_disasm__8__opcode))) {
                            __Vfunc_disasm__8__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__8__instr) ;
                            goto __Vlabel5;
                        } else if ((2U & (IData)(__Vfunc_disasm__8__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__8__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__8__funct3))) {
                                    __Vfunc_disasm__8__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__8__rs2,
                                                         32,
                                                         __Vfunc_disasm__8__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__8__rs1)) ;
                                    goto __Vlabel5;
                                } else {
                                    __Vfunc_disasm__8__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__8__instr) ;
                                    goto __Vlabel5;
                                }
                            } else {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__8__instr) ;
                                goto __Vlabel5;
                            }
                        } else {
                            __Vfunc_disasm__8__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__8__instr) ;
                            goto __Vlabel5;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__8__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__8__opcode))) {
                            __Vfunc_disasm__8__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__8__instr) ;
                            goto __Vlabel5;
                        } else if ((4U & (IData)(__Vfunc_disasm__8__opcode))) {
                            __Vfunc_disasm__8__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__8__instr) ;
                            goto __Vlabel5;
                        } else if ((2U & (IData)(__Vfunc_disasm__8__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__8__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__8__funct3))) {
                                    __Vfunc_disasm__8__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__8__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__8__rs1),
                                                         32,
                                                         __Vfunc_disasm__8__imm_i) ;
                                    goto __Vlabel5;
                                } else {
                                    __Vfunc_disasm__8__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__8__instr) ;
                                    goto __Vlabel5;
                                }
                            } else {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__8__instr) ;
                                goto __Vlabel5;
                            }
                        } else {
                            __Vfunc_disasm__8__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__8__instr) ;
                            goto __Vlabel5;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__8__opcode))) {
                        __Vfunc_disasm__8__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__8__instr) ;
                        goto __Vlabel5;
                    } else if ((4U & (IData)(__Vfunc_disasm__8__opcode))) {
                        __Vfunc_disasm__8__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__8__instr) ;
                        goto __Vlabel5;
                    } else if ((2U & (IData)(__Vfunc_disasm__8__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__8__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__8__funct3))) {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__8__rd,
                                                     32,
                                                     __Vfunc_disasm__8__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__8__rs1)) ;
                                goto __Vlabel5;
                            } else {
                                __Vfunc_disasm__8__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__8__instr) ;
                                goto __Vlabel5;
                            }
                        } else {
                            __Vfunc_disasm__8__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__8__instr) ;
                            goto __Vlabel5;
                        }
                    } else {
                        __Vfunc_disasm__8__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__8__instr) ;
                        goto __Vlabel5;
                    }
                    __Vlabel5: ;
                }
            }(), __Vfunc_disasm__8__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__instruction_file," EX : %@ \n",
                   -1,&(__Vtemp_3));
        __Vtemp_4 = ([&]() {
                __Vfunc_disasm__9__instr = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_instr;
                {
                    __Vfunc_disasm__9__opcode = (0x7fU 
                                                 & __Vfunc_disasm__9__instr);
                    __Vfunc_disasm__9__funct3 = (7U 
                                                 & (__Vfunc_disasm__9__instr 
                                                    >> 0xcU));
                    __Vfunc_disasm__9__funct7 = (__Vfunc_disasm__9__instr 
                                                 >> 0x19U);
                    __Vfunc_disasm__9__rd = (0x1fU 
                                             & (__Vfunc_disasm__9__instr 
                                                >> 7U));
                    __Vfunc_disasm__9__rs1 = (0x1fU 
                                              & (__Vfunc_disasm__9__instr 
                                                 >> 0xfU));
                    __Vfunc_disasm__9__rs2 = (0x1fU 
                                              & (__Vfunc_disasm__9__instr 
                                                 >> 0x14U));
                    __Vfunc_disasm__9__imm_i = (((- (IData)(
                                                            (__Vfunc_disasm__9__instr 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | (__Vfunc_disasm__9__instr 
                                                   >> 0x14U));
                    __Vfunc_disasm__9__imm_s = (((- (IData)(
                                                            (__Vfunc_disasm__9__instr 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | ((0xfe0U 
                                                    & (__Vfunc_disasm__9__instr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (__Vfunc_disasm__9__instr 
                                                         >> 7U))));
                    __Vfunc_disasm__9__imm_b = (((- (IData)(
                                                            (__Vfunc_disasm__9__instr 
                                                             >> 0x1fU))) 
                                                 << 0xdU) 
                                                | ((0x1000U 
                                                    & (__Vfunc_disasm__9__instr 
                                                       >> 0x13U)) 
                                                   | ((0x800U 
                                                       & (__Vfunc_disasm__9__instr 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (__Vfunc_disasm__9__instr 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (__Vfunc_disasm__9__instr 
                                                               >> 7U))))));
                    __Vfunc_disasm__9__imm_j = (((- (IData)(
                                                            (__Vfunc_disasm__9__instr 
                                                             >> 0x1fU))) 
                                                 << 0x15U) 
                                                | ((0x100000U 
                                                    & (__Vfunc_disasm__9__instr 
                                                       >> 0xbU)) 
                                                   | ((0xff000U 
                                                       & __Vfunc_disasm__9__instr) 
                                                      | ((0x800U 
                                                          & (__Vfunc_disasm__9__instr 
                                                             >> 9U)) 
                                                         | (0x7feU 
                                                            & (__Vfunc_disasm__9__instr 
                                                               >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__9__instr)) {
                        __Vfunc_disasm__9__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel6;
                    }
                    if ((0x13U == __Vfunc_disasm__9__instr)) {
                        __Vfunc_disasm__9__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel6;
                    }
                    if ((0x500013U == __Vfunc_disasm__9__instr)) {
                        __Vfunc_disasm__9__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel6;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__9__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__9__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__9__opcode))) {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__9__instr) ;
                                goto __Vlabel6;
                            } else if ((8U & (IData)(__Vfunc_disasm__9__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__9__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__9__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__9__opcode))) {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__9__rd,
                                                                 32,
                                                                 __Vfunc_disasm__9__imm_j) ;
                                            goto __Vlabel6;
                                        } else {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__9__instr) ;
                                            goto __Vlabel6;
                                        }
                                    } else {
                                        __Vfunc_disasm__9__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__9__instr) ;
                                        goto __Vlabel6;
                                    }
                                } else {
                                    __Vfunc_disasm__9__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__9__instr) ;
                                    goto __Vlabel6;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__9__opcode))) {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__9__instr) ;
                                goto __Vlabel6;
                            } else if ((2U & (IData)(__Vfunc_disasm__9__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__9__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__9__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__9__funct3))) {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__9__instr) ;
                                            goto __Vlabel6;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__9__funct3))) {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__9__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__9__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__9__imm_b) ;
                                            goto __Vlabel6;
                                        } else {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__9__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__9__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__9__imm_b) ;
                                            goto __Vlabel6;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__9__funct3))) {
                                        __Vfunc_disasm__9__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__9__instr) ;
                                        goto __Vlabel6;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__9__funct3))) {
                                        __Vfunc_disasm__9__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__9__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__9__rs2),
                                                             32,
                                                             __Vfunc_disasm__9__imm_b) ;
                                        goto __Vlabel6;
                                    } else {
                                        __Vfunc_disasm__9__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__9__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__9__rs2),
                                                             32,
                                                             __Vfunc_disasm__9__imm_b) ;
                                        goto __Vlabel6;
                                    }
                                } else {
                                    __Vfunc_disasm__9__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__9__instr) ;
                                    goto __Vlabel6;
                                }
                            } else {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__9__instr) ;
                                goto __Vlabel6;
                            }
                        } else {
                            __Vfunc_disasm__9__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__9__instr) ;
                            goto __Vlabel6;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__9__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__9__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__9__opcode))) {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__9__instr) ;
                                goto __Vlabel6;
                            } else if ((4U & (IData)(__Vfunc_disasm__9__opcode))) {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__9__instr) ;
                                goto __Vlabel6;
                            } else if ((2U & (IData)(__Vfunc_disasm__9__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__9__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__9__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__9__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__9__funct3))) {
                                                __Vfunc_disasm__9__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__9__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__9__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__9__rs2) ;
                                                goto __Vlabel6;
                                            } else {
                                                __Vfunc_disasm__9__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__9__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__9__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__9__rs2) ;
                                                goto __Vlabel6;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__9__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__9__funct7))) {
                                                __Vfunc_disasm__9__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__9__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__9__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__9__rs2) ;
                                                goto __Vlabel6;
                                            } else {
                                                __Vfunc_disasm__9__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__9__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__9__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__9__rs2) ;
                                                goto __Vlabel6;
                                            }
                                        } else {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__9__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__9__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__9__rs2) ;
                                            goto __Vlabel6;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__9__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__9__funct3))) {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__9__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__9__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__9__rs2) ;
                                            goto __Vlabel6;
                                        } else {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__9__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__9__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__9__rs2) ;
                                            goto __Vlabel6;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__9__funct3))) {
                                        __Vfunc_disasm__9__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__9__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__9__rs1),
                                                             5,
                                                             __Vfunc_disasm__9__rs2) ;
                                        goto __Vlabel6;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__9__funct7))) {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__9__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__9__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__9__rs2) ;
                                            goto __Vlabel6;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__9__funct7))) {
                                            __Vfunc_disasm__9__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__9__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__9__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__9__rs2) ;
                                            goto __Vlabel6;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__9__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__9__instr) ;
                                    goto __Vlabel6;
                                }
                            } else {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__9__instr) ;
                                goto __Vlabel6;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__9__opcode))) {
                            __Vfunc_disasm__9__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__9__instr) ;
                            goto __Vlabel6;
                        } else if ((4U & (IData)(__Vfunc_disasm__9__opcode))) {
                            __Vfunc_disasm__9__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__9__instr) ;
                            goto __Vlabel6;
                        } else if ((2U & (IData)(__Vfunc_disasm__9__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__9__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__9__funct3))) {
                                    __Vfunc_disasm__9__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__9__rs2,
                                                         32,
                                                         __Vfunc_disasm__9__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__9__rs1)) ;
                                    goto __Vlabel6;
                                } else {
                                    __Vfunc_disasm__9__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__9__instr) ;
                                    goto __Vlabel6;
                                }
                            } else {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__9__instr) ;
                                goto __Vlabel6;
                            }
                        } else {
                            __Vfunc_disasm__9__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__9__instr) ;
                            goto __Vlabel6;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__9__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__9__opcode))) {
                            __Vfunc_disasm__9__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__9__instr) ;
                            goto __Vlabel6;
                        } else if ((4U & (IData)(__Vfunc_disasm__9__opcode))) {
                            __Vfunc_disasm__9__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__9__instr) ;
                            goto __Vlabel6;
                        } else if ((2U & (IData)(__Vfunc_disasm__9__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__9__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__9__funct3))) {
                                    __Vfunc_disasm__9__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__9__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__9__rs1),
                                                         32,
                                                         __Vfunc_disasm__9__imm_i) ;
                                    goto __Vlabel6;
                                } else {
                                    __Vfunc_disasm__9__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__9__instr) ;
                                    goto __Vlabel6;
                                }
                            } else {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__9__instr) ;
                                goto __Vlabel6;
                            }
                        } else {
                            __Vfunc_disasm__9__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__9__instr) ;
                            goto __Vlabel6;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__9__opcode))) {
                        __Vfunc_disasm__9__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__9__instr) ;
                        goto __Vlabel6;
                    } else if ((4U & (IData)(__Vfunc_disasm__9__opcode))) {
                        __Vfunc_disasm__9__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__9__instr) ;
                        goto __Vlabel6;
                    } else if ((2U & (IData)(__Vfunc_disasm__9__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__9__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__9__funct3))) {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__9__rd,
                                                     32,
                                                     __Vfunc_disasm__9__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__9__rs1)) ;
                                goto __Vlabel6;
                            } else {
                                __Vfunc_disasm__9__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__9__instr) ;
                                goto __Vlabel6;
                            }
                        } else {
                            __Vfunc_disasm__9__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__9__instr) ;
                            goto __Vlabel6;
                        }
                    } else {
                        __Vfunc_disasm__9__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__9__instr) ;
                        goto __Vlabel6;
                    }
                    __Vlabel6: ;
                }
            }(), __Vfunc_disasm__9__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__instruction_file," MEM: %@ \n",
                   -1,&(__Vtemp_4));
        __Vtemp_5 = ([&]() {
                __Vfunc_disasm__10__instr = vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr;
                {
                    __Vfunc_disasm__10__opcode = (0x7fU 
                                                  & __Vfunc_disasm__10__instr);
                    __Vfunc_disasm__10__funct3 = (7U 
                                                  & (__Vfunc_disasm__10__instr 
                                                     >> 0xcU));
                    __Vfunc_disasm__10__funct7 = (__Vfunc_disasm__10__instr 
                                                  >> 0x19U);
                    __Vfunc_disasm__10__rd = (0x1fU 
                                              & (__Vfunc_disasm__10__instr 
                                                 >> 7U));
                    __Vfunc_disasm__10__rs1 = (0x1fU 
                                               & (__Vfunc_disasm__10__instr 
                                                  >> 0xfU));
                    __Vfunc_disasm__10__rs2 = (0x1fU 
                                               & (__Vfunc_disasm__10__instr 
                                                  >> 0x14U));
                    __Vfunc_disasm__10__imm_i = (((- (IData)(
                                                             (__Vfunc_disasm__10__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (__Vfunc_disasm__10__instr 
                                                    >> 0x14U));
                    __Vfunc_disasm__10__imm_s = (((- (IData)(
                                                             (__Vfunc_disasm__10__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (__Vfunc_disasm__10__instr 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (__Vfunc_disasm__10__instr 
                                                          >> 7U))));
                    __Vfunc_disasm__10__imm_b = (((- (IData)(
                                                             (__Vfunc_disasm__10__instr 
                                                              >> 0x1fU))) 
                                                  << 0xdU) 
                                                 | ((0x1000U 
                                                     & (__Vfunc_disasm__10__instr 
                                                        >> 0x13U)) 
                                                    | ((0x800U 
                                                        & (__Vfunc_disasm__10__instr 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (__Vfunc_disasm__10__instr 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (__Vfunc_disasm__10__instr 
                                                                >> 7U))))));
                    __Vfunc_disasm__10__imm_j = (((- (IData)(
                                                             (__Vfunc_disasm__10__instr 
                                                              >> 0x1fU))) 
                                                  << 0x15U) 
                                                 | ((0x100000U 
                                                     & (__Vfunc_disasm__10__instr 
                                                        >> 0xbU)) 
                                                    | ((0xff000U 
                                                        & __Vfunc_disasm__10__instr) 
                                                       | ((0x800U 
                                                           & (__Vfunc_disasm__10__instr 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (__Vfunc_disasm__10__instr 
                                                                >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__10__instr)) {
                        __Vfunc_disasm__10__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel7;
                    }
                    if ((0x13U == __Vfunc_disasm__10__instr)) {
                        __Vfunc_disasm__10__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel7;
                    }
                    if ((0x500013U == __Vfunc_disasm__10__instr)) {
                        __Vfunc_disasm__10__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel7;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__10__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__10__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__10__opcode))) {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__10__instr) ;
                                goto __Vlabel7;
                            } else if ((8U & (IData)(__Vfunc_disasm__10__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__10__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__10__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__10__opcode))) {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__10__rd,
                                                                 32,
                                                                 __Vfunc_disasm__10__imm_j) ;
                                            goto __Vlabel7;
                                        } else {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__10__instr) ;
                                            goto __Vlabel7;
                                        }
                                    } else {
                                        __Vfunc_disasm__10__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__10__instr) ;
                                        goto __Vlabel7;
                                    }
                                } else {
                                    __Vfunc_disasm__10__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__10__instr) ;
                                    goto __Vlabel7;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__10__opcode))) {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__10__instr) ;
                                goto __Vlabel7;
                            } else if ((2U & (IData)(__Vfunc_disasm__10__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__10__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__10__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__10__funct3))) {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__10__instr) ;
                                            goto __Vlabel7;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__10__funct3))) {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__10__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__10__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__10__imm_b) ;
                                            goto __Vlabel7;
                                        } else {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__10__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__10__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__10__imm_b) ;
                                            goto __Vlabel7;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__10__funct3))) {
                                        __Vfunc_disasm__10__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__10__instr) ;
                                        goto __Vlabel7;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__10__funct3))) {
                                        __Vfunc_disasm__10__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__10__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__10__rs2),
                                                             32,
                                                             __Vfunc_disasm__10__imm_b) ;
                                        goto __Vlabel7;
                                    } else {
                                        __Vfunc_disasm__10__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__10__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__10__rs2),
                                                             32,
                                                             __Vfunc_disasm__10__imm_b) ;
                                        goto __Vlabel7;
                                    }
                                } else {
                                    __Vfunc_disasm__10__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__10__instr) ;
                                    goto __Vlabel7;
                                }
                            } else {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__10__instr) ;
                                goto __Vlabel7;
                            }
                        } else {
                            __Vfunc_disasm__10__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__10__instr) ;
                            goto __Vlabel7;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__10__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__10__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__10__opcode))) {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__10__instr) ;
                                goto __Vlabel7;
                            } else if ((4U & (IData)(__Vfunc_disasm__10__opcode))) {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__10__instr) ;
                                goto __Vlabel7;
                            } else if ((2U & (IData)(__Vfunc_disasm__10__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__10__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__10__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__10__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__10__funct3))) {
                                                __Vfunc_disasm__10__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__10__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__10__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__10__rs2) ;
                                                goto __Vlabel7;
                                            } else {
                                                __Vfunc_disasm__10__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__10__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__10__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__10__rs2) ;
                                                goto __Vlabel7;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__10__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__10__funct7))) {
                                                __Vfunc_disasm__10__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__10__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__10__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__10__rs2) ;
                                                goto __Vlabel7;
                                            } else {
                                                __Vfunc_disasm__10__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__10__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__10__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__10__rs2) ;
                                                goto __Vlabel7;
                                            }
                                        } else {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__10__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__10__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__10__rs2) ;
                                            goto __Vlabel7;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__10__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__10__funct3))) {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__10__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__10__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__10__rs2) ;
                                            goto __Vlabel7;
                                        } else {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__10__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__10__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__10__rs2) ;
                                            goto __Vlabel7;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__10__funct3))) {
                                        __Vfunc_disasm__10__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__10__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__10__rs1),
                                                             5,
                                                             __Vfunc_disasm__10__rs2) ;
                                        goto __Vlabel7;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__10__funct7))) {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__10__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__10__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__10__rs2) ;
                                            goto __Vlabel7;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__10__funct7))) {
                                            __Vfunc_disasm__10__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__10__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__10__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__10__rs2) ;
                                            goto __Vlabel7;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__10__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__10__instr) ;
                                    goto __Vlabel7;
                                }
                            } else {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__10__instr) ;
                                goto __Vlabel7;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__10__opcode))) {
                            __Vfunc_disasm__10__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__10__instr) ;
                            goto __Vlabel7;
                        } else if ((4U & (IData)(__Vfunc_disasm__10__opcode))) {
                            __Vfunc_disasm__10__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__10__instr) ;
                            goto __Vlabel7;
                        } else if ((2U & (IData)(__Vfunc_disasm__10__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__10__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__10__funct3))) {
                                    __Vfunc_disasm__10__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__10__rs2,
                                                         32,
                                                         __Vfunc_disasm__10__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__10__rs1)) ;
                                    goto __Vlabel7;
                                } else {
                                    __Vfunc_disasm__10__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__10__instr) ;
                                    goto __Vlabel7;
                                }
                            } else {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__10__instr) ;
                                goto __Vlabel7;
                            }
                        } else {
                            __Vfunc_disasm__10__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__10__instr) ;
                            goto __Vlabel7;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__10__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__10__opcode))) {
                            __Vfunc_disasm__10__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__10__instr) ;
                            goto __Vlabel7;
                        } else if ((4U & (IData)(__Vfunc_disasm__10__opcode))) {
                            __Vfunc_disasm__10__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__10__instr) ;
                            goto __Vlabel7;
                        } else if ((2U & (IData)(__Vfunc_disasm__10__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__10__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__10__funct3))) {
                                    __Vfunc_disasm__10__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__10__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__10__rs1),
                                                         32,
                                                         __Vfunc_disasm__10__imm_i) ;
                                    goto __Vlabel7;
                                } else {
                                    __Vfunc_disasm__10__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__10__instr) ;
                                    goto __Vlabel7;
                                }
                            } else {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__10__instr) ;
                                goto __Vlabel7;
                            }
                        } else {
                            __Vfunc_disasm__10__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__10__instr) ;
                            goto __Vlabel7;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__10__opcode))) {
                        __Vfunc_disasm__10__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__10__instr) ;
                        goto __Vlabel7;
                    } else if ((4U & (IData)(__Vfunc_disasm__10__opcode))) {
                        __Vfunc_disasm__10__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__10__instr) ;
                        goto __Vlabel7;
                    } else if ((2U & (IData)(__Vfunc_disasm__10__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__10__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__10__funct3))) {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__10__rd,
                                                     32,
                                                     __Vfunc_disasm__10__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__10__rs1)) ;
                                goto __Vlabel7;
                            } else {
                                __Vfunc_disasm__10__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__10__instr) ;
                                goto __Vlabel7;
                            }
                        } else {
                            __Vfunc_disasm__10__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__10__instr) ;
                            goto __Vlabel7;
                        }
                    } else {
                        __Vfunc_disasm__10__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__10__instr) ;
                        goto __Vlabel7;
                    }
                    __Vlabel7: ;
                }
            }(), __Vfunc_disasm__10__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__instruction_file," WB : %@\n \n",
                   -1,&(__Vtemp_5));
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"\n============================================================\nCYCLE %0#\nPC=%08x | STALL=%0b | CTRL_REDIRECT=%0b | TARGET=%08x\nBRANCH_TAKEN=%0b | JUMP_TAKEN=%0b | HALT_IN_WB=%0b\n\n[IF] Instruction Fetch\n  Fetch PC          : %08x\n  Instruction Word  : %08x\n",
                   32,vlSelf->tb_cpu__DOT__cycle_count,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__pc,
                   1,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__stall),
                   1,vlSelf->tb_cpu__DOT__uut__DOT__control_taken,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__jal_target,
                   1,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__branch_cond_taken),
                   1,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_jal,
                   1,(0x500013U == vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr),
                   32,vlSelf->tb_cpu__DOT__uut__DOT__pc,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__instr);
        __Vtemp_6 = ([&]() {
                __Vfunc_disasm__12__instr = vlSelf->tb_cpu__DOT__uut__DOT__instr;
                {
                    __Vfunc_disasm__12__opcode = (0x7fU 
                                                  & __Vfunc_disasm__12__instr);
                    __Vfunc_disasm__12__funct3 = (7U 
                                                  & (__Vfunc_disasm__12__instr 
                                                     >> 0xcU));
                    __Vfunc_disasm__12__funct7 = (__Vfunc_disasm__12__instr 
                                                  >> 0x19U);
                    __Vfunc_disasm__12__rd = (0x1fU 
                                              & (__Vfunc_disasm__12__instr 
                                                 >> 7U));
                    __Vfunc_disasm__12__rs1 = (0x1fU 
                                               & (__Vfunc_disasm__12__instr 
                                                  >> 0xfU));
                    __Vfunc_disasm__12__rs2 = (0x1fU 
                                               & (__Vfunc_disasm__12__instr 
                                                  >> 0x14U));
                    __Vfunc_disasm__12__imm_i = (((- (IData)(
                                                             (__Vfunc_disasm__12__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (__Vfunc_disasm__12__instr 
                                                    >> 0x14U));
                    __Vfunc_disasm__12__imm_s = (((- (IData)(
                                                             (__Vfunc_disasm__12__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (__Vfunc_disasm__12__instr 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (__Vfunc_disasm__12__instr 
                                                          >> 7U))));
                    __Vfunc_disasm__12__imm_b = (((- (IData)(
                                                             (__Vfunc_disasm__12__instr 
                                                              >> 0x1fU))) 
                                                  << 0xdU) 
                                                 | ((0x1000U 
                                                     & (__Vfunc_disasm__12__instr 
                                                        >> 0x13U)) 
                                                    | ((0x800U 
                                                        & (__Vfunc_disasm__12__instr 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (__Vfunc_disasm__12__instr 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (__Vfunc_disasm__12__instr 
                                                                >> 7U))))));
                    __Vfunc_disasm__12__imm_j = (((- (IData)(
                                                             (__Vfunc_disasm__12__instr 
                                                              >> 0x1fU))) 
                                                  << 0x15U) 
                                                 | ((0x100000U 
                                                     & (__Vfunc_disasm__12__instr 
                                                        >> 0xbU)) 
                                                    | ((0xff000U 
                                                        & __Vfunc_disasm__12__instr) 
                                                       | ((0x800U 
                                                           & (__Vfunc_disasm__12__instr 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (__Vfunc_disasm__12__instr 
                                                                >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__12__instr)) {
                        __Vfunc_disasm__12__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel8;
                    }
                    if ((0x13U == __Vfunc_disasm__12__instr)) {
                        __Vfunc_disasm__12__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel8;
                    }
                    if ((0x500013U == __Vfunc_disasm__12__instr)) {
                        __Vfunc_disasm__12__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel8;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__12__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__12__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__12__opcode))) {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__12__instr) ;
                                goto __Vlabel8;
                            } else if ((8U & (IData)(__Vfunc_disasm__12__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__12__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__12__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__12__opcode))) {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__12__rd,
                                                                 32,
                                                                 __Vfunc_disasm__12__imm_j) ;
                                            goto __Vlabel8;
                                        } else {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__12__instr) ;
                                            goto __Vlabel8;
                                        }
                                    } else {
                                        __Vfunc_disasm__12__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__12__instr) ;
                                        goto __Vlabel8;
                                    }
                                } else {
                                    __Vfunc_disasm__12__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__12__instr) ;
                                    goto __Vlabel8;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__12__opcode))) {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__12__instr) ;
                                goto __Vlabel8;
                            } else if ((2U & (IData)(__Vfunc_disasm__12__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__12__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__12__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__12__funct3))) {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__12__instr) ;
                                            goto __Vlabel8;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__12__funct3))) {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__12__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__12__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__12__imm_b) ;
                                            goto __Vlabel8;
                                        } else {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__12__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__12__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__12__imm_b) ;
                                            goto __Vlabel8;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__12__funct3))) {
                                        __Vfunc_disasm__12__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__12__instr) ;
                                        goto __Vlabel8;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__12__funct3))) {
                                        __Vfunc_disasm__12__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__12__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__12__rs2),
                                                             32,
                                                             __Vfunc_disasm__12__imm_b) ;
                                        goto __Vlabel8;
                                    } else {
                                        __Vfunc_disasm__12__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__12__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__12__rs2),
                                                             32,
                                                             __Vfunc_disasm__12__imm_b) ;
                                        goto __Vlabel8;
                                    }
                                } else {
                                    __Vfunc_disasm__12__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__12__instr) ;
                                    goto __Vlabel8;
                                }
                            } else {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__12__instr) ;
                                goto __Vlabel8;
                            }
                        } else {
                            __Vfunc_disasm__12__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__12__instr) ;
                            goto __Vlabel8;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__12__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__12__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__12__opcode))) {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__12__instr) ;
                                goto __Vlabel8;
                            } else if ((4U & (IData)(__Vfunc_disasm__12__opcode))) {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__12__instr) ;
                                goto __Vlabel8;
                            } else if ((2U & (IData)(__Vfunc_disasm__12__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__12__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__12__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__12__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__12__funct3))) {
                                                __Vfunc_disasm__12__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__12__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__12__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__12__rs2) ;
                                                goto __Vlabel8;
                                            } else {
                                                __Vfunc_disasm__12__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__12__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__12__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__12__rs2) ;
                                                goto __Vlabel8;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__12__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__12__funct7))) {
                                                __Vfunc_disasm__12__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__12__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__12__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__12__rs2) ;
                                                goto __Vlabel8;
                                            } else {
                                                __Vfunc_disasm__12__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__12__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__12__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__12__rs2) ;
                                                goto __Vlabel8;
                                            }
                                        } else {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__12__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__12__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__12__rs2) ;
                                            goto __Vlabel8;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__12__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__12__funct3))) {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__12__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__12__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__12__rs2) ;
                                            goto __Vlabel8;
                                        } else {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__12__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__12__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__12__rs2) ;
                                            goto __Vlabel8;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__12__funct3))) {
                                        __Vfunc_disasm__12__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__12__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__12__rs1),
                                                             5,
                                                             __Vfunc_disasm__12__rs2) ;
                                        goto __Vlabel8;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__12__funct7))) {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__12__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__12__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__12__rs2) ;
                                            goto __Vlabel8;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__12__funct7))) {
                                            __Vfunc_disasm__12__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__12__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__12__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__12__rs2) ;
                                            goto __Vlabel8;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__12__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__12__instr) ;
                                    goto __Vlabel8;
                                }
                            } else {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__12__instr) ;
                                goto __Vlabel8;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__12__opcode))) {
                            __Vfunc_disasm__12__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__12__instr) ;
                            goto __Vlabel8;
                        } else if ((4U & (IData)(__Vfunc_disasm__12__opcode))) {
                            __Vfunc_disasm__12__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__12__instr) ;
                            goto __Vlabel8;
                        } else if ((2U & (IData)(__Vfunc_disasm__12__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__12__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__12__funct3))) {
                                    __Vfunc_disasm__12__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__12__rs2,
                                                         32,
                                                         __Vfunc_disasm__12__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__12__rs1)) ;
                                    goto __Vlabel8;
                                } else {
                                    __Vfunc_disasm__12__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__12__instr) ;
                                    goto __Vlabel8;
                                }
                            } else {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__12__instr) ;
                                goto __Vlabel8;
                            }
                        } else {
                            __Vfunc_disasm__12__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__12__instr) ;
                            goto __Vlabel8;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__12__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__12__opcode))) {
                            __Vfunc_disasm__12__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__12__instr) ;
                            goto __Vlabel8;
                        } else if ((4U & (IData)(__Vfunc_disasm__12__opcode))) {
                            __Vfunc_disasm__12__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__12__instr) ;
                            goto __Vlabel8;
                        } else if ((2U & (IData)(__Vfunc_disasm__12__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__12__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__12__funct3))) {
                                    __Vfunc_disasm__12__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__12__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__12__rs1),
                                                         32,
                                                         __Vfunc_disasm__12__imm_i) ;
                                    goto __Vlabel8;
                                } else {
                                    __Vfunc_disasm__12__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__12__instr) ;
                                    goto __Vlabel8;
                                }
                            } else {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__12__instr) ;
                                goto __Vlabel8;
                            }
                        } else {
                            __Vfunc_disasm__12__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__12__instr) ;
                            goto __Vlabel8;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__12__opcode))) {
                        __Vfunc_disasm__12__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__12__instr) ;
                        goto __Vlabel8;
                    } else if ((4U & (IData)(__Vfunc_disasm__12__opcode))) {
                        __Vfunc_disasm__12__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__12__instr) ;
                        goto __Vlabel8;
                    } else if ((2U & (IData)(__Vfunc_disasm__12__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__12__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__12__funct3))) {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__12__rd,
                                                     32,
                                                     __Vfunc_disasm__12__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__12__rs1)) ;
                                goto __Vlabel8;
                            } else {
                                __Vfunc_disasm__12__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__12__instr) ;
                                goto __Vlabel8;
                            }
                        } else {
                            __Vfunc_disasm__12__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__12__instr) ;
                            goto __Vlabel8;
                        }
                    } else {
                        __Vfunc_disasm__12__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__12__instr) ;
                        goto __Vlabel8;
                    }
                    __Vlabel8: ;
                }
            }(), __Vfunc_disasm__12__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Instruction       : %@\n\n[ID] Decode / Register Read\n  Instruction PC    : %08x\n  Instruction Word  : %08x\n",
                   -1,&(__Vtemp_6),32,vlSelf->tb_cpu__DOT__uut__DOT__if_id_pc,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr);
        __Vtemp_7 = ([&]() {
                __Vfunc_disasm__13__instr = vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr;
                {
                    __Vfunc_disasm__13__opcode = (0x7fU 
                                                  & __Vfunc_disasm__13__instr);
                    __Vfunc_disasm__13__funct3 = (7U 
                                                  & (__Vfunc_disasm__13__instr 
                                                     >> 0xcU));
                    __Vfunc_disasm__13__funct7 = (__Vfunc_disasm__13__instr 
                                                  >> 0x19U);
                    __Vfunc_disasm__13__rd = (0x1fU 
                                              & (__Vfunc_disasm__13__instr 
                                                 >> 7U));
                    __Vfunc_disasm__13__rs1 = (0x1fU 
                                               & (__Vfunc_disasm__13__instr 
                                                  >> 0xfU));
                    __Vfunc_disasm__13__rs2 = (0x1fU 
                                               & (__Vfunc_disasm__13__instr 
                                                  >> 0x14U));
                    __Vfunc_disasm__13__imm_i = (((- (IData)(
                                                             (__Vfunc_disasm__13__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (__Vfunc_disasm__13__instr 
                                                    >> 0x14U));
                    __Vfunc_disasm__13__imm_s = (((- (IData)(
                                                             (__Vfunc_disasm__13__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (__Vfunc_disasm__13__instr 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (__Vfunc_disasm__13__instr 
                                                          >> 7U))));
                    __Vfunc_disasm__13__imm_b = (((- (IData)(
                                                             (__Vfunc_disasm__13__instr 
                                                              >> 0x1fU))) 
                                                  << 0xdU) 
                                                 | ((0x1000U 
                                                     & (__Vfunc_disasm__13__instr 
                                                        >> 0x13U)) 
                                                    | ((0x800U 
                                                        & (__Vfunc_disasm__13__instr 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (__Vfunc_disasm__13__instr 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (__Vfunc_disasm__13__instr 
                                                                >> 7U))))));
                    __Vfunc_disasm__13__imm_j = (((- (IData)(
                                                             (__Vfunc_disasm__13__instr 
                                                              >> 0x1fU))) 
                                                  << 0x15U) 
                                                 | ((0x100000U 
                                                     & (__Vfunc_disasm__13__instr 
                                                        >> 0xbU)) 
                                                    | ((0xff000U 
                                                        & __Vfunc_disasm__13__instr) 
                                                       | ((0x800U 
                                                           & (__Vfunc_disasm__13__instr 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (__Vfunc_disasm__13__instr 
                                                                >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__13__instr)) {
                        __Vfunc_disasm__13__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel9;
                    }
                    if ((0x13U == __Vfunc_disasm__13__instr)) {
                        __Vfunc_disasm__13__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel9;
                    }
                    if ((0x500013U == __Vfunc_disasm__13__instr)) {
                        __Vfunc_disasm__13__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel9;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__13__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__13__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__13__opcode))) {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__13__instr) ;
                                goto __Vlabel9;
                            } else if ((8U & (IData)(__Vfunc_disasm__13__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__13__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__13__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__13__opcode))) {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__13__rd,
                                                                 32,
                                                                 __Vfunc_disasm__13__imm_j) ;
                                            goto __Vlabel9;
                                        } else {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__13__instr) ;
                                            goto __Vlabel9;
                                        }
                                    } else {
                                        __Vfunc_disasm__13__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__13__instr) ;
                                        goto __Vlabel9;
                                    }
                                } else {
                                    __Vfunc_disasm__13__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__13__instr) ;
                                    goto __Vlabel9;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__13__opcode))) {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__13__instr) ;
                                goto __Vlabel9;
                            } else if ((2U & (IData)(__Vfunc_disasm__13__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__13__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__13__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__13__funct3))) {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__13__instr) ;
                                            goto __Vlabel9;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__13__funct3))) {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__13__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__13__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__13__imm_b) ;
                                            goto __Vlabel9;
                                        } else {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__13__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__13__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__13__imm_b) ;
                                            goto __Vlabel9;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__13__funct3))) {
                                        __Vfunc_disasm__13__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__13__instr) ;
                                        goto __Vlabel9;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__13__funct3))) {
                                        __Vfunc_disasm__13__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__13__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__13__rs2),
                                                             32,
                                                             __Vfunc_disasm__13__imm_b) ;
                                        goto __Vlabel9;
                                    } else {
                                        __Vfunc_disasm__13__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__13__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__13__rs2),
                                                             32,
                                                             __Vfunc_disasm__13__imm_b) ;
                                        goto __Vlabel9;
                                    }
                                } else {
                                    __Vfunc_disasm__13__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__13__instr) ;
                                    goto __Vlabel9;
                                }
                            } else {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__13__instr) ;
                                goto __Vlabel9;
                            }
                        } else {
                            __Vfunc_disasm__13__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__13__instr) ;
                            goto __Vlabel9;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__13__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__13__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__13__opcode))) {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__13__instr) ;
                                goto __Vlabel9;
                            } else if ((4U & (IData)(__Vfunc_disasm__13__opcode))) {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__13__instr) ;
                                goto __Vlabel9;
                            } else if ((2U & (IData)(__Vfunc_disasm__13__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__13__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__13__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__13__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__13__funct3))) {
                                                __Vfunc_disasm__13__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__13__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__13__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__13__rs2) ;
                                                goto __Vlabel9;
                                            } else {
                                                __Vfunc_disasm__13__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__13__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__13__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__13__rs2) ;
                                                goto __Vlabel9;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__13__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__13__funct7))) {
                                                __Vfunc_disasm__13__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__13__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__13__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__13__rs2) ;
                                                goto __Vlabel9;
                                            } else {
                                                __Vfunc_disasm__13__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__13__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__13__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__13__rs2) ;
                                                goto __Vlabel9;
                                            }
                                        } else {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__13__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__13__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__13__rs2) ;
                                            goto __Vlabel9;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__13__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__13__funct3))) {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__13__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__13__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__13__rs2) ;
                                            goto __Vlabel9;
                                        } else {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__13__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__13__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__13__rs2) ;
                                            goto __Vlabel9;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__13__funct3))) {
                                        __Vfunc_disasm__13__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__13__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__13__rs1),
                                                             5,
                                                             __Vfunc_disasm__13__rs2) ;
                                        goto __Vlabel9;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__13__funct7))) {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__13__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__13__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__13__rs2) ;
                                            goto __Vlabel9;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__13__funct7))) {
                                            __Vfunc_disasm__13__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__13__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__13__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__13__rs2) ;
                                            goto __Vlabel9;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__13__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__13__instr) ;
                                    goto __Vlabel9;
                                }
                            } else {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__13__instr) ;
                                goto __Vlabel9;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__13__opcode))) {
                            __Vfunc_disasm__13__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__13__instr) ;
                            goto __Vlabel9;
                        } else if ((4U & (IData)(__Vfunc_disasm__13__opcode))) {
                            __Vfunc_disasm__13__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__13__instr) ;
                            goto __Vlabel9;
                        } else if ((2U & (IData)(__Vfunc_disasm__13__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__13__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__13__funct3))) {
                                    __Vfunc_disasm__13__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__13__rs2,
                                                         32,
                                                         __Vfunc_disasm__13__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__13__rs1)) ;
                                    goto __Vlabel9;
                                } else {
                                    __Vfunc_disasm__13__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__13__instr) ;
                                    goto __Vlabel9;
                                }
                            } else {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__13__instr) ;
                                goto __Vlabel9;
                            }
                        } else {
                            __Vfunc_disasm__13__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__13__instr) ;
                            goto __Vlabel9;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__13__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__13__opcode))) {
                            __Vfunc_disasm__13__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__13__instr) ;
                            goto __Vlabel9;
                        } else if ((4U & (IData)(__Vfunc_disasm__13__opcode))) {
                            __Vfunc_disasm__13__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__13__instr) ;
                            goto __Vlabel9;
                        } else if ((2U & (IData)(__Vfunc_disasm__13__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__13__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__13__funct3))) {
                                    __Vfunc_disasm__13__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__13__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__13__rs1),
                                                         32,
                                                         __Vfunc_disasm__13__imm_i) ;
                                    goto __Vlabel9;
                                } else {
                                    __Vfunc_disasm__13__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__13__instr) ;
                                    goto __Vlabel9;
                                }
                            } else {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__13__instr) ;
                                goto __Vlabel9;
                            }
                        } else {
                            __Vfunc_disasm__13__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__13__instr) ;
                            goto __Vlabel9;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__13__opcode))) {
                        __Vfunc_disasm__13__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__13__instr) ;
                        goto __Vlabel9;
                    } else if ((4U & (IData)(__Vfunc_disasm__13__opcode))) {
                        __Vfunc_disasm__13__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__13__instr) ;
                        goto __Vlabel9;
                    } else if ((2U & (IData)(__Vfunc_disasm__13__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__13__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__13__funct3))) {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__13__rd,
                                                     32,
                                                     __Vfunc_disasm__13__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__13__rs1)) ;
                                goto __Vlabel9;
                            } else {
                                __Vfunc_disasm__13__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__13__instr) ;
                                goto __Vlabel9;
                            }
                        } else {
                            __Vfunc_disasm__13__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__13__instr) ;
                            goto __Vlabel9;
                        }
                    } else {
                        __Vfunc_disasm__13__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__13__instr) ;
                        goto __Vlabel9;
                    }
                    __Vlabel9: ;
                }
            }(), __Vfunc_disasm__13__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Instruction       : %@\n  Opcode            : %02x\n  Funct3 / Funct7   : %0x / %02x\n  Source Reg 1      : x%0#\n  Source Reg 2      : x%0#\n  Destination Reg   : x%0#\n  Immediate Value   : %0#\n  Type Flags        : R=%0b I=%0b LOAD=%0b STORE=%0b BRANCH=%0b JAL=%0b\n  ALU Control       : %0x\n\n[EX] Execute / ALU / Forwarding\n  Instruction PC    : %08x\n  Instruction Word  : %08x\n",
                   -1,&(__Vtemp_7),7,(0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr),
                   3,(7U & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                            >> 0xcU)),7,(vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                         >> 0x19U),
                   5,(0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                               >> 0xfU)),5,(0x1fU & 
                                            (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                             >> 0x14U)),
                   5,(0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                               >> 7U)),32,vlSelf->tb_cpu__DOT__uut__DOT__imm,
                   1,(0x33U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)),
                   1,(0x13U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)),
                   1,(3U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)),
                   1,(0x23U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)),
                   1,(0x63U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)),
                   1,(0x6fU == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)),
                   4,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__alu_ctrl),
                   32,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_pc,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr);
        __Vtemp_8 = ([&]() {
                __Vfunc_disasm__14__instr = vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr;
                {
                    __Vfunc_disasm__14__opcode = (0x7fU 
                                                  & __Vfunc_disasm__14__instr);
                    __Vfunc_disasm__14__funct3 = (7U 
                                                  & (__Vfunc_disasm__14__instr 
                                                     >> 0xcU));
                    __Vfunc_disasm__14__funct7 = (__Vfunc_disasm__14__instr 
                                                  >> 0x19U);
                    __Vfunc_disasm__14__rd = (0x1fU 
                                              & (__Vfunc_disasm__14__instr 
                                                 >> 7U));
                    __Vfunc_disasm__14__rs1 = (0x1fU 
                                               & (__Vfunc_disasm__14__instr 
                                                  >> 0xfU));
                    __Vfunc_disasm__14__rs2 = (0x1fU 
                                               & (__Vfunc_disasm__14__instr 
                                                  >> 0x14U));
                    __Vfunc_disasm__14__imm_i = (((- (IData)(
                                                             (__Vfunc_disasm__14__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (__Vfunc_disasm__14__instr 
                                                    >> 0x14U));
                    __Vfunc_disasm__14__imm_s = (((- (IData)(
                                                             (__Vfunc_disasm__14__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (__Vfunc_disasm__14__instr 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (__Vfunc_disasm__14__instr 
                                                          >> 7U))));
                    __Vfunc_disasm__14__imm_b = (((- (IData)(
                                                             (__Vfunc_disasm__14__instr 
                                                              >> 0x1fU))) 
                                                  << 0xdU) 
                                                 | ((0x1000U 
                                                     & (__Vfunc_disasm__14__instr 
                                                        >> 0x13U)) 
                                                    | ((0x800U 
                                                        & (__Vfunc_disasm__14__instr 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (__Vfunc_disasm__14__instr 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (__Vfunc_disasm__14__instr 
                                                                >> 7U))))));
                    __Vfunc_disasm__14__imm_j = (((- (IData)(
                                                             (__Vfunc_disasm__14__instr 
                                                              >> 0x1fU))) 
                                                  << 0x15U) 
                                                 | ((0x100000U 
                                                     & (__Vfunc_disasm__14__instr 
                                                        >> 0xbU)) 
                                                    | ((0xff000U 
                                                        & __Vfunc_disasm__14__instr) 
                                                       | ((0x800U 
                                                           & (__Vfunc_disasm__14__instr 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (__Vfunc_disasm__14__instr 
                                                                >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__14__instr)) {
                        __Vfunc_disasm__14__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel10;
                    }
                    if ((0x13U == __Vfunc_disasm__14__instr)) {
                        __Vfunc_disasm__14__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel10;
                    }
                    if ((0x500013U == __Vfunc_disasm__14__instr)) {
                        __Vfunc_disasm__14__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel10;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__14__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__14__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__14__opcode))) {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__14__instr) ;
                                goto __Vlabel10;
                            } else if ((8U & (IData)(__Vfunc_disasm__14__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__14__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__14__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__14__opcode))) {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__14__rd,
                                                                 32,
                                                                 __Vfunc_disasm__14__imm_j) ;
                                            goto __Vlabel10;
                                        } else {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__14__instr) ;
                                            goto __Vlabel10;
                                        }
                                    } else {
                                        __Vfunc_disasm__14__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__14__instr) ;
                                        goto __Vlabel10;
                                    }
                                } else {
                                    __Vfunc_disasm__14__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__14__instr) ;
                                    goto __Vlabel10;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__14__opcode))) {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__14__instr) ;
                                goto __Vlabel10;
                            } else if ((2U & (IData)(__Vfunc_disasm__14__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__14__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__14__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__14__funct3))) {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__14__instr) ;
                                            goto __Vlabel10;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__14__funct3))) {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__14__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__14__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__14__imm_b) ;
                                            goto __Vlabel10;
                                        } else {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__14__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__14__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__14__imm_b) ;
                                            goto __Vlabel10;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__14__funct3))) {
                                        __Vfunc_disasm__14__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__14__instr) ;
                                        goto __Vlabel10;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__14__funct3))) {
                                        __Vfunc_disasm__14__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__14__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__14__rs2),
                                                             32,
                                                             __Vfunc_disasm__14__imm_b) ;
                                        goto __Vlabel10;
                                    } else {
                                        __Vfunc_disasm__14__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__14__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__14__rs2),
                                                             32,
                                                             __Vfunc_disasm__14__imm_b) ;
                                        goto __Vlabel10;
                                    }
                                } else {
                                    __Vfunc_disasm__14__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__14__instr) ;
                                    goto __Vlabel10;
                                }
                            } else {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__14__instr) ;
                                goto __Vlabel10;
                            }
                        } else {
                            __Vfunc_disasm__14__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__14__instr) ;
                            goto __Vlabel10;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__14__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__14__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__14__opcode))) {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__14__instr) ;
                                goto __Vlabel10;
                            } else if ((4U & (IData)(__Vfunc_disasm__14__opcode))) {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__14__instr) ;
                                goto __Vlabel10;
                            } else if ((2U & (IData)(__Vfunc_disasm__14__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__14__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__14__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__14__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__14__funct3))) {
                                                __Vfunc_disasm__14__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__14__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__14__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__14__rs2) ;
                                                goto __Vlabel10;
                                            } else {
                                                __Vfunc_disasm__14__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__14__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__14__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__14__rs2) ;
                                                goto __Vlabel10;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__14__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__14__funct7))) {
                                                __Vfunc_disasm__14__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__14__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__14__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__14__rs2) ;
                                                goto __Vlabel10;
                                            } else {
                                                __Vfunc_disasm__14__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__14__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__14__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__14__rs2) ;
                                                goto __Vlabel10;
                                            }
                                        } else {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__14__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__14__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__14__rs2) ;
                                            goto __Vlabel10;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__14__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__14__funct3))) {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__14__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__14__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__14__rs2) ;
                                            goto __Vlabel10;
                                        } else {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__14__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__14__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__14__rs2) ;
                                            goto __Vlabel10;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__14__funct3))) {
                                        __Vfunc_disasm__14__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__14__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__14__rs1),
                                                             5,
                                                             __Vfunc_disasm__14__rs2) ;
                                        goto __Vlabel10;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__14__funct7))) {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__14__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__14__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__14__rs2) ;
                                            goto __Vlabel10;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__14__funct7))) {
                                            __Vfunc_disasm__14__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__14__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__14__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__14__rs2) ;
                                            goto __Vlabel10;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__14__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__14__instr) ;
                                    goto __Vlabel10;
                                }
                            } else {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__14__instr) ;
                                goto __Vlabel10;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__14__opcode))) {
                            __Vfunc_disasm__14__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__14__instr) ;
                            goto __Vlabel10;
                        } else if ((4U & (IData)(__Vfunc_disasm__14__opcode))) {
                            __Vfunc_disasm__14__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__14__instr) ;
                            goto __Vlabel10;
                        } else if ((2U & (IData)(__Vfunc_disasm__14__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__14__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__14__funct3))) {
                                    __Vfunc_disasm__14__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__14__rs2,
                                                         32,
                                                         __Vfunc_disasm__14__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__14__rs1)) ;
                                    goto __Vlabel10;
                                } else {
                                    __Vfunc_disasm__14__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__14__instr) ;
                                    goto __Vlabel10;
                                }
                            } else {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__14__instr) ;
                                goto __Vlabel10;
                            }
                        } else {
                            __Vfunc_disasm__14__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__14__instr) ;
                            goto __Vlabel10;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__14__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__14__opcode))) {
                            __Vfunc_disasm__14__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__14__instr) ;
                            goto __Vlabel10;
                        } else if ((4U & (IData)(__Vfunc_disasm__14__opcode))) {
                            __Vfunc_disasm__14__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__14__instr) ;
                            goto __Vlabel10;
                        } else if ((2U & (IData)(__Vfunc_disasm__14__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__14__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__14__funct3))) {
                                    __Vfunc_disasm__14__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__14__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__14__rs1),
                                                         32,
                                                         __Vfunc_disasm__14__imm_i) ;
                                    goto __Vlabel10;
                                } else {
                                    __Vfunc_disasm__14__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__14__instr) ;
                                    goto __Vlabel10;
                                }
                            } else {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__14__instr) ;
                                goto __Vlabel10;
                            }
                        } else {
                            __Vfunc_disasm__14__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__14__instr) ;
                            goto __Vlabel10;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__14__opcode))) {
                        __Vfunc_disasm__14__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__14__instr) ;
                        goto __Vlabel10;
                    } else if ((4U & (IData)(__Vfunc_disasm__14__opcode))) {
                        __Vfunc_disasm__14__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__14__instr) ;
                        goto __Vlabel10;
                    } else if ((2U & (IData)(__Vfunc_disasm__14__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__14__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__14__funct3))) {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__14__rd,
                                                     32,
                                                     __Vfunc_disasm__14__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__14__rs1)) ;
                                goto __Vlabel10;
                            } else {
                                __Vfunc_disasm__14__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__14__instr) ;
                                goto __Vlabel10;
                            }
                        } else {
                            __Vfunc_disasm__14__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__14__instr) ;
                            goto __Vlabel10;
                        }
                    } else {
                        __Vfunc_disasm__14__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__14__instr) ;
                        goto __Vlabel10;
                    }
                    __Vlabel10: ;
                }
            }(), __Vfunc_disasm__14__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Instruction       : %@\n  Source Reg 1      : x%0#\n  Source Reg 2      : x%0#\n  Raw Reg Data 1    : %0#\n  Raw Reg Data 2    : %0#\n  Immediate Value   : %0#\n  Forwarded A       : %0#\n  Forwarded B       : %0#\n",
                   -1,&(__Vtemp_8),5,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1),
                   5,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__forward_a,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__forward_b);
        __Vtemp_9 = ([&]() {
                __Vfunc_tb_cpu__DOT__fwd_sel_name__15__sel 
                    = vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel;
                {
                    if ((0U == (IData)(__Vfunc_tb_cpu__DOT__fwd_sel_name__15__sel))) {
                        __Vfunc_tb_cpu__DOT__fwd_sel_name__15__Vfuncout = 
                            std::string{"REGFILE"};
                        goto __Vlabel11;
                    } else if ((1U == (IData)(__Vfunc_tb_cpu__DOT__fwd_sel_name__15__sel))) {
                        __Vfunc_tb_cpu__DOT__fwd_sel_name__15__Vfuncout = 
                            std::string{"MEM/WB"};
                        goto __Vlabel11;
                    } else if ((2U == (IData)(__Vfunc_tb_cpu__DOT__fwd_sel_name__15__sel))) {
                        __Vfunc_tb_cpu__DOT__fwd_sel_name__15__Vfuncout = 
                            std::string{"EX/MEM"};
                        goto __Vlabel11;
                    } else {
                        __Vfunc_tb_cpu__DOT__fwd_sel_name__15__Vfuncout = 
                            std::string{"UNKNOWN"};
                        goto __Vlabel11;
                    }
                    __Vlabel11: ;
                }
            }(), __Vfunc_tb_cpu__DOT__fwd_sel_name__15__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Forward Select A  : %b (%@)\n",
                   2,vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel,
                   -1,&(__Vtemp_9));
        __Vtemp_10 = ([&]() {
                __Vfunc_tb_cpu__DOT__fwd_sel_name__16__sel 
                    = vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel;
                {
                    if ((0U == (IData)(__Vfunc_tb_cpu__DOT__fwd_sel_name__16__sel))) {
                        __Vfunc_tb_cpu__DOT__fwd_sel_name__16__Vfuncout = 
                            std::string{"REGFILE"};
                        goto __Vlabel12;
                    } else if ((1U == (IData)(__Vfunc_tb_cpu__DOT__fwd_sel_name__16__sel))) {
                        __Vfunc_tb_cpu__DOT__fwd_sel_name__16__Vfuncout = 
                            std::string{"MEM/WB"};
                        goto __Vlabel12;
                    } else if ((2U == (IData)(__Vfunc_tb_cpu__DOT__fwd_sel_name__16__sel))) {
                        __Vfunc_tb_cpu__DOT__fwd_sel_name__16__Vfuncout = 
                            std::string{"EX/MEM"};
                        goto __Vlabel12;
                    } else {
                        __Vfunc_tb_cpu__DOT__fwd_sel_name__16__Vfuncout = 
                            std::string{"UNKNOWN"};
                        goto __Vlabel12;
                    }
                    __Vlabel12: ;
                }
            }(), __Vfunc_tb_cpu__DOT__fwd_sel_name__16__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Forward Select B  : %b (%@)\n  Uses Immediate    : %0b\n  ALU Result        : %0# (0x%08x)\n",
                   2,vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel,
                   -1,&(__Vtemp_10),1,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_use_imm),
                   32,vlSelf->tb_cpu__DOT__uut__DOT__alu_result,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__alu_result);
        if (VL_UNLIKELY(vlSelf->tb_cpu__DOT__uut__DOT__stall)) {
            VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"\n[HAZARD] Load-Use Stall Detected\n  EX Load Dest Reg  : x%0#\n  ID Source Reg 1   : x%0#\n  ID Source Reg 2   : x%0#\n",
                       5,vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd,
                       5,(0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                   >> 0xfU)),5,(0x1fU 
                                                & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                   >> 0x14U)));
        }
        if (VL_UNLIKELY(vlSelf->tb_cpu__DOT__uut__DOT__control_taken)) {
            VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"\n[CONTROL] Pipeline Flush / Redirect\n  Branch Taken      : %0b\n  Jump Taken        : %0b\n  Redirect Target   : %08x\n",
                       1,vlSelf->tb_cpu__DOT__uut__DOT__branch_cond_taken,
                       1,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_jal),
                       32,vlSelf->tb_cpu__DOT__uut__DOT__jal_target);
        }
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"\n[MEM] Memory Access / Pass-Through\n  Instruction Word  : %08x\n",
                   32,vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_instr);
        __Vtemp_11 = ([&]() {
                __Vfunc_disasm__17__instr = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_instr;
                {
                    __Vfunc_disasm__17__opcode = (0x7fU 
                                                  & __Vfunc_disasm__17__instr);
                    __Vfunc_disasm__17__funct3 = (7U 
                                                  & (__Vfunc_disasm__17__instr 
                                                     >> 0xcU));
                    __Vfunc_disasm__17__funct7 = (__Vfunc_disasm__17__instr 
                                                  >> 0x19U);
                    __Vfunc_disasm__17__rd = (0x1fU 
                                              & (__Vfunc_disasm__17__instr 
                                                 >> 7U));
                    __Vfunc_disasm__17__rs1 = (0x1fU 
                                               & (__Vfunc_disasm__17__instr 
                                                  >> 0xfU));
                    __Vfunc_disasm__17__rs2 = (0x1fU 
                                               & (__Vfunc_disasm__17__instr 
                                                  >> 0x14U));
                    __Vfunc_disasm__17__imm_i = (((- (IData)(
                                                             (__Vfunc_disasm__17__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (__Vfunc_disasm__17__instr 
                                                    >> 0x14U));
                    __Vfunc_disasm__17__imm_s = (((- (IData)(
                                                             (__Vfunc_disasm__17__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (__Vfunc_disasm__17__instr 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (__Vfunc_disasm__17__instr 
                                                          >> 7U))));
                    __Vfunc_disasm__17__imm_b = (((- (IData)(
                                                             (__Vfunc_disasm__17__instr 
                                                              >> 0x1fU))) 
                                                  << 0xdU) 
                                                 | ((0x1000U 
                                                     & (__Vfunc_disasm__17__instr 
                                                        >> 0x13U)) 
                                                    | ((0x800U 
                                                        & (__Vfunc_disasm__17__instr 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (__Vfunc_disasm__17__instr 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (__Vfunc_disasm__17__instr 
                                                                >> 7U))))));
                    __Vfunc_disasm__17__imm_j = (((- (IData)(
                                                             (__Vfunc_disasm__17__instr 
                                                              >> 0x1fU))) 
                                                  << 0x15U) 
                                                 | ((0x100000U 
                                                     & (__Vfunc_disasm__17__instr 
                                                        >> 0xbU)) 
                                                    | ((0xff000U 
                                                        & __Vfunc_disasm__17__instr) 
                                                       | ((0x800U 
                                                           & (__Vfunc_disasm__17__instr 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (__Vfunc_disasm__17__instr 
                                                                >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__17__instr)) {
                        __Vfunc_disasm__17__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel13;
                    }
                    if ((0x13U == __Vfunc_disasm__17__instr)) {
                        __Vfunc_disasm__17__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel13;
                    }
                    if ((0x500013U == __Vfunc_disasm__17__instr)) {
                        __Vfunc_disasm__17__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel13;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__17__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__17__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__17__opcode))) {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__17__instr) ;
                                goto __Vlabel13;
                            } else if ((8U & (IData)(__Vfunc_disasm__17__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__17__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__17__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__17__opcode))) {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__17__rd,
                                                                 32,
                                                                 __Vfunc_disasm__17__imm_j) ;
                                            goto __Vlabel13;
                                        } else {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__17__instr) ;
                                            goto __Vlabel13;
                                        }
                                    } else {
                                        __Vfunc_disasm__17__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__17__instr) ;
                                        goto __Vlabel13;
                                    }
                                } else {
                                    __Vfunc_disasm__17__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__17__instr) ;
                                    goto __Vlabel13;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__17__opcode))) {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__17__instr) ;
                                goto __Vlabel13;
                            } else if ((2U & (IData)(__Vfunc_disasm__17__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__17__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__17__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__17__funct3))) {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__17__instr) ;
                                            goto __Vlabel13;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__17__funct3))) {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__17__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__17__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__17__imm_b) ;
                                            goto __Vlabel13;
                                        } else {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__17__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__17__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__17__imm_b) ;
                                            goto __Vlabel13;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__17__funct3))) {
                                        __Vfunc_disasm__17__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__17__instr) ;
                                        goto __Vlabel13;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__17__funct3))) {
                                        __Vfunc_disasm__17__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__17__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__17__rs2),
                                                             32,
                                                             __Vfunc_disasm__17__imm_b) ;
                                        goto __Vlabel13;
                                    } else {
                                        __Vfunc_disasm__17__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__17__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__17__rs2),
                                                             32,
                                                             __Vfunc_disasm__17__imm_b) ;
                                        goto __Vlabel13;
                                    }
                                } else {
                                    __Vfunc_disasm__17__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__17__instr) ;
                                    goto __Vlabel13;
                                }
                            } else {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__17__instr) ;
                                goto __Vlabel13;
                            }
                        } else {
                            __Vfunc_disasm__17__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__17__instr) ;
                            goto __Vlabel13;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__17__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__17__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__17__opcode))) {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__17__instr) ;
                                goto __Vlabel13;
                            } else if ((4U & (IData)(__Vfunc_disasm__17__opcode))) {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__17__instr) ;
                                goto __Vlabel13;
                            } else if ((2U & (IData)(__Vfunc_disasm__17__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__17__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__17__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__17__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__17__funct3))) {
                                                __Vfunc_disasm__17__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__17__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__17__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__17__rs2) ;
                                                goto __Vlabel13;
                                            } else {
                                                __Vfunc_disasm__17__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__17__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__17__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__17__rs2) ;
                                                goto __Vlabel13;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__17__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__17__funct7))) {
                                                __Vfunc_disasm__17__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__17__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__17__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__17__rs2) ;
                                                goto __Vlabel13;
                                            } else {
                                                __Vfunc_disasm__17__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__17__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__17__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__17__rs2) ;
                                                goto __Vlabel13;
                                            }
                                        } else {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__17__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__17__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__17__rs2) ;
                                            goto __Vlabel13;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__17__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__17__funct3))) {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__17__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__17__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__17__rs2) ;
                                            goto __Vlabel13;
                                        } else {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__17__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__17__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__17__rs2) ;
                                            goto __Vlabel13;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__17__funct3))) {
                                        __Vfunc_disasm__17__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__17__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__17__rs1),
                                                             5,
                                                             __Vfunc_disasm__17__rs2) ;
                                        goto __Vlabel13;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__17__funct7))) {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__17__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__17__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__17__rs2) ;
                                            goto __Vlabel13;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__17__funct7))) {
                                            __Vfunc_disasm__17__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__17__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__17__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__17__rs2) ;
                                            goto __Vlabel13;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__17__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__17__instr) ;
                                    goto __Vlabel13;
                                }
                            } else {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__17__instr) ;
                                goto __Vlabel13;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__17__opcode))) {
                            __Vfunc_disasm__17__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__17__instr) ;
                            goto __Vlabel13;
                        } else if ((4U & (IData)(__Vfunc_disasm__17__opcode))) {
                            __Vfunc_disasm__17__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__17__instr) ;
                            goto __Vlabel13;
                        } else if ((2U & (IData)(__Vfunc_disasm__17__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__17__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__17__funct3))) {
                                    __Vfunc_disasm__17__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__17__rs2,
                                                         32,
                                                         __Vfunc_disasm__17__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__17__rs1)) ;
                                    goto __Vlabel13;
                                } else {
                                    __Vfunc_disasm__17__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__17__instr) ;
                                    goto __Vlabel13;
                                }
                            } else {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__17__instr) ;
                                goto __Vlabel13;
                            }
                        } else {
                            __Vfunc_disasm__17__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__17__instr) ;
                            goto __Vlabel13;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__17__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__17__opcode))) {
                            __Vfunc_disasm__17__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__17__instr) ;
                            goto __Vlabel13;
                        } else if ((4U & (IData)(__Vfunc_disasm__17__opcode))) {
                            __Vfunc_disasm__17__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__17__instr) ;
                            goto __Vlabel13;
                        } else if ((2U & (IData)(__Vfunc_disasm__17__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__17__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__17__funct3))) {
                                    __Vfunc_disasm__17__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__17__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__17__rs1),
                                                         32,
                                                         __Vfunc_disasm__17__imm_i) ;
                                    goto __Vlabel13;
                                } else {
                                    __Vfunc_disasm__17__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__17__instr) ;
                                    goto __Vlabel13;
                                }
                            } else {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__17__instr) ;
                                goto __Vlabel13;
                            }
                        } else {
                            __Vfunc_disasm__17__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__17__instr) ;
                            goto __Vlabel13;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__17__opcode))) {
                        __Vfunc_disasm__17__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__17__instr) ;
                        goto __Vlabel13;
                    } else if ((4U & (IData)(__Vfunc_disasm__17__opcode))) {
                        __Vfunc_disasm__17__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__17__instr) ;
                        goto __Vlabel13;
                    } else if ((2U & (IData)(__Vfunc_disasm__17__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__17__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__17__funct3))) {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__17__rd,
                                                     32,
                                                     __Vfunc_disasm__17__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__17__rs1)) ;
                                goto __Vlabel13;
                            } else {
                                __Vfunc_disasm__17__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__17__instr) ;
                                goto __Vlabel13;
                            }
                        } else {
                            __Vfunc_disasm__17__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__17__instr) ;
                            goto __Vlabel13;
                        }
                    } else {
                        __Vfunc_disasm__17__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__17__instr) ;
                        goto __Vlabel13;
                    }
                    __Vlabel13: ;
                }
            }(), __Vfunc_disasm__17__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Instruction       : %@\n  Stage Opcode      : %02x\n",
                   -1,&(__Vtemp_11),7,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode));
        if (((3U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)) 
             | (0x23U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)))) {
            VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Memory Access     : YES\n  Effective Address : %08x\n  Memory Read En    : %0b\n  Memory Write En   : %0b\n  Store Write Data  : %0#\n  Load Read Data    : %0#\n",
                       32,vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result,
                       1,(3U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)),
                       1,(0x23U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)),
                       32,vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_store_data,
                       32,vlSelf->tb_cpu__DOT__uut__DOT__mem_read_data);
        } else {
            VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Memory Access     : NO\n  ALU Pass-Through  : %0# (0x%08x)\n",
                       32,vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result,
                       32,vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result);
        }
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"\n[WB] Writeback / Commit\n  Instruction Word  : %08x\n",
                   32,vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr);
        __Vtemp_12 = ([&]() {
                __Vfunc_disasm__18__instr = vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr;
                {
                    __Vfunc_disasm__18__opcode = (0x7fU 
                                                  & __Vfunc_disasm__18__instr);
                    __Vfunc_disasm__18__funct3 = (7U 
                                                  & (__Vfunc_disasm__18__instr 
                                                     >> 0xcU));
                    __Vfunc_disasm__18__funct7 = (__Vfunc_disasm__18__instr 
                                                  >> 0x19U);
                    __Vfunc_disasm__18__rd = (0x1fU 
                                              & (__Vfunc_disasm__18__instr 
                                                 >> 7U));
                    __Vfunc_disasm__18__rs1 = (0x1fU 
                                               & (__Vfunc_disasm__18__instr 
                                                  >> 0xfU));
                    __Vfunc_disasm__18__rs2 = (0x1fU 
                                               & (__Vfunc_disasm__18__instr 
                                                  >> 0x14U));
                    __Vfunc_disasm__18__imm_i = (((- (IData)(
                                                             (__Vfunc_disasm__18__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | (__Vfunc_disasm__18__instr 
                                                    >> 0x14U));
                    __Vfunc_disasm__18__imm_s = (((- (IData)(
                                                             (__Vfunc_disasm__18__instr 
                                                              >> 0x1fU))) 
                                                  << 0xcU) 
                                                 | ((0xfe0U 
                                                     & (__Vfunc_disasm__18__instr 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (__Vfunc_disasm__18__instr 
                                                          >> 7U))));
                    __Vfunc_disasm__18__imm_b = (((- (IData)(
                                                             (__Vfunc_disasm__18__instr 
                                                              >> 0x1fU))) 
                                                  << 0xdU) 
                                                 | ((0x1000U 
                                                     & (__Vfunc_disasm__18__instr 
                                                        >> 0x13U)) 
                                                    | ((0x800U 
                                                        & (__Vfunc_disasm__18__instr 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (__Vfunc_disasm__18__instr 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (__Vfunc_disasm__18__instr 
                                                                >> 7U))))));
                    __Vfunc_disasm__18__imm_j = (((- (IData)(
                                                             (__Vfunc_disasm__18__instr 
                                                              >> 0x1fU))) 
                                                  << 0x15U) 
                                                 | ((0x100000U 
                                                     & (__Vfunc_disasm__18__instr 
                                                        >> 0xbU)) 
                                                    | ((0xff000U 
                                                        & __Vfunc_disasm__18__instr) 
                                                       | ((0x800U 
                                                           & (__Vfunc_disasm__18__instr 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (__Vfunc_disasm__18__instr 
                                                                >> 0x14U))))));
                    if ((0U == __Vfunc_disasm__18__instr)) {
                        __Vfunc_disasm__18__Vfuncout = 
                            std::string{"BUBBLE/FLUSH"};
                        goto __Vlabel14;
                    }
                    if ((0x13U == __Vfunc_disasm__18__instr)) {
                        __Vfunc_disasm__18__Vfuncout = 
                            std::string{"HALT/NOP: ADDI x0, x0, 0"};
                        goto __Vlabel14;
                    }
                    if ((0x500013U == __Vfunc_disasm__18__instr)) {
                        __Vfunc_disasm__18__Vfuncout = 
                            std::string{"HALT: ADDI x0, x0, 5"};
                        goto __Vlabel14;
                    }
                    if ((0x40U & (IData)(__Vfunc_disasm__18__opcode))) {
                        if ((0x20U & (IData)(__Vfunc_disasm__18__opcode))) {
                            if ((0x10U & (IData)(__Vfunc_disasm__18__opcode))) {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__18__instr) ;
                                goto __Vlabel14;
                            } else if ((8U & (IData)(__Vfunc_disasm__18__opcode))) {
                                if ((4U & (IData)(__Vfunc_disasm__18__opcode))) {
                                    if ((2U & (IData)(__Vfunc_disasm__18__opcode))) {
                                        if ((1U & (IData)(__Vfunc_disasm__18__opcode))) {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("JAL x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__18__rd,
                                                                 32,
                                                                 __Vfunc_disasm__18__imm_j) ;
                                            goto __Vlabel14;
                                        } else {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__18__instr) ;
                                            goto __Vlabel14;
                                        }
                                    } else {
                                        __Vfunc_disasm__18__Vfuncout 
                                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__18__instr) ;
                                        goto __Vlabel14;
                                    }
                                } else {
                                    __Vfunc_disasm__18__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__18__instr) ;
                                    goto __Vlabel14;
                                }
                            } else if ((4U & (IData)(__Vfunc_disasm__18__opcode))) {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__18__instr) ;
                                goto __Vlabel14;
                            } else if ((2U & (IData)(__Vfunc_disasm__18__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__18__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__18__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__18__funct3))) {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                                 32,
                                                                 __Vfunc_disasm__18__instr) ;
                                            goto __Vlabel14;
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__18__funct3))) {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("BGE x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__18__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__18__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__18__imm_b) ;
                                            goto __Vlabel14;
                                        } else {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("BLT x%0#, x%0#, %0d",
                                                                 5,
                                                                 __Vfunc_disasm__18__rs1,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__18__rs2),
                                                                 32,
                                                                 __Vfunc_disasm__18__imm_b) ;
                                            goto __Vlabel14;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__18__funct3))) {
                                        __Vfunc_disasm__18__Vfuncout 
                                            = VL_SFORMATF_NX("BRANCH? instr=%08x",
                                                             32,
                                                             __Vfunc_disasm__18__instr) ;
                                        goto __Vlabel14;
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__18__funct3))) {
                                        __Vfunc_disasm__18__Vfuncout 
                                            = VL_SFORMATF_NX("BNE x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__18__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__18__rs2),
                                                             32,
                                                             __Vfunc_disasm__18__imm_b) ;
                                        goto __Vlabel14;
                                    } else {
                                        __Vfunc_disasm__18__Vfuncout 
                                            = VL_SFORMATF_NX("BEQ x%0#, x%0#, %0d",
                                                             5,
                                                             __Vfunc_disasm__18__rs1,
                                                             5,
                                                             (IData)(__Vfunc_disasm__18__rs2),
                                                             32,
                                                             __Vfunc_disasm__18__imm_b) ;
                                        goto __Vlabel14;
                                    }
                                } else {
                                    __Vfunc_disasm__18__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__18__instr) ;
                                    goto __Vlabel14;
                                }
                            } else {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__18__instr) ;
                                goto __Vlabel14;
                            }
                        } else {
                            __Vfunc_disasm__18__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__18__instr) ;
                            goto __Vlabel14;
                        }
                    } else if ((0x20U & (IData)(__Vfunc_disasm__18__opcode))) {
                        if ((0x10U & (IData)(__Vfunc_disasm__18__opcode))) {
                            if ((8U & (IData)(__Vfunc_disasm__18__opcode))) {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__18__instr) ;
                                goto __Vlabel14;
                            } else if ((4U & (IData)(__Vfunc_disasm__18__opcode))) {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__18__instr) ;
                                goto __Vlabel14;
                            } else if ((2U & (IData)(__Vfunc_disasm__18__opcode))) {
                                if ((1U & (IData)(__Vfunc_disasm__18__opcode))) {
                                    if ((4U & (IData)(__Vfunc_disasm__18__funct3))) {
                                        if ((2U & (IData)(__Vfunc_disasm__18__funct3))) {
                                            if ((1U 
                                                 & (IData)(__Vfunc_disasm__18__funct3))) {
                                                __Vfunc_disasm__18__Vfuncout 
                                                    = VL_SFORMATF_NX("AND x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__18__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__18__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__18__rs2) ;
                                                goto __Vlabel14;
                                            } else {
                                                __Vfunc_disasm__18__Vfuncout 
                                                    = VL_SFORMATF_NX("OR x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__18__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__18__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__18__rs2) ;
                                                goto __Vlabel14;
                                            }
                                        } else if (
                                                   (1U 
                                                    & (IData)(__Vfunc_disasm__18__funct3))) {
                                            if ((0x20U 
                                                 == (IData)(__Vfunc_disasm__18__funct7))) {
                                                __Vfunc_disasm__18__Vfuncout 
                                                    = VL_SFORMATF_NX("SRA x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__18__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__18__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__18__rs2) ;
                                                goto __Vlabel14;
                                            } else {
                                                __Vfunc_disasm__18__Vfuncout 
                                                    = VL_SFORMATF_NX("SRL x%0#, x%0#, x%0#",
                                                                     5,
                                                                     __Vfunc_disasm__18__rd,
                                                                     5,
                                                                     (IData)(__Vfunc_disasm__18__rs1),
                                                                     5,
                                                                     __Vfunc_disasm__18__rs2) ;
                                                goto __Vlabel14;
                                            }
                                        } else {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("XOR x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__18__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__18__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__18__rs2) ;
                                            goto __Vlabel14;
                                        }
                                    } else if ((2U 
                                                & (IData)(__Vfunc_disasm__18__funct3))) {
                                        if ((1U & (IData)(__Vfunc_disasm__18__funct3))) {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("SLTU x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__18__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__18__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__18__rs2) ;
                                            goto __Vlabel14;
                                        } else {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("SLT x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__18__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__18__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__18__rs2) ;
                                            goto __Vlabel14;
                                        }
                                    } else if ((1U 
                                                & (IData)(__Vfunc_disasm__18__funct3))) {
                                        __Vfunc_disasm__18__Vfuncout 
                                            = VL_SFORMATF_NX("SLL x%0#, x%0#, x%0#",
                                                             5,
                                                             __Vfunc_disasm__18__rd,
                                                             5,
                                                             (IData)(__Vfunc_disasm__18__rs1),
                                                             5,
                                                             __Vfunc_disasm__18__rs2) ;
                                        goto __Vlabel14;
                                    } else {
                                        if ((0x20U 
                                             == (IData)(__Vfunc_disasm__18__funct7))) {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("SUB x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__18__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__18__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__18__rs2) ;
                                            goto __Vlabel14;
                                        }
                                        if ((0U == (IData)(__Vfunc_disasm__18__funct7))) {
                                            __Vfunc_disasm__18__Vfuncout 
                                                = VL_SFORMATF_NX("ADD x%0#, x%0#, x%0#",
                                                                 5,
                                                                 __Vfunc_disasm__18__rd,
                                                                 5,
                                                                 (IData)(__Vfunc_disasm__18__rs1),
                                                                 5,
                                                                 __Vfunc_disasm__18__rs2) ;
                                            goto __Vlabel14;
                                        }
                                    }
                                } else {
                                    __Vfunc_disasm__18__Vfuncout 
                                        = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__18__instr) ;
                                    goto __Vlabel14;
                                }
                            } else {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__18__instr) ;
                                goto __Vlabel14;
                            }
                        } else if ((8U & (IData)(__Vfunc_disasm__18__opcode))) {
                            __Vfunc_disasm__18__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__18__instr) ;
                            goto __Vlabel14;
                        } else if ((4U & (IData)(__Vfunc_disasm__18__opcode))) {
                            __Vfunc_disasm__18__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__18__instr) ;
                            goto __Vlabel14;
                        } else if ((2U & (IData)(__Vfunc_disasm__18__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__18__opcode))) {
                                if ((2U == (IData)(__Vfunc_disasm__18__funct3))) {
                                    __Vfunc_disasm__18__Vfuncout 
                                        = VL_SFORMATF_NX("SW x%0#, %0d(x%0#)",
                                                         5,
                                                         __Vfunc_disasm__18__rs2,
                                                         32,
                                                         __Vfunc_disasm__18__imm_s,
                                                         5,
                                                         (IData)(__Vfunc_disasm__18__rs1)) ;
                                    goto __Vlabel14;
                                } else {
                                    __Vfunc_disasm__18__Vfuncout 
                                        = VL_SFORMATF_NX("STORE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__18__instr) ;
                                    goto __Vlabel14;
                                }
                            } else {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__18__instr) ;
                                goto __Vlabel14;
                            }
                        } else {
                            __Vfunc_disasm__18__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__18__instr) ;
                            goto __Vlabel14;
                        }
                    } else if ((0x10U & (IData)(__Vfunc_disasm__18__opcode))) {
                        if ((8U & (IData)(__Vfunc_disasm__18__opcode))) {
                            __Vfunc_disasm__18__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__18__instr) ;
                            goto __Vlabel14;
                        } else if ((4U & (IData)(__Vfunc_disasm__18__opcode))) {
                            __Vfunc_disasm__18__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__18__instr) ;
                            goto __Vlabel14;
                        } else if ((2U & (IData)(__Vfunc_disasm__18__opcode))) {
                            if ((1U & (IData)(__Vfunc_disasm__18__opcode))) {
                                if ((0U == (IData)(__Vfunc_disasm__18__funct3))) {
                                    __Vfunc_disasm__18__Vfuncout 
                                        = VL_SFORMATF_NX("ADDI x%0#, x%0#, %0d",
                                                         5,
                                                         __Vfunc_disasm__18__rd,
                                                         5,
                                                         (IData)(__Vfunc_disasm__18__rs1),
                                                         32,
                                                         __Vfunc_disasm__18__imm_i) ;
                                    goto __Vlabel14;
                                } else {
                                    __Vfunc_disasm__18__Vfuncout 
                                        = VL_SFORMATF_NX("I-TYPE? instr=%08x",
                                                         32,
                                                         __Vfunc_disasm__18__instr) ;
                                    goto __Vlabel14;
                                }
                            } else {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__18__instr) ;
                                goto __Vlabel14;
                            }
                        } else {
                            __Vfunc_disasm__18__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__18__instr) ;
                            goto __Vlabel14;
                        }
                    } else if ((8U & (IData)(__Vfunc_disasm__18__opcode))) {
                        __Vfunc_disasm__18__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__18__instr) ;
                        goto __Vlabel14;
                    } else if ((4U & (IData)(__Vfunc_disasm__18__opcode))) {
                        __Vfunc_disasm__18__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__18__instr) ;
                        goto __Vlabel14;
                    } else if ((2U & (IData)(__Vfunc_disasm__18__opcode))) {
                        if ((1U & (IData)(__Vfunc_disasm__18__opcode))) {
                            if ((2U == (IData)(__Vfunc_disasm__18__funct3))) {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("LW x%0#, %0d(x%0#)",
                                                     5,
                                                     __Vfunc_disasm__18__rd,
                                                     32,
                                                     __Vfunc_disasm__18__imm_i,
                                                     5,
                                                     (IData)(__Vfunc_disasm__18__rs1)) ;
                                goto __Vlabel14;
                            } else {
                                __Vfunc_disasm__18__Vfuncout 
                                    = VL_SFORMATF_NX("LOAD? instr=%08x",
                                                     32,
                                                     __Vfunc_disasm__18__instr) ;
                                goto __Vlabel14;
                            }
                        } else {
                            __Vfunc_disasm__18__Vfuncout 
                                = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                                 32,
                                                 __Vfunc_disasm__18__instr) ;
                            goto __Vlabel14;
                        }
                    } else {
                        __Vfunc_disasm__18__Vfuncout 
                            = VL_SFORMATF_NX("UNKNOWN instr=%08x",
                                             32,__Vfunc_disasm__18__instr) ;
                        goto __Vlabel14;
                    }
                    __Vlabel14: ;
                }
            }(), __Vfunc_disasm__18__Vfuncout);
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Instruction       : %@\n  Writeback Opcode  : %02x\n  Is JAL Writeback  : %0b\n  JAL PC + 4        : %08x\n",
                   -1,&(__Vtemp_12),7,(IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode),
                   1,vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_is_jal,
                   32,vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_pc_plus_4);
        if (VL_UNLIKELY(((IData)(vlSelf->tb_cpu__DOT__uut__DOT__wb_we) 
                         & (0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd))))) {
            VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Commit Valid      : YES\n  Destination Reg   : x%0#\n  Writeback Data    : %0# (0x%08x)\n",
                       5,vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd,
                       32,vlSelf->tb_cpu__DOT__uut__DOT__wb_data,
                       32,vlSelf->tb_cpu__DOT__uut__DOT__wb_data);
        } else if (((IData)(vlSelf->tb_cpu__DOT__uut__DOT__wb_we) 
                    & (0U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd)))) {
            VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Commit Valid      : NO\n  Register Write    : blocked write to x0\n  Attempted Data    : %0# (0x%08x)\n",
                       32,vlSelf->tb_cpu__DOT__uut__DOT__wb_data,
                       32,vlSelf->tb_cpu__DOT__uut__DOT__wb_data);
        } else {
            VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"  Commit Valid      : NO\n  Register Write    : none\n");
        }
        VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"============================================================\n");
        if (VL_UNLIKELY((0x500013U == vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr))) {
            VL_FWRITEF(vlSelf->tb_cpu__DOT__instruction_file,"\nHALT reached WB stage. Ending simulation.\n");
            VL_FWRITEF(vlSelf->tb_cpu__DOT__trace_file,"\nHALT reached WB stage. Ending simulation.\n");
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"\n==================== FINAL SUMMARY ====================\n\n[GENERAL PERFORMANCE]\nCycles                   : %0#\nRetired Instructions     : %0#\n",
                       32,vlSelf->tb_cpu__DOT__cycle_count,
                       32,vlSelf->tb_cpu__DOT__retired_count);
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"CPI                      : %0f\n",
                       64,([&]() {
                            {
                                if ((0U != vlSelf->tb_cpu__DOT__retired_count)) {
                                    __Vfunc_tb_cpu__DOT__calc_cpi__20__Vfuncout 
                                        = ((1.0 * VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__cycle_count)) 
                                           / VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__retired_count));
                                    goto __Vlabel15;
                                } else {
                                    __Vfunc_tb_cpu__DOT__calc_cpi__20__Vfuncout = 0.0;
                                    goto __Vlabel15;
                                }
                                __Vlabel15: ;
                            }
                        }(), __Vfunc_tb_cpu__DOT__calc_cpi__20__Vfuncout));
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"IPC                      : %0f\n",
                       64,([&]() {
                            {
                                if ((0U != vlSelf->tb_cpu__DOT__cycle_count)) {
                                    __Vfunc_tb_cpu__DOT__calc_ipc__21__Vfuncout 
                                        = ((1.0 * VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__retired_count)) 
                                           / VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__cycle_count));
                                    goto __Vlabel16;
                                } else {
                                    __Vfunc_tb_cpu__DOT__calc_ipc__21__Vfuncout = 0.0;
                                    goto __Vlabel16;
                                }
                                __Vlabel16: ;
                            }
                        }(), __Vfunc_tb_cpu__DOT__calc_ipc__21__Vfuncout));
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"\n[PIPELINE HAZARDS]\nStall Cycles             : %0#\n",
                       32,vlSelf->tb_cpu__DOT__stall_count);
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"Stall Rate               : %0f%%\n",
                       64,([&]() {
                            {
                                if ((0U != vlSelf->tb_cpu__DOT__cycle_count)) {
                                    __Vfunc_tb_cpu__DOT__calc_stall_rate__22__Vfuncout 
                                        = ((100.0 * 
                                            VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__stall_count)) 
                                           / VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__cycle_count));
                                    goto __Vlabel17;
                                } else {
                                    __Vfunc_tb_cpu__DOT__calc_stall_rate__22__Vfuncout = 0.0;
                                    goto __Vlabel17;
                                }
                                __Vlabel17: ;
                            }
                        }(), __Vfunc_tb_cpu__DOT__calc_stall_rate__22__Vfuncout));
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"Load-Use Stalls          : %0#\n\n[CONTROL FLOW]\nTaken Branches           : %0#\nTaken Jumps              : %0#\nControl Redirects        : %0#\nFlush Events             : %0#\n",
                       32,vlSelf->tb_cpu__DOT__load_use_stall_count,
                       32,vlSelf->tb_cpu__DOT__branch_taken_count,
                       32,vlSelf->tb_cpu__DOT__jump_taken_count,
                       32,vlSelf->tb_cpu__DOT__control_count,
                       32,vlSelf->tb_cpu__DOT__flush_count);
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"Control Redirect Rate    : %0f%%\n",
                       64,([&]() {
                            {
                                if ((0U != vlSelf->tb_cpu__DOT__retired_count)) {
                                    __Vfunc_tb_cpu__DOT__calc_control_redirect_rate__23__Vfuncout 
                                        = ((100.0 * 
                                            VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__control_count)) 
                                           / VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__retired_count));
                                    goto __Vlabel18;
                                } else {
                                    __Vfunc_tb_cpu__DOT__calc_control_redirect_rate__23__Vfuncout = 0.0;
                                    goto __Vlabel18;
                                }
                                __Vlabel18: ;
                            }
                        }(), __Vfunc_tb_cpu__DOT__calc_control_redirect_rate__23__Vfuncout));
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"\n[INSTRUCTION MIX]\nR-Type Instructions      : %0#\nI-Type Instructions      : %0#\nLoad Instructions        : %0#\nStore Instructions       : %0#\nBranch Instructions      : %0#\nJAL Instructions         : %0#\n\n[MEMORY ACTIVITY]\nMemory Instructions      : %0#\n",
                       32,vlSelf->tb_cpu__DOT__rtype_count,
                       32,vlSelf->tb_cpu__DOT__itype_count,
                       32,vlSelf->tb_cpu__DOT__load_count,
                       32,vlSelf->tb_cpu__DOT__store_count,
                       32,vlSelf->tb_cpu__DOT__branch_instr_count,
                       32,vlSelf->tb_cpu__DOT__jal_instr_count,
                       32,(vlSelf->tb_cpu__DOT__load_count 
                           + vlSelf->tb_cpu__DOT__store_count));
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"Memory Instruction Rate  : %0f%%\n",
                       64,([&]() {
                            {
                                if ((0U != vlSelf->tb_cpu__DOT__retired_count)) {
                                    __Vfunc_tb_cpu__DOT__calc_memory_instruction_rate__24__Vfuncout 
                                        = ((100.0 * 
                                            VL_ITOR_D_I(32, 
                                                        (vlSelf->tb_cpu__DOT__load_count 
                                                         + vlSelf->tb_cpu__DOT__store_count))) 
                                           / VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__retired_count));
                                    goto __Vlabel19;
                                } else {
                                    __Vfunc_tb_cpu__DOT__calc_memory_instruction_rate__24__Vfuncout = 0.0;
                                    goto __Vlabel19;
                                }
                                __Vlabel19: ;
                            }
                        }(), __Vfunc_tb_cpu__DOT__calc_memory_instruction_rate__24__Vfuncout));
            VL_FWRITEF(vlSelf->tb_cpu__DOT__summary_file,"\n[FORWARDING ACTIVITY]\nEX/MEM Forward A Count   : %0#\nEX/MEM Forward B Count   : %0#\nMEM/WB Forward A Count   : %0#\nMEM/WB Forward B Count   : %0#\nTotal Forward Events     : %0#\n\n=======================================================\n\n",
                       32,vlSelf->tb_cpu__DOT__ex_mem_forward_a_count,
                       32,vlSelf->tb_cpu__DOT__ex_mem_forward_b_count,
                       32,vlSelf->tb_cpu__DOT__mem_wb_forward_a_count,
                       32,vlSelf->tb_cpu__DOT__mem_wb_forward_b_count,
                       32,vlSelf->tb_cpu__DOT__total_forward_count);
            VL_WRITEF("\nSUMMARY:\nCycles=%0# | Retired=%0# | CPI=%0f | IPC=%0f\nStalls=%0# | Branches Taken=%0# | Jumps Taken=%0# | Forwards=%0#\n",
                      32,vlSelf->tb_cpu__DOT__cycle_count,
                      32,vlSelf->tb_cpu__DOT__retired_count,
                      64,([&]() {
                            {
                                if ((0U != vlSelf->tb_cpu__DOT__retired_count)) {
                                    __Vfunc_tb_cpu__DOT__calc_cpi__25__Vfuncout 
                                        = ((1.0 * VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__cycle_count)) 
                                           / VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__retired_count));
                                    goto __Vlabel20;
                                } else {
                                    __Vfunc_tb_cpu__DOT__calc_cpi__25__Vfuncout = 0.0;
                                    goto __Vlabel20;
                                }
                                __Vlabel20: ;
                            }
                        }(), __Vfunc_tb_cpu__DOT__calc_cpi__25__Vfuncout),
                      64,([&]() {
                            {
                                if ((0U != vlSelf->tb_cpu__DOT__cycle_count)) {
                                    __Vfunc_tb_cpu__DOT__calc_ipc__26__Vfuncout 
                                        = ((1.0 * VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__retired_count)) 
                                           / VL_ITOR_D_I(32, vlSelf->tb_cpu__DOT__cycle_count));
                                    goto __Vlabel21;
                                } else {
                                    __Vfunc_tb_cpu__DOT__calc_ipc__26__Vfuncout = 0.0;
                                    goto __Vlabel21;
                                }
                                __Vlabel21: ;
                            }
                        }(), __Vfunc_tb_cpu__DOT__calc_ipc__26__Vfuncout),
                      32,vlSelf->tb_cpu__DOT__stall_count,
                      32,vlSelf->tb_cpu__DOT__branch_taken_count,
                      32,vlSelf->tb_cpu__DOT__jump_taken_count,
                      32,vlSelf->tb_cpu__DOT__total_forward_count);
            VL_FCLOSE_I(vlSelf->tb_cpu__DOT__trace_file); VL_FCLOSE_I(vlSelf->tb_cpu__DOT__summary_file); VL_FCLOSE_I(vlSelf->tb_cpu__DOT__instruction_file); VL_FINISH_MT("../rtl/../tb/tb_cpu.sv", 71, "");
        }
    }
}

void Vtb_cpu___024root___nba_sequent__TOP__0(Vtb_cpu___024root* vlSelf);

void Vtb_cpu___024root___eval_nba(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_cpu___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_cpu___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_cpu___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vtb_cpu___024root___timing_resume(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h605b3eaf__0.resume("@(posedge tb_cpu.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_cpu___024root___timing_commit(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h605b3eaf__0.commit("@(posedge tb_cpu.clk)");
    }
}

void Vtb_cpu___024root___eval_triggers__act(Vtb_cpu___024root* vlSelf);

bool Vtb_cpu___024root___eval_phase__act(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_cpu___024root___eval_triggers__act(vlSelf);
    Vtb_cpu___024root___timing_commit(vlSelf);
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
            VL_FATAL_MT("../rtl/../tb/tb_cpu.sv", 4, "", "NBA region did not converge.");
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
                VL_FATAL_MT("../rtl/../tb/tb_cpu.sv", 4, "", "Active region did not converge.");
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
