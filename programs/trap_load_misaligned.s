# A word load from a non-multiple-of-4 address must raise a misalignment trap.
li x1, 0x100
li x2, 123
sw x2, 0(x1)
lw x3, 1(x1)        # misaligned: traps (cause 4)
halt
