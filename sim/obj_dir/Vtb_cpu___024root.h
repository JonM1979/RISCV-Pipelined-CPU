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
    CData/*0:0*/ __Vdlyvval__tb_cpu__DOT__clk__v0;
    CData/*0:0*/ __Vdlyvset__tb_cpu__DOT__clk__v0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_cpu__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_cpu__DOT__cycle;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__a;
    IData/*31:0*/ tb_cpu__DOT__uut__DOT__b;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
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
