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
echo "Cleaning old build/output files.."
rm -rf obj_dir
rm -f "$HEX_FILE"
rm -f trace.log instruction_trace.log summary.log

echo ""
# A .hex input is used directly; anything else is assembled first.
case "$PROGRAM" in
    *.hex)
        echo "Using pre-assembled hex image..."
        cp "$PROGRAM" "$HEX_FILE"
        ;;
    *.S)
        # Official riscv-tests sources (uppercase .S, matching upstream's own
        # convention) use C-preprocessor #include and GNU assembler macros
        # that tools/asm_to_hex.py cannot parse. These are compiled by the
        # real RISC-V GNU toolchain instead -- see
        # tools/riscv-tests-mini/build_and_convert.sh.
        echo "Compiling official riscv-tests source via GNU toolchain..."
        ../tools/riscv-tests-mini/build_and_convert.sh "$PROGRAM" "$HEX_FILE"
        ;;
    *)
        echo "Assembling program..."
        python3 ../tools/asm_to_hex.py "$PROGRAM" "$HEX_FILE"
        ;;
esac

echo ""
echo "Compiling with Verilator..."
verilator -Wall --assert --I../rtl --I../tb --timing -Wno-fatal --cc ../rtl/*.sv ../tb/tb_cpu.sv --top-module tb_cpu --exe sim_main.cpp

echo ""
echo "Building..."
make -C obj_dir -f Vtb_cpu.mk Vtb_cpu

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