// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_cpu.h for the primary calling header

#ifndef VERILATED_VTB_CPU___024UNIT_H_
#define VERILATED_VTB_CPU___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_cpu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_cpu___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtb_cpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_cpu___024unit(Vtb_cpu__Syms* symsp, const char* v__name);
    ~Vtb_cpu___024unit();
    VL_UNCOPYABLE(Vtb_cpu___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
