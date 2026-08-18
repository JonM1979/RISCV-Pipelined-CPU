#!/usr/bin/env bash
# run_trap_halt.sh
#
# Builds and runs the dedicated sticky-trap-halt regression test
# (tb/tb_trap_halt.sv). This test exists because the main testbench finishes
# the instant a trap is raised and so cannot observe the multi-cycle halt
# behaviour; see the header of tb/tb_trap_halt.sv for the full rationale.
#
# Assertions are enabled (--assert), so the two halt-liveness properties in
# cpu_assertions.sv (a_trapped_blocks_all_writes, a_trapped_freezes_pc) are
# checked on every cycle of the run as well.
set -euo pipefail
 
OBJ=obj_dir_trap_halt
 
# Program: addi x1,x0,5 / ECALL / four younger addis / halt.
# The four younger addis must never commit once the ECALL traps.
cat > program.hex << 'EOF'
00500093
00000073
06f00513
0de00593
14d00613
1bc00693
00500013
EOF
printf "00000000\n" > data.hex
 
echo "Building trap-halt test (Verilator, assertions enabled)..."
rm -rf "$OBJ"
verilator -Wall --assert --I../rtl --I../tb --timing -Wno-fatal --cc \
    ../rtl/*.sv ../tb/tb_trap_halt.sv \
    --top-module tb_trap_halt --Mdir "$OBJ" --exe --build --main \
    > /dev/null 2>&1 || {
        echo "Build failed; re-running verbosely:" >&2
        verilator -Wall --assert --I../rtl --I../tb --timing -Wno-fatal --cc \
            ../rtl/*.sv ../tb/tb_trap_halt.sv \
            --top-module tb_trap_halt --Mdir "$OBJ" --exe --build --main
        exit 1
    }
 
echo "Running trap-halt test..."
./"$OBJ"/Vtb_trap_halt
 