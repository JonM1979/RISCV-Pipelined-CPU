# RISCV-Pipelined-CPU

A 5-stage pipelined RISCV-style CPU written in SystemVerilog. The processor supports arithmetic, logic, memory, branch, jump, and upper-immediate instructions. Its architecture includes forwarding, load-use hazard detection, and branch/JAL/JALR flushing. It features a custom assembly-to-hex assembler, automated Verilator regression tests, cycle-by-cycle trace logs, and various performance statistics.

## Features

- 5-stage pipeline: IF, ID, EX, MEM, WB
- Forwarding unit for EX/MEM and MEM/WB hazards
- Load-use hazard detection and pipeline stall insertion
- Branch, JAL, and JALR control flushing
- Custom assembler for writing `.s` assembly programs
- Verilator simulation flow
- Automated regression testing using `run_all.sh`
- Cycle-by-cycle data and instruction traces
- Final performance summary with CPI, IPC, instruction mix, stalls, redirects, and forwarding activity 

## Supported Instructions

| Instruction Type | Instruction |
|------------------|-------------| 
| R-Type           | ADD, SUB, AND, OR, XOR, SLT, SLL, SRL |
| I-Type           | ADDI, ANDI, ORI, XORI, SLTI, SLLI, SRLI, LW, JALR |
| S-Type           | SW | 
| B-Type           | BEQ, BNE, BLT, BGE |
| J-Type           | JAL |
| U-Type           | LUI |

## How to Run 

Run a single program:

cd sim
./run.sh ../programs/full_instruction_test.s

Run all regression tests:
cd sim
./run_all.sh

## Verification

| Test Program | Purpose |
|--------------|---------|
| full_instruction_test.s | Verifies all supported instructions |
| all_hazards_test.s | Verifies forwarding, load-use stalls, store-data forwarding
branch flushed, JAL/JALR flushes, and x0 protection | 
