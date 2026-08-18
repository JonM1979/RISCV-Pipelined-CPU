// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_trap_halt.h for the primary calling header

#ifndef VERILATED_VTB_TRAP_HALT___024UNIT_H_
#define VERILATED_VTB_TRAP_HALT___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_trap_halt__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_trap_halt___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vtb_trap_halt__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_trap_halt___024unit(Vtb_trap_halt__Syms* symsp, const char* v__name);
    ~Vtb_trap_halt___024unit();
    VL_UNCOPYABLE(Vtb_trap_halt___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
