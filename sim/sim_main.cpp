#include "Vtb_cpu.h"
#include "verilated.h"

int main() {
    Vtb_cpu top;

    vluint64_t sim_time = 0;

    while (!Verilated::gotFinish()) {
        top.eval();
        Verilated::timeInc(1); // Increment simulation time by 1 unit
        sim_time++;

    }

    return 0;
}