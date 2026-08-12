// a simple program to showcase a few instructions 
// and to test the assembler

// simple addi instructions
addi x1, x0, 8
addi x2, x0, 12

// store the value in x1 to the address in x2
sw x1, 0(x2)

// this instruction order will create a load-use hazard, 
// making the processor stall for one cycle
lw x4, 0(x2)
lw x5, 4(x4)

// this is to check that x4 is indeed 8, and if it is not,
// then the program will halt with an error code of 0
addi x6, x0, 8
bne x4, x6, fail

// this instruction order tests the WB-to-ID same-cycle bypass:
// x7's writeback and x9's register read land on the same clock
// edge, since exactly two instructions separate the producer from
// the consumer. without the bypass, x9 would read the stale
// (pre-write) value of x7 straight out of the register file
addi x7, x0, 21
nop
nop
addi x9, x7, 0

// check that x9 is indeed 21, and if it is not,
// then the program will halt with an error code of 0
addi x10, x0, 21
bne x9, x10, fail
addi x31, x0, 1

// in the terminal, the assembler will say what rules it is 
// using, for example, this test will use the generic rule, 
// that x31 must equal 1. If not then the program failed 
// and it will halt. If you see a "PASS: self-checking test succeeded"
// then the program completed successfully and the assembler is working correctly.
fail:
halt
