// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_cpu__pch.h"
#include "Vtb_cpu.h"
#include "Vtb_cpu___024root.h"
#include "Vtb_cpu___024unit.h"

// FUNCTIONS
Vtb_cpu__Syms::~Vtb_cpu__Syms()
{
}

Vtb_cpu__Syms::Vtb_cpu__Syms(VerilatedContext* contextp, const char* namep, Vtb_cpu* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_cpu.configure(this, name(), "tb_cpu", "tb_cpu", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_cpu__open_output_files.configure(this, name(), "tb_cpu.open_output_files", "open_output_files", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_cpu__update_counters.configure(this, name(), "tb_cpu.update_counters", "update_counters", -12, VerilatedScope::SCOPE_OTHER);
}
