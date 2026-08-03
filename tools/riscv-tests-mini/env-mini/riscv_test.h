// Minimal bare-metal test harness for a CPU with no CSR/privileged support.
//
// The official env/p/riscv_test.h drives pass/fail through a trap handler
// that reads mcause and writes to a memory-mapped tohost location -- both of
// which require CSRs this core does not implement. The test BODIES (the
// actual instruction sequences and expected values in isa/rv32ui/*.S) need
// no privileged state at all; only this environment header does. This file
// replaces just the environment, targeting this core's actual capability:
// a precise, hardware-native ECALL trap.
//
// Convention: RVTEST_PASS executes `ecall` with a0=0. RVTEST_FAIL executes
// `ecall` with a0 = (failing testnum << 1) | 1. The testbench inspects a0 at
// the moment of the trap to determine the result -- no trap_vector required.

#ifndef _ENV_MINI_H
#define _ENV_MINI_H

#define RVTEST_RV32U \
  .macro init;        \
  .endm

#define RVTEST_CODE_BEGIN \
  .section .text;         \
  .globl _start;          \
_start:                   \
  .align 2;

#define RVTEST_CODE_END \
  unimp

#define TESTNUM gp

#define RVTEST_PASS \
  li a7, 93;        \
  li a0, 0;         \
  ecall

#define RVTEST_FAIL             \
1:  beqz TESTNUM, 1b;           \
    sll  TESTNUM, TESTNUM, 1;   \
    or   TESTNUM, TESTNUM, 1;   \
    li   a7, 93;                \
    addi a0, TESTNUM, 0;        \
    ecall

#define RVTEST_DATA_BEGIN \
  .data;                  \
  .align 4;

#define RVTEST_DATA_END

#endif
