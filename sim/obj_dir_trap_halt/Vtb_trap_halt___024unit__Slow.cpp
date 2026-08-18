// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_trap_halt.h for the primary calling header

#include "Vtb_trap_halt__pch.h"
#include "Vtb_trap_halt__Syms.h"
#include "Vtb_trap_halt___024unit.h"

void Vtb_trap_halt___024unit___ctor_var_reset(Vtb_trap_halt___024unit* vlSelf);

Vtb_trap_halt___024unit::Vtb_trap_halt___024unit(Vtb_trap_halt__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_trap_halt___024unit___ctor_var_reset(this);
}

void Vtb_trap_halt___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_trap_halt___024unit::~Vtb_trap_halt___024unit() {
}
