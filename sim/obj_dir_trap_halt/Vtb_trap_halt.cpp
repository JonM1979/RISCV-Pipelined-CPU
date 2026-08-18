// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_trap_halt__pch.h"

//============================================================
// Constructors

Vtb_trap_halt::Vtb_trap_halt(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_trap_halt__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_trap_halt::Vtb_trap_halt(const char* _vcname__)
    : Vtb_trap_halt(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_trap_halt::~Vtb_trap_halt() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_trap_halt___024root___eval_debug_assertions(Vtb_trap_halt___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_trap_halt___024root___eval_static(Vtb_trap_halt___024root* vlSelf);
void Vtb_trap_halt___024root___eval_initial(Vtb_trap_halt___024root* vlSelf);
void Vtb_trap_halt___024root___eval_settle(Vtb_trap_halt___024root* vlSelf);
void Vtb_trap_halt___024root___eval(Vtb_trap_halt___024root* vlSelf);

void Vtb_trap_halt::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_trap_halt::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_trap_halt___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_trap_halt___024root___eval_static(&(vlSymsp->TOP));
        Vtb_trap_halt___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_trap_halt___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_trap_halt___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_trap_halt::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_trap_halt::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_trap_halt::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_trap_halt___024root___eval_final(Vtb_trap_halt___024root* vlSelf);

VL_ATTR_COLD void Vtb_trap_halt::final() {
    Vtb_trap_halt___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_trap_halt::hierName() const { return vlSymsp->name(); }
const char* Vtb_trap_halt::modelName() const { return "Vtb_trap_halt"; }
unsigned Vtb_trap_halt::threads() const { return 1; }
void Vtb_trap_halt::prepareClone() const { contextp()->prepareClone(); }
void Vtb_trap_halt::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_trap_halt::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_trap_halt::trace()' called on model that was Verilated without --trace option");
}
