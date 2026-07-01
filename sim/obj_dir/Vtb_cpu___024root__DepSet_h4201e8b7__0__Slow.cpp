// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cpu.h for the primary calling header

#include "Vtb_cpu__pch.h"
#include "Vtb_cpu___024root.h"

VL_ATTR_COLD void Vtb_cpu___024root___eval_static(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_cpu___024root___eval_initial__TOP(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i;
    tb_cpu__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i = 0;
    // Body
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0U] = 0xa00093U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[1U] = 0x1400113U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[2U] = 0x2081b3U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[3U] = 0x118233U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[4U] = 0x100293U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[5U] = 0x218333U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[6U] = 0x6203b3U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[7U] = 0x438433U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[8U] = 0x802223U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[9U] = 0x402483U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0xaU] = 0x148533U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0xbU] = 0x500593U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0xcU] = 0xb58463U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0xdU] = 0x6300613U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0xeU] = 0xc00613U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0xfU] = 0xc02423U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x10U] = 0x802683U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x11U] = 0xc68463U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x12U] = 0x4d00713U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x13U] = 0xe00713U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x14U] = 0xc007efU;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x15U] = 0x4200813U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x16U] = 0x4d00893U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x17U] = 0x178913U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x18U] = 0x7b00013U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x19U] = 0x1300993U;
    vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[0x1aU] = 0x500013U;
    tb_cpu__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, tb_cpu__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i)) {
        vlSelf->tb_cpu__DOT__uut__DOT__dmem__DOT__mem[(0xffU 
                                                       & tb_cpu__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i)] = 0U;
        tb_cpu__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + tb_cpu__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i);
    }
}

VL_ATTR_COLD void Vtb_cpu___024root___eval_final(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu___024root___dump_triggers__stl(Vtb_cpu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_cpu___024root___eval_phase__stl(Vtb_cpu___024root* vlSelf);

VL_ATTR_COLD void Vtb_cpu___024root___eval_settle(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_cpu___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/../tb/tb_cpu.sv", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_cpu___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu___024root___dump_triggers__stl(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_cpu___024root___stl_sequent__TOP__0(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ tb_cpu__DOT__id_ex_valid_for_forwarding;
    tb_cpu__DOT__id_ex_valid_for_forwarding = 0;
    CData/*0:0*/ tb_cpu__DOT__id_ex_uses_rs1;
    tb_cpu__DOT__id_ex_uses_rs1 = 0;
    CData/*0:0*/ tb_cpu__DOT__id_ex_uses_rs2;
    tb_cpu__DOT__id_ex_uses_rs2 = 0;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__ex_mem_forward_data;
    tb_cpu__DOT__uut__DOT__ex_mem_forward_data = 0;
    CData/*0:0*/ tb_cpu__DOT__uut__DOT__ex_mem_regwrite;
    tb_cpu__DOT__uut__DOT__ex_mem_regwrite = 0;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b;
    tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b = 0;
    // Body
    vlSelf->tb_cpu__DOT__uut__DOT__imm = ((0x40U & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                           ? ((0x20U 
                                               & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                               ? ((0x10U 
                                                   & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                   ? 0U
                                                   : 
                                                  ((8U 
                                                    & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                    ? 
                                                   ((4U 
                                                     & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                    >> 0x1fU))) 
                                                        << 0x15U) 
                                                       | ((0x100000U 
                                                           & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                              >> 0xbU)) 
                                                          | ((0xff000U 
                                                              & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr) 
                                                             | ((0x800U 
                                                                 & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                    >> 9U)) 
                                                                | (0x7feU 
                                                                   & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                      >> 0x14U))))))
                                                       : 0U)
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                    >> 0x1fU))) 
                                                        << 0xdU) 
                                                       | ((0x1000U 
                                                           & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                              >> 0x13U)) 
                                                          | ((0x800U 
                                                              & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                 << 4U)) 
                                                             | ((0x7e0U 
                                                                 & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                    >> 0x14U)) 
                                                                | (0x1eU 
                                                                   & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                      >> 7U))))))
                                                       : 0U)
                                                      : 0U))))
                                               : 0U)
                                           : ((0x20U 
                                               & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                               ? ((0x10U 
                                                   & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                   ? 
                                                  ((8U 
                                                    & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                     ? 
                                                    ((2U 
                                                      & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                       ? 
                                                      (0xfffff000U 
                                                       & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                       : 0U)
                                                      : 0U)
                                                     : 0U))
                                                   : 
                                                  ((8U 
                                                    & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                       ? 
                                                      (((- (IData)(
                                                                   (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                    >> 0x1fU))) 
                                                        << 0xcU) 
                                                       | ((0xfe0U 
                                                           & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                              >> 0x14U)) 
                                                          | (0x1fU 
                                                             & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                >> 7U))))
                                                       : 0U)
                                                      : 0U))))
                                               : ((8U 
                                                   & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                                   >> 0x1fU))) 
                                                       << 0xcU) 
                                                      | (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                         >> 0x14U))
                                                      : 0U)
                                                     : 0U)))));
    vlSelf->tb_cpu__DOT__uut__DOT__alu_ctrl = 0U;
    if ((0x33U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr))) {
        vlSelf->tb_cpu__DOT__uut__DOT__alu_ctrl = (
                                                   (0x4000U 
                                                    & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                      ? 9U
                                                      : 8U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                      ? 
                                                     ((0x20U 
                                                       == 
                                                       (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                        >> 0x19U))
                                                       ? 7U
                                                       : 6U)
                                                      : 5U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                     ? 
                                                    ((0x1000U 
                                                      & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                      ? 4U
                                                      : 3U)
                                                     : 
                                                    ((0x1000U 
                                                      & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)
                                                      ? 2U
                                                      : 
                                                     ((0x20U 
                                                       == 
                                                       (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                        >> 0x19U))
                                                       ? 1U
                                                       : 0U))));
    } else if (((0x13U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)) 
                | ((3U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)) 
                   | (0x23U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr))))) {
        vlSelf->tb_cpu__DOT__uut__DOT__alu_ctrl = 0U;
    }
    vlSelf->tb_cpu__DOT__uut__DOT__instr = vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem
        [(0xffU & (vlSelf->tb_cpu__DOT__uut__DOT__pc 
                   >> 2U))];
    vlSelf->tb_cpu__DOT__uut__DOT__jal_target = (vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm 
                                                 + vlSelf->tb_cpu__DOT__uut__DOT__id_ex_pc);
    vlSelf->tb_cpu__DOT__uut__DOT__stall = ((3U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode)) 
                                            & ((0U 
                                                != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd)) 
                                               & (((IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd) 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                       >> 0xfU))) 
                                                  | ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd) 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                                         >> 0x14U))))));
    vlSelf->tb_cpu__DOT__uut__DOT__mem_read_data = 
        ((3U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode))
          ? vlSelf->tb_cpu__DOT__uut__DOT__dmem__DOT__mem
         [(0xffU & (vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result 
                    >> 2U))] : 0U);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_use_imm = ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_itype) 
                                                 | ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_load) 
                                                    | (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_store)));
    tb_cpu__DOT__id_ex_valid_for_forwarding = ((0U 
                                                != vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr) 
                                               & (0x500013U 
                                                  != vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr));
    vlSelf->tb_cpu__DOT__uut__DOT__wb_data = ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_is_jal)
                                               ? vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_pc_plus_4
                                               : vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result);
    tb_cpu__DOT__uut__DOT__ex_mem_forward_data = ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_is_jal)
                                                   ? vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_pc_plus_4
                                                   : vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result);
    vlSelf->tb_cpu__DOT__uut__DOT__wb_we = ((0x33U 
                                             == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)) 
                                            | ((0x13U 
                                                == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)) 
                                               | ((3U 
                                                   == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)) 
                                                  | (0x6fU 
                                                     == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)))));
    tb_cpu__DOT__uut__DOT__ex_mem_regwrite = ((0x33U 
                                               == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)) 
                                              | ((0x13U 
                                                  == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)) 
                                                 | (0x6fU 
                                                    == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode))));
    tb_cpu__DOT__id_ex_uses_rs1 = ((IData)(tb_cpu__DOT__id_ex_valid_for_forwarding) 
                                   & ([&]() {
                vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode 
                    = vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode;
                {
                    if ((0x40U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                        if ((0x20U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                            if ((0x10U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                                vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            } else if ((8U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                                vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            } else if ((4U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                                vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            } else if ((2U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                                if ((1U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                                    vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 1U;
                                    goto __Vlabel1;
                                } else {
                                    vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                                    goto __Vlabel1;
                                }
                            } else {
                                vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                                goto __Vlabel1;
                            }
                        } else {
                            vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                    } else if ((8U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                        vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    } else if ((4U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                        vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    } else if ((2U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                        if ((1U & (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode))) {
                            vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 1U;
                            goto __Vlabel1;
                        } else {
                            vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                    } else {
                        vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    __Vlabel1: ;
                }
            }(), (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout)));
    tb_cpu__DOT__id_ex_uses_rs2 = ((IData)(tb_cpu__DOT__id_ex_valid_for_forwarding) 
                                   & ([&]() {
                vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs2__1__opcode 
                    = vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode;
                {
                    if ((((0x33U == (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs2__1__opcode)) 
                          || (0x23U == (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs2__1__opcode))) 
                         || (0x63U == (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs2__1__opcode)))) {
                        vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs2__1__Vfuncout = 1U;
                        goto __Vlabel2;
                    } else {
                        vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs2__1__Vfuncout = 0U;
                        goto __Vlabel2;
                    }
                    __Vlabel2: ;
                }
            }(), (IData)(vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs2__1__Vfuncout)));
    vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel = 0U;
    if ((((IData)(tb_cpu__DOT__uut__DOT__ex_mem_regwrite) 
          & (0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd))) 
         & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd) 
            == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1)))) {
        vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel = 2U;
    } else if ((((IData)(vlSelf->tb_cpu__DOT__uut__DOT__wb_we) 
                 & (0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd))) 
                & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd) 
                   == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1)))) {
        vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel = 1U;
    }
    vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel = 0U;
    if ((((IData)(tb_cpu__DOT__uut__DOT__ex_mem_regwrite) 
          & (0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd))) 
         & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd) 
            == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2)))) {
        vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel = 2U;
    } else if ((((IData)(vlSelf->tb_cpu__DOT__uut__DOT__wb_we) 
                 & (0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd))) 
                & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd) 
                   == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2)))) {
        vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel = 1U;
    }
    vlSelf->tb_cpu__DOT__ex_mem_forward_a_event = ((IData)(tb_cpu__DOT__id_ex_uses_rs1) 
                                                   & (2U 
                                                      == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel)));
    vlSelf->tb_cpu__DOT__mem_wb_forward_a_event = ((IData)(tb_cpu__DOT__id_ex_uses_rs1) 
                                                   & (1U 
                                                      == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel)));
    vlSelf->tb_cpu__DOT__uut__DOT__forward_a = ((2U 
                                                 == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel))
                                                 ? tb_cpu__DOT__uut__DOT__ex_mem_forward_data
                                                 : 
                                                ((1U 
                                                  == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel))
                                                  ? vlSelf->tb_cpu__DOT__uut__DOT__wb_data
                                                  : vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1));
    vlSelf->tb_cpu__DOT__ex_mem_forward_b_event = ((IData)(tb_cpu__DOT__id_ex_uses_rs2) 
                                                   & (2U 
                                                      == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel)));
    vlSelf->tb_cpu__DOT__mem_wb_forward_b_event = ((IData)(tb_cpu__DOT__id_ex_uses_rs2) 
                                                   & (1U 
                                                      == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel)));
    vlSelf->tb_cpu__DOT__uut__DOT__forward_b = ((2U 
                                                 == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel))
                                                 ? tb_cpu__DOT__uut__DOT__ex_mem_forward_data
                                                 : 
                                                ((1U 
                                                  == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel))
                                                  ? vlSelf->tb_cpu__DOT__uut__DOT__wb_data
                                                  : vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2));
    vlSelf->tb_cpu__DOT__uut__DOT__branch_cond_taken = 0U;
    if (vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_branch) {
        if ((0U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_funct3))) {
            if ((vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                 == vlSelf->tb_cpu__DOT__uut__DOT__forward_b)) {
                vlSelf->tb_cpu__DOT__uut__DOT__branch_cond_taken = 1U;
            }
        } else if ((1U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_funct3))) {
            if ((vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                 != vlSelf->tb_cpu__DOT__uut__DOT__forward_b)) {
                vlSelf->tb_cpu__DOT__uut__DOT__branch_cond_taken = 1U;
            }
        } else {
            vlSelf->tb_cpu__DOT__uut__DOT__branch_cond_taken = 0U;
        }
    }
    tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b 
        = ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_use_imm)
            ? vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm
            : vlSelf->tb_cpu__DOT__uut__DOT__forward_b);
    vlSelf->tb_cpu__DOT__uut__DOT__control_taken = 
        ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__branch_cond_taken) 
         | (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_jal));
    vlSelf->tb_cpu__DOT__uut__DOT__alu_result = ((8U 
                                                  & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                     ? 
                                                    (vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                                                     & tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b)
                                                     : 
                                                    (vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                                                     | tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b))))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelf->tb_cpu__DOT__uut__DOT__forward_a, 
                                                                   (0x1fU 
                                                                    & tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b))
                                                     : 
                                                    (vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                                                     >> 
                                                     (0x1fU 
                                                      & tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                     ? 
                                                    (vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                                                     ^ tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b)
                                                     : 
                                                    ((vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                                                      < tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b)
                                                      ? 1U
                                                      : 0U)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                     ? 
                                                    (VL_LTS_III(32, vlSelf->tb_cpu__DOT__uut__DOT__forward_a, tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                                                     << 
                                                     (0x1fU 
                                                      & tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl))
                                                     ? 
                                                    (vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                                                     - tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b)
                                                     : 
                                                    (vlSelf->tb_cpu__DOT__uut__DOT__forward_a 
                                                     + tb_cpu__DOT__uut__DOT____Vcellinp__alu_inst__b)))));
}

VL_ATTR_COLD void Vtb_cpu___024root___eval_stl(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_cpu___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_cpu___024root___eval_triggers__stl(Vtb_cpu___024root* vlSelf);

VL_ATTR_COLD bool Vtb_cpu___024root___eval_phase__stl(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_cpu___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_cpu___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu___024root___dump_triggers__act(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_cpu.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_cpu.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu___024root___dump_triggers__nba(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_cpu.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_cpu.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_cpu___024root___ctor_var_reset(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_cpu__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__cycle_count = 0;
    vlSelf->tb_cpu__DOT__retired_count = 0;
    vlSelf->tb_cpu__DOT__stall_count = 0;
    vlSelf->tb_cpu__DOT__control_count = 0;
    vlSelf->tb_cpu__DOT__load_use_stall_count = 0;
    vlSelf->tb_cpu__DOT__branch_taken_count = 0;
    vlSelf->tb_cpu__DOT__jump_taken_count = 0;
    vlSelf->tb_cpu__DOT__flush_count = 0;
    vlSelf->tb_cpu__DOT__rtype_count = 0;
    vlSelf->tb_cpu__DOT__itype_count = 0;
    vlSelf->tb_cpu__DOT__load_count = 0;
    vlSelf->tb_cpu__DOT__store_count = 0;
    vlSelf->tb_cpu__DOT__branch_instr_count = 0;
    vlSelf->tb_cpu__DOT__jal_instr_count = 0;
    vlSelf->tb_cpu__DOT__ex_mem_forward_a_count = 0;
    vlSelf->tb_cpu__DOT__ex_mem_forward_b_count = 0;
    vlSelf->tb_cpu__DOT__mem_wb_forward_a_count = 0;
    vlSelf->tb_cpu__DOT__mem_wb_forward_b_count = 0;
    vlSelf->tb_cpu__DOT__total_forward_count = 0;
    vlSelf->tb_cpu__DOT__summary_file = 0;
    vlSelf->tb_cpu__DOT__instruction_file = 0;
    vlSelf->tb_cpu__DOT__trace_file = 0;
    vlSelf->tb_cpu__DOT__ex_mem_forward_a_event = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__ex_mem_forward_b_event = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__mem_wb_forward_a_event = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__mem_wb_forward_b_event = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__control_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__if_id_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__alu_ctrl = VL_RAND_RESET_I(4);
    vlSelf->tb_cpu__DOT__uut__DOT__wb_we = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__wb_data = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode = VL_RAND_RESET_I(7);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl = VL_RAND_RESET_I(4);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_itype = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_load = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_store = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_branch = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_jal = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_funct3 = VL_RAND_RESET_I(3);
    vlSelf->tb_cpu__DOT__uut__DOT__forward_a = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__forward_b = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel = VL_RAND_RESET_I(2);
    vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel = VL_RAND_RESET_I(2);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode = VL_RAND_RESET_I(7);
    vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode = VL_RAND_RESET_I(7);
    vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_pc_plus_4 = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_is_jal = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_use_imm = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__branch_cond_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__jal_target = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_store_data = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_pc_plus_4 = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_is_jal = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_instr = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__mem_read_data = VL_RAND_RESET_I(32);
    vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_cpu__DOT__uut__DOT__rf__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_cpu__DOT__uut__DOT__dmem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout = 0;
    vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode = VL_RAND_RESET_I(7);
    vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs2__1__Vfuncout = 0;
    vlSelf->__Vfunc_tb_cpu__DOT__instr_uses_rs2__1__opcode = VL_RAND_RESET_I(7);
    vlSelf->__Vdlyvval__tb_cpu__DOT__clk__v0 = VL_RAND_RESET_I(1);
    vlSelf->__Vdlyvset__tb_cpu__DOT__clk__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_cpu__DOT__clk__0 = VL_RAND_RESET_I(1);
}
