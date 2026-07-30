# A halfword store to an odd address must raise a misalignment trap.
li x1, 0x101
li x2, 5
sh x2, 0(x1)        # misaligned: traps (cause 6)
halt
