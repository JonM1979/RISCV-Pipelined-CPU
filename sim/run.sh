#!/bin/bash
set -e

# ================================================
# run.sh
#
#
# Usage:
#   allows for run.sh to accept a program 
#   argument instead of program being 
#   hardcoded
#
#   If no program is provided, the default file is:
#   full_instruction_test.s
#
# ================================================

# Usage: ./run.sh <program.s|program.hex> [expected_trap_cause]
PROGRAM=${1:-../programs/full_instruction_test.s}
EXPECT_CAUSE=${2:-}
HEX_FILE=program.hex


echo "============================================================"
echo "RISC-V CPU Simulation"
echo "============================================================"
echo "Assembly program : $PROGRAM"
echo "Output hex file  : $HEX_FILE"
echo "============================================================"

# Check that the assembly program exists
if [ ! -f "$PROGRAM" ]; then
    echo "ERROR: Assembly program not found: $PROGRAM"
    exit 1
fi

echo ""
echo "Cleaning old output files.."
rm -f "$HEX_FILE"
rm -f data.hex
rm -f trace.log instruction_trace.log summary.log

DATA_FILE=data.hex

echo ""
# A .hex input is used directly; anything else is assembled first.
# data_memory.sv unconditionally loads data.hex at reset (mirroring how
# instruction_memory.sv loads program.hex), so every path below must leave a
# valid data.hex in place -- a real data image for the riscv-tests sources
# that have one, or a single zero word otherwise.
case "$PROGRAM" in
    *.hex)
        echo "Using pre-assembled hex image..."
        cp "$PROGRAM" "$HEX_FILE"
        printf '00000000\n' > "$DATA_FILE"
        ;;
    *.S)
        # Official riscv-tests sources (uppercase .S, matching upstream's own
        # convention) use C-preprocessor #include and GNU assembler macros
        # that tools/asm_to_hex.py cannot parse. These are compiled by the
        # real RISC-V GNU toolchain instead -- see
        # tools/riscv-tests-mini/build_and_convert.sh. This path also extracts
        # the .data section into data.hex for load/store tests.
        echo "Compiling official riscv-tests source via GNU toolchain..."
        ../tools/riscv-tests-mini/build_and_convert.sh "$PROGRAM" "$HEX_FILE" "$DATA_FILE"
        ;;
    *)
        echo "Assembling program..."
        python3 ../tools/asm_to_hex.py "$PROGRAM" "$HEX_FILE"
        printf '00000000\n' > "$DATA_FILE"
        ;;
esac

echo ""
# The compiled simulator does not have any test program "baked in" -- it
# reads program.hex/data.hex and its +TEST=/+EXPECT_CAUSE=/+MAX_CYCLES=
# plusargs at RUNTIME, via $readmemh and $value$plusargs inside the RTL and
# testbench. Only the RTL and testbench SOURCE determines what Verilator
# compiles. So as long as none of that source has changed since the last
# build, re-running a different test program never needs a rebuild -- only
# a different simulation of the same, already-correct hardware model.
#
# Rebuilding on every single test (as this script used to do unconditionally)
# is always correct, but wastes a full Verilator transpile + C++ compile on
# every test even when nothing changed -- the dominant cost in a large batch
# like `run_all.sh compliance`. The check below rebuilds only when actually
# necessary: the binary is missing, or a source file is newer than it.
#
# Set FORCE_REBUILD=1 to always rebuild regardless (e.g. after switching
# Verilator versions, or if you distrust the mtime check for any reason).
BIN=obj_dir/Vtb_cpu

rebuild_needed=0
if [ -n "${FORCE_REBUILD:-}" ]; then
    rebuild_needed=1
elif [ ! -f "$BIN" ]; then
    rebuild_needed=1
else
    # Any source newer than the existing binary means it's stale.
    stale=$(find ../rtl ../tb -type f \( -name '*.sv' -o -name '*.svh' \) -newer "$BIN" 2>/dev/null | head -1)
    stale_extra=$(find sim_main.cpp run.sh -type f -newer "$BIN" 2>/dev/null | head -1)
    if [ -n "$stale" ] || [ -n "$stale_extra" ]; then
        rebuild_needed=1
    fi
fi

if [ "$rebuild_needed" -eq 1 ]; then
    echo "RTL/testbench changed (or no prior build) -- rebuilding..."
    rm -rf obj_dir

    echo ""
    echo "Compiling with Verilator..."
    verilator -Wall --assert --I../rtl --I../tb --timing -Wno-fatal --cc ../rtl/*.sv ../tb/tb_cpu.sv --top-module tb_cpu --exe sim_main.cpp

    echo ""
    echo "Building..."
    make -C obj_dir -f Vtb_cpu.mk Vtb_cpu
else
    echo "RTL/testbench unchanged -- reusing existing build ($BIN)"
fi

echo ""
echo "Running simulation..."
TEST_NAME=$(basename "$PROGRAM" | sed 's/\.[^.]*$//')

# The testbench's compliance checker (tb/riscv_compliance.svh) is selected by
# a "riscvtest_" name prefix. Apply it here based on the .S extension rather
# than renaming the vendored upstream files, so programs/riscv-tests/ stays
# byte-identical to the official riscv-tests repository.
case "$PROGRAM" in
    *.S) TEST_NAME="riscvtest_${TEST_NAME}" ;;
esac

PLUSARGS="+TEST=$TEST_NAME"
if [ -n "$EXPECT_CAUSE" ]; then
    PLUSARGS="$PLUSARGS +EXPECT_CAUSE=$EXPECT_CAUSE"
fi

# riscv-tests images are substantially longer than this project's own
# hand-written tests (hundreds of instructions vs. dozens), so they need a
# much larger safety-timeout budget.
case "$TEST_NAME" in
    riscvtest_*)
        PLUSARGS="$PLUSARGS +MAX_CYCLES=20000"
        ;;
esac

echo ""
echo "Running simulation: $TEST_NAME"
./obj_dir/Vtb_cpu $PLUSARGS