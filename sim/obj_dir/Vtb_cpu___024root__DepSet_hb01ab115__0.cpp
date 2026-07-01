// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cpu.h for the primary calling header

#include "Vtb_cpu__pch.h"
#include "Vtb_cpu__Syms.h"
#include "Vtb_cpu___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_cpu___024root___eval_initial__TOP__Vtiming__0(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ tb_cpu__DOT____Vrepeat0;
    tb_cpu__DOT____Vrepeat0 = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<6>/*191:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    // Body
    __Vtemp_1[0U] = 0x2e6c6f67U;
    __Vtemp_1[1U] = 0x72616365U;
    __Vtemp_1[2U] = 0x74U;
    vlSelf->tb_cpu__DOT__trace_file = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(3, __Vtemp_1)
                                                  , 
                                                  std::string{"w"});
    ;
    __Vtemp_2[0U] = 0x2e6c6f67U;
    __Vtemp_2[1U] = 0x72616365U;
    __Vtemp_2[2U] = 0x6f6e5f74U;
    __Vtemp_2[3U] = 0x75637469U;
    __Vtemp_2[4U] = 0x6e737472U;
    __Vtemp_2[5U] = 0x69U;
    vlSelf->tb_cpu__DOT__instruction_file = VL_FOPEN_NN(
                                                        VL_CVT_PACK_STR_NW(6, __Vtemp_2)
                                                        , 
                                                        std::string{"w"});
    ;
    __Vtemp_3[0U] = 0x2e6c6f67U;
    __Vtemp_3[1U] = 0x6d617279U;
    __Vtemp_3[2U] = 0x73756dU;
    vlSelf->tb_cpu__DOT__summary_file = VL_FOPEN_NN(
                                                    VL_CVT_PACK_STR_NW(3, __Vtemp_3)
                                                    , 
                                                    std::string{"w"});
    ;
    if (VL_UNLIKELY((0U == vlSelf->tb_cpu__DOT__trace_file))) {
        VL_WRITEF("[%0t] %%Fatal: tb_init_tasks.svh:11: Assertion failed in %Ntb_cpu.open_output_files: Could not open trace.log\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("../tb/tb_init_tasks.svh", 11, "");
    }
    if (VL_UNLIKELY((0U == vlSelf->tb_cpu__DOT__summary_file))) {
        VL_WRITEF("[%0t] %%Fatal: tb_init_tasks.svh:14: Assertion failed in %Ntb_cpu.open_output_files: Could not open summary.log\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("../tb/tb_init_tasks.svh", 14, "");
    }
    if (VL_UNLIKELY((0U == vlSelf->tb_cpu__DOT__instruction_file))) {
        VL_WRITEF("[%0t] %%Fatal: tb_init_tasks.svh:17: Assertion failed in %Ntb_cpu.open_output_files: Could not open instruction_trace.log\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("../tb/tb_init_tasks.svh", 17, "");
    }
    vlSelf->tb_cpu__DOT__cycle_count = 0U;
    vlSelf->tb_cpu__DOT__retired_count = 0U;
    vlSelf->tb_cpu__DOT__stall_count = 0U;
    vlSelf->tb_cpu__DOT__control_count = 0U;
    vlSelf->tb_cpu__DOT__load_use_stall_count = 0U;
    vlSelf->tb_cpu__DOT__branch_taken_count = 0U;
    vlSelf->tb_cpu__DOT__jump_taken_count = 0U;
    vlSelf->tb_cpu__DOT__flush_count = 0U;
    vlSelf->tb_cpu__DOT__rtype_count = 0U;
    vlSelf->tb_cpu__DOT__itype_count = 0U;
    vlSelf->tb_cpu__DOT__load_count = 0U;
    vlSelf->tb_cpu__DOT__store_count = 0U;
    vlSelf->tb_cpu__DOT__branch_instr_count = 0U;
    vlSelf->tb_cpu__DOT__jal_instr_count = 0U;
    vlSelf->tb_cpu__DOT__ex_mem_forward_a_count = 0U;
    vlSelf->tb_cpu__DOT__ex_mem_forward_b_count = 0U;
    vlSelf->tb_cpu__DOT__mem_wb_forward_a_count = 0U;
    vlSelf->tb_cpu__DOT__mem_wb_forward_b_count = 0U;
    vlSelf->tb_cpu__DOT__total_forward_count = 0U;
    vlSelf->tb_cpu__DOT__clk = 0U;
    vlSelf->tb_cpu__DOT__reset = 1U;
    co_await vlSelf->__VdlySched.delay(0xaULL, nullptr, 
                                       "../rtl/../tb/tb_cpu.sv", 
                                       37);
    vlSelf->tb_cpu__DOT__reset = 0U;
    tb_cpu__DOT____Vrepeat0 = 0x12cU;
    while (VL_LTS_III(32, 0U, tb_cpu__DOT____Vrepeat0)) {
        co_await vlSelf->__VtrigSched_h605b3eaf__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_cpu.clk)", 
                                                           "../rtl/../tb/tb_cpu.sv", 
                                                           42);
        tb_cpu__DOT____Vrepeat0 = (tb_cpu__DOT____Vrepeat0 
                                   - (IData)(1U));
    }
    VL_WRITEF("[%0t] %%Fatal: tb_cpu.sv:44: Assertion failed in %Ntb_cpu: TIMEOUT: HALT instruction did not reach WB stage\n",
              64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
    VL_STOP_MT("../rtl/../tb/tb_cpu.sv", 44, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu___024root___dump_triggers__act(Vtb_cpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_cpu___024root___eval_triggers__act(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_cpu__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_cpu__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, ((~ (IData)(vlSelf->tb_cpu__DOT__clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_cpu__DOT__clk__0)));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_cpu__DOT__clk__0 
        = vlSelf->tb_cpu__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_cpu___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_cpu___024root___nba_sequent__TOP__0(Vtb_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu___024root___nba_sequent__TOP__0\n"); );
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
    IData/*31:0*/ __Vdly__tb_cpu__DOT__uut__DOT__pc;
    __Vdly__tb_cpu__DOT__uut__DOT__pc = 0;
    CData/*4:0*/ __Vdlyvdim0__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0;
    __Vdlyvdim0__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0;
    __Vdlyvval__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0;
    __Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 0;
    CData/*7:0*/ __Vdlyvdim0__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0;
    __Vdlyvdim0__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0;
    __Vdlyvval__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0;
    __Vdlyvset__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0 = 0;
    // Body
    __Vdly__tb_cpu__DOT__uut__DOT__pc = vlSelf->tb_cpu__DOT__uut__DOT__pc;
    __Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 0U;
    __Vdlyvset__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0 = 0U;
    if (((IData)(vlSelf->tb_cpu__DOT__uut__DOT__wb_we) 
         & (0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd)))) {
        __Vdlyvval__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 
            = vlSelf->tb_cpu__DOT__uut__DOT__wb_data;
        __Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 = 1U;
        __Vdlyvdim0__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0 
            = vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd;
    }
    if ((0x23U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode))) {
        __Vdlyvval__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0 
            = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_store_data;
        __Vdlyvset__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0 = 1U;
        __Vdlyvdim0__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0 
            = (0xffU & (vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result 
                        >> 2U));
    }
    if (vlSelf->tb_cpu__DOT__reset) {
        __Vdly__tb_cpu__DOT__uut__DOT__pc = 0U;
    } else if (vlSelf->tb_cpu__DOT__uut__DOT__control_taken) {
        __Vdly__tb_cpu__DOT__uut__DOT__pc = vlSelf->tb_cpu__DOT__uut__DOT__jal_target;
    } else if ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__stall)))) {
        __Vdly__tb_cpu__DOT__uut__DOT__pc = ((IData)(4U) 
                                             + vlSelf->tb_cpu__DOT__uut__DOT__pc);
    }
    if ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__reset)))) {
        vlSelf->tb_cpu__DOT__cycle_count = ((IData)(1U) 
                                            + vlSelf->tb_cpu__DOT__cycle_count);
        if (((0U != vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr) 
             & (0x500013U != vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr))) {
            if ((0x40U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                if ((0x20U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                    if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                            if ((4U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                                if ((2U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                                    if ((1U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                                        vlSelf->tb_cpu__DOT__jal_instr_count 
                                            = ((IData)(1U) 
                                               + vlSelf->tb_cpu__DOT__jal_instr_count);
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                                if ((1U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                                    vlSelf->tb_cpu__DOT__branch_instr_count 
                                        = ((IData)(1U) 
                                           + vlSelf->tb_cpu__DOT__branch_instr_count);
                                }
                            }
                        }
                    }
                }
            } else if ((0x20U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                if ((0x10U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                    if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                                if ((1U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                                    vlSelf->tb_cpu__DOT__rtype_count 
                                        = ((IData)(1U) 
                                           + vlSelf->tb_cpu__DOT__rtype_count);
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                                     >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                            if ((1U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                                vlSelf->tb_cpu__DOT__store_count 
                                    = ((IData)(1U) 
                                       + vlSelf->tb_cpu__DOT__store_count);
                            }
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                            if ((1U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                                vlSelf->tb_cpu__DOT__itype_count 
                                    = ((IData)(1U) 
                                       + vlSelf->tb_cpu__DOT__itype_count);
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                                 >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                        if ((1U & (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode))) {
                            vlSelf->tb_cpu__DOT__load_count 
                                = ((IData)(1U) + vlSelf->tb_cpu__DOT__load_count);
                        }
                    }
                }
            }
            vlSelf->tb_cpu__DOT__retired_count = ((IData)(1U) 
                                                  + vlSelf->tb_cpu__DOT__retired_count);
        }
        if (vlSelf->tb_cpu__DOT__uut__DOT__stall) {
            vlSelf->tb_cpu__DOT__stall_count = ((IData)(1U) 
                                                + vlSelf->tb_cpu__DOT__stall_count);
            vlSelf->tb_cpu__DOT__load_use_stall_count 
                = ((IData)(1U) + vlSelf->tb_cpu__DOT__load_use_stall_count);
        }
        if (vlSelf->tb_cpu__DOT__uut__DOT__control_taken) {
            vlSelf->tb_cpu__DOT__control_count = ((IData)(1U) 
                                                  + vlSelf->tb_cpu__DOT__control_count);
            vlSelf->tb_cpu__DOT__flush_count = ((IData)(1U) 
                                                + vlSelf->tb_cpu__DOT__flush_count);
        }
        if (vlSelf->tb_cpu__DOT__uut__DOT__branch_cond_taken) {
            vlSelf->tb_cpu__DOT__branch_taken_count 
                = ((IData)(1U) + vlSelf->tb_cpu__DOT__branch_taken_count);
        }
        if (vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_jal) {
            vlSelf->tb_cpu__DOT__jump_taken_count = 
                ((IData)(1U) + vlSelf->tb_cpu__DOT__jump_taken_count);
        }
        if (vlSelf->tb_cpu__DOT__ex_mem_forward_a_event) {
            vlSelf->tb_cpu__DOT__ex_mem_forward_a_count 
                = ((IData)(1U) + vlSelf->tb_cpu__DOT__ex_mem_forward_a_count);
        }
        if (vlSelf->tb_cpu__DOT__ex_mem_forward_b_event) {
            vlSelf->tb_cpu__DOT__ex_mem_forward_b_count 
                = ((IData)(1U) + vlSelf->tb_cpu__DOT__ex_mem_forward_b_count);
        }
        if (vlSelf->tb_cpu__DOT__mem_wb_forward_a_event) {
            vlSelf->tb_cpu__DOT__mem_wb_forward_a_count 
                = ((IData)(1U) + vlSelf->tb_cpu__DOT__mem_wb_forward_a_count);
        }
        if (vlSelf->tb_cpu__DOT__mem_wb_forward_b_event) {
            vlSelf->tb_cpu__DOT__mem_wb_forward_b_count 
                = ((IData)(1U) + vlSelf->tb_cpu__DOT__mem_wb_forward_b_count);
        }
        vlSelf->tb_cpu__DOT__total_forward_count = 
            ((((vlSelf->tb_cpu__DOT__total_forward_count 
                + (IData)(vlSelf->tb_cpu__DOT__ex_mem_forward_a_event)) 
               + (IData)(vlSelf->tb_cpu__DOT__ex_mem_forward_b_event)) 
              + (IData)(vlSelf->tb_cpu__DOT__mem_wb_forward_a_event)) 
             + (IData)(vlSelf->tb_cpu__DOT__mem_wb_forward_b_event));
        if (VL_UNLIKELY((0U != vlSelf->tb_cpu__DOT__uut__DOT__rf__DOT__regs
                         [0U]))) {
            VL_WRITEF("[%0t] %%Fatal: tb_counter_update.svh:96: Assertion failed in %Ntb_cpu.update_counters: ERROR: x0 changed! Expected x0=0, got %0#\n",
                      64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                      32,vlSelf->tb_cpu__DOT__uut__DOT__rf__DOT__regs
                      [0U]);
            VL_STOP_MT("../tb/tb_counter_update.svh", 96, "");
        }
    }
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_branch 
        = ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__reset))) 
           && ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__control_taken))) 
               && ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__stall))) 
                   && (0x63U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)))));
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_load = 
        ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__reset))) 
         && ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__control_taken))) 
             && ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__stall))) 
                 && (3U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)))));
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_store = 
        ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__reset))) 
         && ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__control_taken))) 
             && ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__stall))) 
                 && (0x23U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)))));
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_itype = 
        ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__reset))) 
         && ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__control_taken))) 
             && ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__stall))) 
                 && (0x13U == (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)))));
    vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_is_jal = 
        ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__reset))) 
         && (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_is_jal));
    if (__Vdlyvset__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0) {
        vlSelf->tb_cpu__DOT__uut__DOT__dmem__DOT__mem[__Vdlyvdim0__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0] 
            = __Vdlyvval__tb_cpu__DOT__uut__DOT__dmem__DOT__mem__v0;
    }
    if (vlSelf->tb_cpu__DOT__reset) {
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_funct3 = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1 = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2 = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_pc_plus_4 = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1 = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2 = 0U;
    } else {
        if (vlSelf->tb_cpu__DOT__uut__DOT__control_taken) {
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_funct3 = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1 = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2 = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1 = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2 = 0U;
        } else if (vlSelf->tb_cpu__DOT__uut__DOT__stall) {
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_funct3 = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1 = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2 = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1 = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2 = 0U;
        } else {
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl 
                = vlSelf->tb_cpu__DOT__uut__DOT__alu_ctrl;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_funct3 
                = (7U & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                         >> 0xcU));
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm 
                = vlSelf->tb_cpu__DOT__uut__DOT__imm;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs1 
                = (0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                            >> 0xfU));
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rs2 
                = (0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                            >> 0x14U));
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1 
                = ((((IData)(vlSelf->tb_cpu__DOT__uut__DOT__wb_we) 
                     & (0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd))) 
                    & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd) 
                       == (0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                    >> 0xfU)))) ? vlSelf->tb_cpu__DOT__uut__DOT__wb_data
                    : vlSelf->tb_cpu__DOT__uut__DOT__rf__DOT__regs
                   [(0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                              >> 0xfU))]);
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2 
                = ((((IData)(vlSelf->tb_cpu__DOT__uut__DOT__wb_we) 
                     & (0U != (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd))) 
                    & ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd) 
                       == (0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                    >> 0x14U)))) ? vlSelf->tb_cpu__DOT__uut__DOT__wb_data
                    : vlSelf->tb_cpu__DOT__uut__DOT__rf__DOT__regs
                   [(0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                              >> 0x14U))]);
        }
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result 
            = ((3U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode))
                ? vlSelf->tb_cpu__DOT__uut__DOT__mem_read_data
                : vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result);
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_pc_plus_4 
            = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_pc_plus_4;
    }
    if (__Vdlyvset__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0) {
        vlSelf->tb_cpu__DOT__uut__DOT__rf__DOT__regs[__Vdlyvdim0__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0] 
            = __Vdlyvval__tb_cpu__DOT__uut__DOT__rf__DOT__regs__v0;
    }
    vlSelf->tb_cpu__DOT__uut__DOT__ex_use_imm = ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_itype) 
                                                 | ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_load) 
                                                    | (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_store)));
    vlSelf->tb_cpu__DOT__uut__DOT__wb_data = ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_is_jal)
                                               ? vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_pc_plus_4
                                               : vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_result);
    vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_is_jal = 
        ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__reset))) 
         && (IData)(vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_jal));
    if (vlSelf->tb_cpu__DOT__reset) {
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_store_data = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode = 0U;
    } else {
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_store_data 
            = vlSelf->tb_cpu__DOT__uut__DOT__forward_b;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_instr 
            = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_instr;
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode 
            = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode;
    }
    vlSelf->tb_cpu__DOT__uut__DOT__wb_we = ((0x33U 
                                             == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)) 
                                            | ((0x13U 
                                                == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)) 
                                               | ((3U 
                                                   == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)) 
                                                  | (0x6fU 
                                                     == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_opcode)))));
    if (vlSelf->tb_cpu__DOT__reset) {
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_pc_plus_4 = 0U;
    } else {
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result 
            = vlSelf->tb_cpu__DOT__uut__DOT__alu_result;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_pc_plus_4 
            = ((IData)(4U) + vlSelf->tb_cpu__DOT__uut__DOT__id_ex_pc);
    }
    tb_cpu__DOT__uut__DOT__ex_mem_forward_data = ((IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_is_jal)
                                                   ? vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_pc_plus_4
                                                   : vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result);
    vlSelf->tb_cpu__DOT__uut__DOT__id_ex_is_jal = (
                                                   (1U 
                                                    & (~ (IData)(vlSelf->tb_cpu__DOT__reset))) 
                                                   && ((1U 
                                                        & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__control_taken))) 
                                                       && ((1U 
                                                            & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__stall))) 
                                                           && (0x6fU 
                                                               == 
                                                               (0x7fU 
                                                                & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr)))));
    if (vlSelf->tb_cpu__DOT__reset) {
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_instr = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_pc = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__if_id_pc = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd = 0U;
        vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr = 0U;
    } else {
        vlSelf->tb_cpu__DOT__uut__DOT__mem_wb_rd = vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_instr 
            = vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode 
            = vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode;
        vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_rd = vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd;
        if (vlSelf->tb_cpu__DOT__uut__DOT__control_taken) {
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_pc = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__if_id_pc = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd = 0U;
            vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr = 0U;
        } else {
            if (vlSelf->tb_cpu__DOT__uut__DOT__stall) {
                vlSelf->tb_cpu__DOT__uut__DOT__id_ex_pc = 0U;
                vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr = 0U;
                vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode = 0U;
                vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd = 0U;
            } else {
                vlSelf->tb_cpu__DOT__uut__DOT__id_ex_pc 
                    = vlSelf->tb_cpu__DOT__uut__DOT__if_id_pc;
                vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr 
                    = vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr;
                vlSelf->tb_cpu__DOT__uut__DOT__id_ex_opcode 
                    = (0x7fU & vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr);
                vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd 
                    = (0x1fU & (vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                                >> 7U));
            }
            if ((1U & (~ (IData)(vlSelf->tb_cpu__DOT__uut__DOT__stall)))) {
                vlSelf->tb_cpu__DOT__uut__DOT__if_id_pc 
                    = vlSelf->tb_cpu__DOT__uut__DOT__pc;
                vlSelf->tb_cpu__DOT__uut__DOT__if_id_instr 
                    = vlSelf->tb_cpu__DOT__uut__DOT__instr;
            }
        }
    }
    vlSelf->tb_cpu__DOT__uut__DOT__mem_read_data = 
        ((3U == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode))
          ? vlSelf->tb_cpu__DOT__uut__DOT__dmem__DOT__mem
         [(0xffU & (vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_result 
                    >> 2U))] : 0U);
    tb_cpu__DOT__uut__DOT__ex_mem_regwrite = ((0x33U 
                                               == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)) 
                                              | ((0x13U 
                                                  == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode)) 
                                                 | (0x6fU 
                                                    == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__ex_mem_opcode))));
    vlSelf->tb_cpu__DOT__uut__DOT__jal_target = (vlSelf->tb_cpu__DOT__uut__DOT__id_ex_imm 
                                                 + vlSelf->tb_cpu__DOT__uut__DOT__id_ex_pc);
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
    vlSelf->tb_cpu__DOT__uut__DOT__pc = __Vdly__tb_cpu__DOT__uut__DOT__pc;
    tb_cpu__DOT__id_ex_valid_for_forwarding = ((0U 
                                                != vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr) 
                                               & (0x500013U 
                                                  != vlSelf->tb_cpu__DOT__uut__DOT__id_ex_instr));
    vlSelf->tb_cpu__DOT__uut__DOT__forward_a = ((2U 
                                                 == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel))
                                                 ? tb_cpu__DOT__uut__DOT__ex_mem_forward_data
                                                 : 
                                                ((1U 
                                                  == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel))
                                                  ? vlSelf->tb_cpu__DOT__uut__DOT__wb_data
                                                  : vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd1));
    vlSelf->tb_cpu__DOT__uut__DOT__forward_b = ((2U 
                                                 == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel))
                                                 ? tb_cpu__DOT__uut__DOT__ex_mem_forward_data
                                                 : 
                                                ((1U 
                                                  == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel))
                                                  ? vlSelf->tb_cpu__DOT__uut__DOT__wb_data
                                                  : vlSelf->tb_cpu__DOT__uut__DOT__id_ex_rd2));
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
    vlSelf->tb_cpu__DOT__uut__DOT__instr = vlSelf->tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem
        [(0xffU & (vlSelf->tb_cpu__DOT__uut__DOT__pc 
                   >> 2U))];
    vlSelf->tb_cpu__DOT__ex_mem_forward_a_event = ((IData)(tb_cpu__DOT__id_ex_uses_rs1) 
                                                   & (2U 
                                                      == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel)));
    vlSelf->tb_cpu__DOT__mem_wb_forward_a_event = ((IData)(tb_cpu__DOT__id_ex_uses_rs1) 
                                                   & (1U 
                                                      == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_a_sel)));
    vlSelf->tb_cpu__DOT__ex_mem_forward_b_event = ((IData)(tb_cpu__DOT__id_ex_uses_rs2) 
                                                   & (2U 
                                                      == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel)));
    vlSelf->tb_cpu__DOT__mem_wb_forward_b_event = ((IData)(tb_cpu__DOT__id_ex_uses_rs2) 
                                                   & (1U 
                                                      == (IData)(vlSelf->tb_cpu__DOT__uut__DOT__forward_b_sel)));
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
}
