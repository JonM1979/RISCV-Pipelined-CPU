# Byte and halfword load/store, including sign vs zero extension
# and verification that stores only touch their own lanes.

li x1, 0x100                # base address

# ---- SW then per-byte LB / LBU ----
li x2, 0x8090A0B0
sw x2, 0(x1)

lbu x3, 0(x1)               # 0xB0 zero-extended
li  x20, 0xB0
bne x3, x20, fail

lb  x4, 0(x1)               # 0xB0 sign-extended -> 0xFFFFFFB0
li  x21, -80                # 0xFFFFFFB0
bne x4, x21, fail

lbu x5, 3(x1)               # top byte 0x80
li  x22, 0x80
bne x5, x22, fail

lb  x6, 3(x1)               # 0x80 sign-extended -> 0xFFFFFF80
li  x23, -128
bne x6, x23, fail

# ---- halfword loads ----
lhu x7, 0(x1)               # 0xA0B0
li  x24, 0xA0B0
bne x7, x24, fail

lh  x8, 0(x1)               # 0xA0B0 sign-extended
li  x25, 0xFFFFA0B0
bne x8, x25, fail

lhu x9, 2(x1)               # 0x8090
li  x26, 0x8090
bne x9, x26, fail

# ---- SB must modify only one lane ----
li x10, 0x11223344
sw x10, 16(x1)
li x11, 0xEE
sb x11, 16(x1)              # replace only the low byte
lw x12, 16(x1)
li x27, 0x112233EE
bne x12, x27, fail

sb x11, 18(x1)              # replace byte 2
lw x12, 16(x1)
li x27, 0x11EE33EE
bne x12, x27, fail

# ---- SH must modify only two lanes ----
li x13, 0x55667788
sw x13, 32(x1)
li x14, 0xABCD
sh x14, 32(x1)
lw x15, 32(x1)
li x28, 0x5566ABCD
bne x15, x28, fail

sh x14, 34(x1)
lw x15, 32(x1)
li x28, 0xABCDABCD
bne x15, x28, fail

addi x31, x0, 1
halt

fail:
addi x31, x0, 0
halt
