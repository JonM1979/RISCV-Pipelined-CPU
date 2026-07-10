#include "Vtb_cpu.h"
#include "verilated.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vtb_cpu* top = new Vtb_cpu;

    vluint64_t sim_time = 0;

    while (!Verilated::gotFinish()) {
        top->eval();
        Verilated::timeInc(1); // Increment simulation time by 1 unit
        sim_time++;

    }

    delete top;
    return 0;
}