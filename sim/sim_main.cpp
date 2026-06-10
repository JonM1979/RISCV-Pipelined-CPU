#include "Vtb_cpu.h"
#include "verilated.h"

int main() {
    Vtb_cpu top;

    while (!Verilated::gotFinish()) {
        top.clk = 0;
        top.eval();

        top.clk = 1;
        top.eval();
    }

    return 0;
}