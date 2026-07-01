#!/bin/bash

echo "Cleaning old build.."
rm -rf obj_dir

echo "Compiling..."

verilator -Wall --I../rtl --I../tb --timing -Wno-fatal --cc ../rtl/*.sv ../tb/tb_cpu.sv --top-module tb_cpu --exe sim_main.cpp

make -C obj_dir -f Vtb_cpu.mk Vtb_cpu

echo "Running simulation..."

./obj_dir/Vtb_cpu