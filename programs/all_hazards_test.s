# ============================================================
# hazard_all_test.s
#
# Directed hazard verification program.
#
# This program verifies hazards by checking final architectural
# state at the end of simulation.
#
# Tests:
# - EX/MEM forwarding to rs1
# - EX/MEM forwarding to rs2
# - MEM/WB forwarding to rs1
# - MEM/WB forwarding to rs2
# - Load-use stall on rs1
# - Load-use stall on rs2
# - Store-data forwarding
# - Branch operand forwarding
# - Branch flush
# - JAL flush
# - JALR flush
# - JALR target forwarding
# - x0 protection
# ============================================================

# ------------------------------------------------------------
# Base values
# ------------------------------------------------------------
addi x1, x0, 5          # x1 = 5
addi x2, x0, 10         # x2 = 10

# ------------------------------------------------------------
# EX/MEM forwarding to rs1
# x3 is produced immediately before x4 consumes it as rs1.
# If EX/MEM forwarding A fails, x4 will be wrong.
# ------------------------------------------------------------
add  x3, x1, x2         # x3 = 15
add  x4, x3, x2         # x4 = 25

# ------------------------------------------------------------
# EX/MEM forwarding to rs2
# x5 is produced immediately before x6 consumes it as rs2.
# If EX/MEM forwarding B fails, x6 will be wrong.
# ------------------------------------------------------------
add  x5, x1, x2         # x5 = 15
add  x6, x2, x5         # x6 = 25

# ------------------------------------------------------------
# MEM/WB forwarding to rs1
# One NOP gap puts producer in MEM/WB when consumer reaches EX.
# ------------------------------------------------------------
add  x7, x1, x2         # x7 = 15
nop
add  x8, x7, x2         # x8 = 25

# ------------------------------------------------------------
# MEM/WB forwarding to rs2
# ------------------------------------------------------------
add  x9, x1, x2         # x9 = 15
nop
add  x10, x2, x9        # x10 = 25

# ------------------------------------------------------------
# Load-use hazard on rs1
# This should force one stall.
# If stall/forwarding fails, x12 will be wrong.
# ------------------------------------------------------------
sw   x2, 0(x0)          # mem[0] = 10
lw   x11, 0(x0)         # x11 = 10
add  x12, x11, x1       # x12 = 15

# ------------------------------------------------------------
# Load-use hazard on rs2
# This should force one stall.
# If stall/forwarding fails, x14 will be wrong.
# ------------------------------------------------------------
lw   x13, 0(x0)         # x13 = 10
add  x14, x1, x13       # x14 = 15

# ------------------------------------------------------------
# Store-data forwarding, immediate producer
# If store-data forwarding fails, mem[1] will be wrong.
# ------------------------------------------------------------
addi x15, x0, 33        # x15 = 33
sw   x15, 4(x0)         # mem[1] = 33

# ------------------------------------------------------------
# Store-data forwarding, one-cycle gap
# If forwarding/bypass fails, mem[2] may be wrong.
# ------------------------------------------------------------
addi x16, x0, 44        # x16 = 44
nop
sw   x16, 8(x0)         # mem[2] = 44

# ------------------------------------------------------------
# Branch operand forwarding and branch flush
# x17 is produced immediately before BEQ uses it.
# The branch must be taken, and the fail-path instruction flushed.
# ------------------------------------------------------------
addi x17, x0, 1
beq  x17, x17, branch_exmem_pass
addi x18, x0, 111       # FAIL path, should be flushed

branch_exmem_pass:
addi x18, x0, 18        # x18 = 18

# ------------------------------------------------------------
# Branch operand forwarding with one-cycle gap
# The BNE should be taken, and the fail-path instruction flushed.
# ------------------------------------------------------------
addi x19, x0, 2
nop
bne  x19, x1, branch_memwb_pass
addi x20, x0, 111       # FAIL path, should be flushed

branch_memwb_pass:
addi x20, x0, 20        # x20 = 20

# ------------------------------------------------------------
# JAL control hazard
# Wrong-path instruction should be flushed.
# JAL is at PC 0x7c, so x21 should receive 0x80 = 128.
# ------------------------------------------------------------
jal  x21, jal_pass
addi x22, x0, 111       # FAIL path, should be flushed

jal_pass:
addi x22, x0, 22        # x22 = 22

# ------------------------------------------------------------
# JALR target forwarding and control hazard
# x23 is produced immediately before JALR uses it.
# If JALR target forwarding fails, jump target will be wrong.
#
# jalr_pass is at PC 0x94 = 148.
# JALR is at PC 0x8c, so x24 should receive 0x90 = 144.
# ------------------------------------------------------------
addi x23, x0, jalr_pass # x23 = 148
jalr x24, 0(x23)        # x24 = 144
addi x25, x0, 111       # FAIL path, should be flushed

jalr_pass:
addi x25, x0, 25        # x25 = 25

# ------------------------------------------------------------
# x0 protection
# ------------------------------------------------------------
addi x0, x0, 123        # x0 should remain 0
addi x26, x0, 26        # x26 = 26

halt