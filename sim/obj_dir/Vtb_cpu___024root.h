// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_cpu.h for the primary calling header

#ifndef VERILATED_VTB_CPU___024ROOT_H_
#define VERILATED_VTB_CPU___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_cpu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_cpu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_cpu__DOT__clk;
    CData/*0:0*/ tb_cpu__DOT__reset;
    CData/*0:0*/ tb_cpu__DOT__uut__DOT__stall;
    CData/*4:0*/ tb_cpu__DOT__uut__DOT__id_ex_rd;
    CData/*6:0*/ tb_cpu__DOT__uut__DOT__id_ex_opcode;
    CData/*4:0*/ tb_cpu__DOT__uut__DOT__id_ex_rs1;
    CData/*4:0*/ tb_cpu__DOT__uut__DOT__id_ex_rs2;
    CData/*1:0*/ tb_cpu__DOT__uut__DOT__forward_a_sel;
    CData/*1:0*/ tb_cpu__DOT__uut__DOT__forward_b_sel;
    CData/*4:0*/ tb_cpu__DOT__uut__DOT__ex_mem_rd;
    CData/*6:0*/ tb_cpu__DOT__uut__DOT__ex_mem_opcode;
    CData/*4:0*/ tb_cpu__DOT__uut__DOT__mem_wb_rd;
    CData/*6:0*/ tb_cpu__DOT__uut__DOT__mem_wb_opcode;
    CData/*0:0*/ __Vdlyvval__tb_cpu__DOT__clk__v0;
    CData/*0:0*/ __Vdlyvset__tb_cpu__DOT__clk__v0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_cpu__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_cpu__DOT__cycle;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__pc;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__instr;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__if_id_instr;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__id_ex_rd1;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__id_ex_rd2;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__id_ex_imm;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__forward_a;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__forward_b;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__alu_result;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__ex_mem_result;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__ex_mem_store_data;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__mem_wb_result;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 256> tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem;
    VlUnpacked<IData/*31:0*/, 32> tb_cpu__DOT__uut__DOT__rf__DOT__regs;
    VlUnpacked<IData/*31:0*/, 256> tb_cpu__DOT__uut__DOT__dmem__DOT__mem;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_cpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_cpu___024root(Vtb_cpu__Syms* symsp, const char* v__name);
    ~Vtb_cpu___024root();
    VL_UNCOPYABLE(Vtb_cpu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
