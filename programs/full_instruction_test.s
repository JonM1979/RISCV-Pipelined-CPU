# Full instruction test program

lui  x1, 0x1
addi x2, x0, 3
add  x3, x1, x2
sub  x4, x3, x2

addi x5, x0, 5
addi x6, x0, 10

or   x7, x5, x6
and  x8, x5, x6
xor  x9, x7, x6
slt  x10, x5, x6

sll  x11, x5, x10
srl  x12, x11, x10

addi x13, x5, 2
andi x14, x7, 7
ori  x15, x14, 8
xori x16, x15, 3
slti x17, x5, 6

slli x18, x5, 2
srli x19, x18, 2


sw   x16, 0(x0)
lw   x20, 0(x0)

beq  x5, x5, beq_pass
addi x21, x0, 111

beq_pass:
addi x21, x0, 1

bne  x5, x6, bne_pass
addi x22, x0, 111

bne_pass:
addi x22, x0, 2

blt  x5, x6, blt_pass
addi x23, x0, 111

blt_pass:
addi x23, x0, 3

bge  x6, x5, bge_pass
addi x24, x0, 111

bge_pass:
addi x24, x0, 4


jal  x25, jal_pass
addi x26, x0, 111

jal_pass:
addi x26, x0, 26

# For this program, jalr_pass is at byte address 156.
# The assembler below also supports labels as ADDI immediates.
addi x28, x0, jalr_pass
jalr x29, 0(x28)
addi x30, x0, 111

jalr_pass:
addi x30, x0, 30

halt
