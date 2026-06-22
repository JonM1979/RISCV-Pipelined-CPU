// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_CPU__SYMS_H_
#define VERILATED_VTB_CPU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_cpu.h"

// INCLUDE MODULE CLASSES
#include "Vtb_cpu___024root.h"
#include "Vtb_cpu___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_cpu__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_cpu* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_cpu___024root              TOP;

    // CONSTRUCTORS
    Vtb_cpu__Syms(VerilatedContext* contextp, const char* namep, Vtb_cpu* modelp);
    ~Vtb_cpu__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
