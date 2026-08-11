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
addi x31, x0, 1

// in the terminal, the assembler will say what rules it is 
// using, for example, this test will use the generic rule, 
// that x31 must equal 1. If not then the program failed 
// and it will halt. If you see a "PASS: self-checking test succeeded"
// then the program completed successfully and the assembler is working correctly.
fail:
halt
