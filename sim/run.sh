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

PROGRAM=${1:-../programs/full_instruction_test.s}
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
echo "Assembling program..."
python3 ../tools/asm_to_hex.py "$PROGRAM" "$HEX_FILE"

echo ""
echo "Compiling with Verilator..."
verilator -Wall --I../rtl --I../tb --timing -Wno-fatal --cc ../rtl/*.sv ../tb/tb_cpu.sv --top-module tb_cpu --exe sim_main.cpp

echo ""
echo "Building..."
make -C obj_dir -f Vtb_cpu.mk Vtb_cpu

echo ""
echo "Running simulation..."
TEST_NAME=$(basename "$PROGRAM" .s)

echo ""
echo "Running simulation: $TEST_NAME"
./obj_dir/Vtb_cpu +TEST="$TEST_NAME"