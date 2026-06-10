#!/bin/bash

echo "Compiling..."

verilator -Wall --cc ../rtl/*.sv ../tb/tb_cpu.sv --exe sim_main.cpp

make -C obj_dir -f Vtb_cpu.mk Vtb_cpu

echo "Running simulation..."

./obj_dir/Vtb_cpu