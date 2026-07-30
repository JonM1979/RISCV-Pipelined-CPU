# Directed test for instructions added in the RV32I expansion.
# x31 = 1 only if every check passes.

# ---- SLTU / SLTIU (unsigned compare) ----
li   x1, -1                 # 0xFFFFFFFF, largest unsigned
li   x2, 1
sltu x3, x2, x1             # 1 <u 0xFFFFFFFF -> 1
li   x20, 1
bne  x3, x20, fail

sltu x3, x1, x2             # 0xFFFFFFFF <u 1 -> 0
bnez x3, fail

slt  x3, x1, x2             # -1 <s 1 -> 1  (signed differs from unsigned)
bne  x3, x20, fail

sltiu x3, x2, 1             # 1 <u 1 -> 0
bnez x3, fail

# ---- SRA / SRAI (arithmetic shift sign-extends) ----
li   x4, -16                # 0xFFFFFFF0
li   x5, 2
sra  x6, x4, x5             # -16 >> 2 = -4
li   x21, -4
bne  x6, x21, fail

srai x6, x4, 2
bne  x6, x21, fail

srl  x7, x4, x5             # logical: 0xFFFFFFF0 >> 2 = 0x3FFFFFFC
li   x22, 0x3FFFFFFC
bne  x7, x22, fail

# ---- BLTU / BGEU (unsigned branches) ----
bltu x1, x2, fail           # 0xFFFFFFFF <u 1 is false
bgeu x1, x2, bgeu_ok        # 0xFFFFFFFF >=u 1 is true
j    fail
bgeu_ok:

blt  x1, x2, blt_ok         # -1 <s 1 is true
j    fail
blt_ok:

# ---- AUIPC ----
auipc x8, 0                 # x8 = address of this instruction
jal   x9, capture           # x9 = PC+4 of the jal
capture:
# x9 points at 'capture'; the auipc is 4 bytes before the jal,
# so x8 + 8 == x9
addi  x10, x8, 8
bne   x10, x9, fail

addi x31, x0, 1
halt

fail:
addi x31, x0, 0
halt
