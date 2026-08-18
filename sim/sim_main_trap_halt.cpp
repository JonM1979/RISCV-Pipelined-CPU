#include "Vtb_trap_halt.h"
#include "verilated.h"
 
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vtb_trap_halt* top = new Vtb_trap_halt;
    while (!Verilated::gotFinish()) {
        top->eval();
        Verilated::timeInc(1);
    }
    delete top;
    return 0;
}
