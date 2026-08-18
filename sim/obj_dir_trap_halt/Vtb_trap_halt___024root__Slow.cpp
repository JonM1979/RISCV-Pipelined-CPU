// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_trap_halt.h for the primary calling header

#include "Vtb_trap_halt__pch.h"
#include "Vtb_trap_halt__Syms.h"
#include "Vtb_trap_halt___024root.h"

void Vtb_trap_halt___024root___ctor_var_reset(Vtb_trap_halt___024root* vlSelf);

Vtb_trap_halt___024root::Vtb_trap_halt___024root(Vtb_trap_halt__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_trap_halt___024root___ctor_var_reset(this);
}

void Vtb_trap_halt___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_trap_halt___024root::~Vtb_trap_halt___024root() {
}
