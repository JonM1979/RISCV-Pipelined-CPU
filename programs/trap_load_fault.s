# An address beyond the data memory window must fault rather than alias.
li x1, 0x40000      # far past the 1024-word window
lw x2, 0(x1)        # traps (cause 5)
halt
