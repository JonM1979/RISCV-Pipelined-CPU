// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_trap_halt.h for the primary calling header

#include "Vtb_trap_halt__pch.h"
#include "Vtb_trap_halt___024root.h"

VL_ATTR_COLD void Vtb_trap_halt___024root___eval_static__TOP(Vtb_trap_halt___024root* vlSelf);

VL_ATTR_COLD void Vtb_trap_halt___024root___eval_static(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_static\n"); );
    // Body
    Vtb_trap_halt___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_trap_halt___024root___eval_static__TOP(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_trap_halt__DOT__clk = 0U;
}

VL_ATTR_COLD void Vtb_trap_halt___024root___eval_initial__TOP(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__unnamedblk1__DOT__i;
    tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__unnamedblk1__DOT__i = 0;
    IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i;
    tb_trap_halt__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__unnamedblk1__DOT__i)) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__mem[(0x3ffU 
                                                                  & tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__unnamedblk1__DOT__i)] = 0U;
        tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__unnamedblk1__DOT__i);
    }
    __Vtemp_2[0U] = 0x2e686578U;
    __Vtemp_2[1U] = 0x6772616dU;
    __Vtemp_2[2U] = 0x70726fU;
    VL_READMEM_N(true, 32, 1024, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_2)
                 ,  &(vlSelf->tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__mem)
                 , 0, ~0ULL);
    tb_trap_halt__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, tb_trap_halt__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i)) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem[(0x3ffU 
                                                             & tb_trap_halt__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i)] = 0U;
        tb_trap_halt__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + tb_trap_halt__DOT__uut__DOT__dmem__DOT__unnamedblk1__DOT__i);
    }
    VL_READMEM_N(true, 32, 1024, 0, std::string{"data.hex"}
                 ,  &(vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_trap_halt___024root___eval_final(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trap_halt___024root___dump_triggers__stl(Vtb_trap_halt___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_trap_halt___024root___eval_phase__stl(Vtb_trap_halt___024root* vlSelf);

VL_ATTR_COLD void Vtb_trap_halt___024root___eval_settle(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_settle\n"); );
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
            Vtb_trap_halt___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/../tb/tb_trap_halt.sv", 30, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_trap_halt___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trap_halt___024root___dump_triggers__stl(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*0:0*/, 256> Vtb_trap_halt__ConstPool__TABLE_h246a8395_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vtb_trap_halt__ConstPool__TABLE_h535cfbdd_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vtb_trap_halt__ConstPool__TABLE_hbc1849bd_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_trap_halt__ConstPool__TABLE_hfcff80f4_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_trap_halt__ConstPool__TABLE_hf2dcfc1f_0;
extern const VlUnpacked<CData/*0:0*/, 16384> Vtb_trap_halt__ConstPool__TABLE_h8b25f60c_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vtb_trap_halt__ConstPool__TABLE_hd161f257_0;
extern const VlUnpacked<CData/*3:0*/, 16> Vtb_trap_halt__ConstPool__TABLE_heb27db18_0;

VL_ATTR_COLD void Vtb_trap_halt___024root___stl_sequent__TOP__0(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___stl_sequent__TOP__0\n"); );
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
    // Body
    vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_done 
        = (1U & ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index) 
                 >> 8U));
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
    vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__current 
        = vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__counters
        [(0xffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc 
                   >> 2U))];
    __Vtableidx3 = (((0U == (7U & (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                   >> 0xcU))) << 7U) 
                    | (0x7fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr));
    vlSelf->tb_trap_halt__DOT__uut__DOT__reg_write 
        = Vtb_trap_halt__ConstPool__TABLE_h246a8395_0
        [__Vtableidx3];
    vlSelf->tb_trap_halt__DOT__uut__DOT__wb_we = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_reg_write) 
                                                  & ((~ 
                                                      ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_exception) 
                                                       | (0U 
                                                          == (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd)))) 
                                                     & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_valid)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__is_jalr = (IData)(
                                                           (0x67U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    tb_trap_halt__DOT__uut__DOT__dec__DOT__imm_i = 
        (((- (IData)((vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                      >> 0x1fU))) << 0xcU) | (vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr 
                                              >> 0x14U));
    vlSelf->tb_trap_halt__DOT__trap_valid = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_exception) 
                                             & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_valid));
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
    vlSelf->tb_trap_halt__DOT__uut__DOT__instr = vlSelf->tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__mem
        [(0x3ffU & (vlSelf->tb_trap_halt__DOT__uut__DOT__pc 
                    >> 2U))];
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
    tb_trap_halt__DOT__uut__DOT__mem_out_of_range = 
        (((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load) 
          | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_store)) 
         & (0x1000U <= vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result));
    tb_trap_halt__DOT__uut__DOT__dec__DOT____VdfgTmp_h92ba0c04__0 
        = (IData)((0x73U == (0x707fU & vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr)));
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data 
        = ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_link)
            ? vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_pc_plus_4
            : vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result);
    vlSelf->tb_trap_halt__DOT__uut__DOT__wb_data = 
        ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_load)
          ? vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_read_data
          : ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_link)
              ? vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_pc_plus_4
              : vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_result));
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward 
        = ((~ (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load)) 
           & (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_reg_write));
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
    vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold 
        = ((IData)(vlSelf->tb_trap_halt__DOT__trap_valid) 
           | (IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__trapped));
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
    vlSelf->tb_trap_halt__DOT__uut__DOT__next_pc = 
        ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken)
          ? vlSelf->tb_trap_halt__DOT__uut__DOT__control_target
          : ((IData)(vlSelf->tb_trap_halt__DOT__uut__DOT__predict_taken)
              ? vlSelf->tb_trap_halt__DOT__uut__DOT__predict_target
              : ((IData)(4U) + vlSelf->tb_trap_halt__DOT__uut__DOT__pc)));
}

VL_ATTR_COLD void Vtb_trap_halt___024root___eval_stl(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_trap_halt___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_trap_halt___024root___eval_triggers__stl(Vtb_trap_halt___024root* vlSelf);

VL_ATTR_COLD bool Vtb_trap_halt___024root___eval_phase__stl(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_trap_halt___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_trap_halt___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trap_halt___024root___dump_triggers__act(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_trap_halt.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_trap_halt___024root___dump_triggers__nba(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_trap_halt.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_trap_halt___024root___ctor_var_reset(Vtb_trap_halt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_trap_halt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_trap_halt___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_trap_halt__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__trap_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__pc_at_trap = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__cause_at_trap = VL_RAND_RESET_I(4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__stall = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__control_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__control_target = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__instr = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__predict_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__predict_target = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__trapped = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__trap_hold = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_instr = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_pc_plus_4 = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__if_id_predict_target = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__alu_ctrl = VL_RAND_RESET_I(4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__is_jalr = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs1 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__uses_rs2 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__reg_write = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_size = VL_RAND_RESET_I(2);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_unsigned = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_exception = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_cause = VL_RAND_RESET_I(4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_pc_plus_4 = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd1 = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd2 = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs1 = VL_RAND_RESET_I(5);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_rs2 = VL_RAND_RESET_I(5);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_funct3 = VL_RAND_RESET_I(3);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl = VL_RAND_RESET_I(4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_itype = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_load = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_store = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_branch = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jal = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_jalr = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_lui = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_is_auipc = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs1 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs2 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_reg_write = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_mem_size = VL_RAND_RESET_I(2);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_mem_unsigned = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_exception = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_cause = VL_RAND_RESET_I(4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_predict_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__id_ex_predict_target = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a_sel = VL_RAND_RESET_I(2);
    vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b_sel = VL_RAND_RESET_I(2);
    vlSelf->tb_trap_halt__DOT__uut__DOT__forward_a = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__forward_b = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__alu_result = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__branch_cond_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__actual_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__actual_target = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_result = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_store_data = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_pc_plus_4 = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_link = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_reg_write = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_load = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_is_store = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size = VL_RAND_RESET_I(2);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_mem_unsigned = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_exception = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_cause = VL_RAND_RESET_I(4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_read_data = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_exception = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_cause = VL_RAND_RESET_I(4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_pc_plus_4 = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_result = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_read_data = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_rd = VL_RAND_RESET_I(5);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_link = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_reg_write = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_is_load = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_exception = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__mem_wb_cause = VL_RAND_RESET_I(4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__wb_we = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__wb_data = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__load_byte = VL_RAND_RESET_I(8);
    vlSelf->tb_trap_halt__DOT__uut__DOT__load_half = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__counters[__Vi0] = VL_RAND_RESET_I(2);
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__current = VL_RAND_RESET_I(2);
    vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index = VL_RAND_RESET_I(9);
    vlSelf->tb_trap_halt__DOT__uut__DOT__bp__DOT__init_done = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__rf__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__byte_en = VL_RAND_RESET_I(4);
    vlSelf->tb_trap_halt__DOT__uut__DOT__dmem__DOT__store_word = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_0_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_1_0 = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_2_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_3_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_4_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_5_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_6_0 = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_7_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_8_0 = VL_RAND_RESET_I(32);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_9_0 = VL_RAND_RESET_I(1);
    vlSelf->tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_10_0 = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__tb_trap_halt__DOT__clk__0 = VL_RAND_RESET_I(1);
}
