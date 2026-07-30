#!/usr/bin/env python3
"""
RV32I assembler producing flat hex for $readmemh.

Accepts standard RISC-V assembly syntax, so the same source assembles with
the GNU toolchain (riscv32-unknown-elf-as) without modification:

    jalr rd, rs1, imm       and      jalr rd, imm(rs1)
    lw   rd, imm(rs1)
    sw   rs2, imm(rs1)

Both numeric (x0-x31) and ABI (zero, ra, sp, a0, t0, s0 ...) register names
are accepted. Common pseudo-instructions are expanded.
"""

import sys
import re

# ---------------------------------------------------------------- encodings
OPCODES = {
    "R":       0b0110011,
    "I":       0b0010011,
    "LOAD":    0b0000011,
    "STORE":   0b0100011,
    "BRANCH":  0b1100011,
    "JALR":    0b1100111,
    "JAL":     0b1101111,
    "LUI":     0b0110111,
    "AUIPC":   0b0010111,
    "MISCMEM": 0b0001111,
    "SYSTEM":  0b1110011,
}

FUNCT3 = {
    "ADD": 0b000, "SUB": 0b000, "ADDI": 0b000,
    "SLL": 0b001, "SLLI": 0b001,
    "SLT": 0b010, "SLTI": 0b010,
    "SLTU": 0b011, "SLTIU": 0b011,
    "XOR": 0b100, "XORI": 0b100,
    "SRL": 0b101, "SRA": 0b101, "SRLI": 0b101, "SRAI": 0b101,
    "OR":  0b110, "ORI": 0b110,
    "AND": 0b111, "ANDI": 0b111,

    "LB": 0b000, "LH": 0b001, "LW": 0b010, "LBU": 0b100, "LHU": 0b101,
    "SB": 0b000, "SH": 0b001, "SW": 0b010,

    "BEQ": 0b000, "BNE": 0b001,
    "BLT": 0b100, "BGE": 0b101, "BLTU": 0b110, "BGEU": 0b111,

    "JALR": 0b000,
    "FENCE": 0b000,
    "ECALL": 0b000, "EBREAK": 0b000,
}

# funct7 field; SUB and SRA use the alternate encoding
FUNCT7 = {
    "ADD": 0b0000000, "SUB": 0b0100000,
    "SLL": 0b0000000, "SLT": 0b0000000, "SLTU": 0b0000000,
    "XOR": 0b0000000,
    "SRL": 0b0000000, "SRA": 0b0100000,
    "OR":  0b0000000, "AND": 0b0000000,
    "SLLI": 0b0000000, "SRLI": 0b0000000, "SRAI": 0b0100000,
}

R_TYPE  = ["ADD", "SUB", "AND", "OR", "XOR", "SLT", "SLTU", "SLL", "SRL", "SRA"]
I_ALU   = ["ADDI", "ANDI", "ORI", "XORI", "SLTI", "SLTIU"]
I_SHIFT = ["SLLI", "SRLI", "SRAI"]
LOADS   = ["LB", "LH", "LW", "LBU", "LHU"]
STORES  = ["SB", "SH", "SW"]
BRANCH  = ["BEQ", "BNE", "BLT", "BGE", "BLTU", "BGEU"]

# ABI register names
ABI = {
    "zero": 0, "ra": 1, "sp": 2, "gp": 3, "tp": 4,
    "t0": 5, "t1": 6, "t2": 7,
    "s0": 8, "fp": 8, "s1": 9,
    "a0": 10, "a1": 11, "a2": 12, "a3": 13,
    "a4": 14, "a5": 15, "a6": 16, "a7": 17,
    "s2": 18, "s3": 19, "s4": 20, "s5": 21, "s6": 22,
    "s7": 23, "s8": 24, "s9": 25, "s10": 26, "s11": 27,
    "t3": 28, "t4": 29, "t5": 30, "t6": 31,
}

# The testbench recognises this exact word as end-of-program
HALT_WORD = 0x00500013  # addi x0, x0, 5
# ---------------------------------------------------------------- parsing
def clean_line(raw):
    line = raw.split("#")[0]
    line = line.split("//")[0]
    return line.strip()


def split_operands(text):
    return [p.strip() for p in text.split(",") if p.strip()]


def reg_num(token):
    t = token.strip().lower()
    if t in ABI:
        return ABI[t]
    m = re.fullmatch(r"x(\d+)", t)
    if not m:
        raise ValueError(f"Invalid register: {token}")
    n = int(m.group(1))
    if not 0 <= n <= 31:
        raise ValueError(f"Register out of range: {token}")
    return n


def parse_int(token, labels=None, pc=None):
    t = token.strip()
    if labels is not None and t in labels:
        return labels[t]
    try:
        return int(t, 0)
    except ValueError:
        raise ValueError(f"Invalid immediate: {token}")


def parse_mem_operand(text, labels=None):
    """Parse `imm(rs1)`; a bare register means offset 0."""
    t = text.strip()
    m = re.fullmatch(r"(.*)\(\s*([^)]+)\s*\)", t)
    if m:
        imm_txt = m.group(1).strip()
        imm = parse_int(imm_txt, labels) if imm_txt else 0
        return imm, reg_num(m.group(2))
    # Bare register form
    return 0, reg_num(t)


def check_range(value, bits, signed=True, what="immediate"):
    if signed:
        lo, hi = -(1 << (bits - 1)), (1 << (bits - 1)) - 1
    else:
        lo, hi = 0, (1 << bits) - 1
    if not lo <= value <= hi:
        raise ValueError(
            f"{what} {value} does not fit in {bits} bits "
            f"(range {lo}..{hi})"
        )


# ---------------------------------------------------------------- encoders

def encode_r(instr, rd, rs1, rs2):
    return ((FUNCT7[instr] << 25) | (rs2 << 20) | (rs1 << 15)
            | (FUNCT3[instr] << 12) | (rd << 7) | OPCODES["R"])


def encode_i(instr, rd, rs1, imm):
    check_range(imm, 12, signed=True)
    return (((imm & 0xFFF) << 20) | (rs1 << 15)
            | (FUNCT3[instr] << 12) | (rd << 7) | OPCODES["I"])


def encode_shift_i(instr, rd, rs1, shamt):
    if not 0 <= shamt <= 31:
        raise ValueError(f"Shift amount out of range: {shamt}")
    return ((FUNCT7[instr] << 25) | (shamt << 20) | (rs1 << 15)
            | (FUNCT3[instr] << 12) | (rd << 7) | OPCODES["I"])


def encode_load(instr, rd, rs1, imm):
    check_range(imm, 12, signed=True)
    return (((imm & 0xFFF) << 20) | (rs1 << 15)
            | (FUNCT3[instr] << 12) | (rd << 7) | OPCODES["LOAD"])


def encode_store(instr, rs2, rs1, imm):
    check_range(imm, 12, signed=True)
    imm &= 0xFFF
    return ((((imm >> 5) & 0x7F) << 25) | (rs2 << 20) | (rs1 << 15)
            | (FUNCT3[instr] << 12) | ((imm & 0x1F) << 7) | OPCODES["STORE"])


def encode_branch(instr, rs1, rs2, offset):
    if offset & 1:
        raise ValueError(f"Branch offset must be even: {offset}")
    check_range(offset, 13, signed=True, what="branch offset")
    o = offset & 0x1FFF
    return ((((o >> 12) & 1) << 31) | (((o >> 5) & 0x3F) << 25)
            | (rs2 << 20) | (rs1 << 15) | (FUNCT3[instr] << 12)
            | (((o >> 1) & 0xF) << 8) | (((o >> 11) & 1) << 7)
            | OPCODES["BRANCH"])


def encode_jal(rd, offset):
    if offset & 1:
        raise ValueError(f"Jump offset must be even: {offset}")
    check_range(offset, 21, signed=True, what="jump offset")
    o = offset & 0x1FFFFF
    return ((((o >> 20) & 1) << 31) | (((o >> 1) & 0x3FF) << 21)
            | (((o >> 11) & 1) << 20) | (((o >> 12) & 0xFF) << 12)
            | (rd << 7) | OPCODES["JAL"])


def encode_jalr(rd, rs1, imm):
    check_range(imm, 12, signed=True)
    return (((imm & 0xFFF) << 20) | (rs1 << 15)
            | (FUNCT3["JALR"] << 12) | (rd << 7) | OPCODES["JALR"])


def encode_u(op, rd, imm20):
    check_range(imm20, 20, signed=False, what="upper immediate")
    return ((imm20 & 0xFFFFF) << 12) | (rd << 7) | OPCODES[op]


# ---------------------------------------------------------------- passes

# Pseudo-instructions that expand to more than one real instruction need
# their true size known during the label pass.
def pseudo_size(instr, operands):
    if instr == "LI":
        try:
            v = int(operands[1], 0)
        except ValueError:
            return 2   # label address: assume the safe two-instruction form
        # Fits in a 12-bit signed immediate -> single ADDI
        return 1 if -2048 <= v <= 2047 else 2
    if instr == "CALL":
        return 2
    return 1


def first_pass(lines):
    labels = {}
    instructions = []
    pc = 0

    for raw in lines:
        line = clean_line(raw)
        if not line:
            continue

        while ":" in line:
            label, rest = line.split(":", 1)
            label = label.strip()
            if not label:
                raise ValueError("Empty label")
            if label in labels:
                raise ValueError(f"Duplicate label: {label}")
            labels[label] = pc
            line = rest.strip()
            if not line:
                break

        if line:
            parts = line.split(None, 1)
            mnemonic = parts[0].upper()
            ops = split_operands(parts[1]) if len(parts) > 1 else []
            size = pseudo_size(mnemonic, ops)
            instructions.append((pc, line))
            pc += 4 * size

    return labels, instructions


def assemble_one(pc, line, labels):
    """Return a list of encoded words for one source line."""
    parts = line.split(None, 1)
    instr = parts[0].upper()
    operand_text = parts[1] if len(parts) > 1 else ""
    ops = split_operands(operand_text)

    def imm_of(tok):
        return parse_int(tok, labels)

    # ---- directives / specials
    if instr == "NOP":
        return [0x00000013]
    if instr == "HALT":
        return [HALT_WORD]
    if instr == "ECALL":
        return [OPCODES["SYSTEM"]]
    if instr == "EBREAK":
        return [(1 << 20) | OPCODES["SYSTEM"]]
    if instr == "FENCE":
        return [(0b1111 << 24) | (0b1111 << 20) | OPCODES["MISCMEM"]]

    # ---- pseudo-instructions
    if instr == "MV":
        return [encode_i("ADDI", reg_num(ops[0]), reg_num(ops[1]), 0)]
    if instr == "NOT":
        return [encode_i("XORI", reg_num(ops[0]), reg_num(ops[1]), -1)]
    if instr == "NEG":
        return [encode_r("SUB", reg_num(ops[0]), 0, reg_num(ops[1]))]
    if instr == "SEQZ":
        return [encode_i("SLTIU", reg_num(ops[0]), reg_num(ops[1]), 1)]
    if instr == "SNEZ":
        return [encode_r("SLTU", reg_num(ops[0]), 0, reg_num(ops[1]))]
    if instr == "J":
        return [encode_jal(0, imm_of(ops[0]) - pc)]
    if instr == "JR":
        return [encode_jalr(0, reg_num(ops[0]), 0)]
    if instr == "RET":
        return [encode_jalr(0, 1, 0)]
    if instr == "BEQZ":
        return [encode_branch("BEQ", reg_num(ops[0]), 0, imm_of(ops[1]) - pc)]
    if instr == "BNEZ":
        return [encode_branch("BNE", reg_num(ops[0]), 0, imm_of(ops[1]) - pc)]
    if instr == "LI":
        rd = reg_num(ops[0])
        val = imm_of(ops[1])
        if -2048 <= val <= 2047:
            return [encode_i("ADDI", rd, 0, val)]
        # LUI + ADDI, accounting for ADDI's sign extension
        upper = (val + 0x800) >> 12
        lower = val - (upper << 12)
        return [encode_u("LUI", rd, upper & 0xFFFFF),
                encode_i("ADDI", rd, rd, lower)]

    # ---- real instructions
    if instr in R_TYPE:
        return [encode_r(instr, reg_num(ops[0]), reg_num(ops[1]), reg_num(ops[2]))]

    if instr in I_ALU:
        return [encode_i(instr, reg_num(ops[0]), reg_num(ops[1]), imm_of(ops[2]))]

    if instr in I_SHIFT:
        return [encode_shift_i(instr, reg_num(ops[0]), reg_num(ops[1]), imm_of(ops[2]))]

    if instr in LOADS:
        imm, rs1 = parse_mem_operand(ops[1], labels)
        return [encode_load(instr, reg_num(ops[0]), rs1, imm)]

    if instr in STORES:
        imm, rs1 = parse_mem_operand(ops[1], labels)
        return [encode_store(instr, reg_num(ops[0]), rs1, imm)]

    if instr in BRANCH:
        return [encode_branch(instr, reg_num(ops[0]), reg_num(ops[1]),
                              imm_of(ops[2]) - pc)]

    if instr == "JAL":
        # jal offset  (rd defaults to ra) or jal rd, offset
        if len(ops) == 1:
            return [encode_jal(1, imm_of(ops[0]) - pc)]
        return [encode_jal(reg_num(ops[0]), imm_of(ops[1]) - pc)]

    if instr == "JALR":
        # Standard three-operand form, or the imm(rs1) form
        if len(ops) == 3:
            return [encode_jalr(reg_num(ops[0]), reg_num(ops[1]), imm_of(ops[2]))]
        if len(ops) == 2:
            imm, rs1 = parse_mem_operand(ops[1], labels)
            return [encode_jalr(reg_num(ops[0]), rs1, imm)]
        return [encode_jalr(1, reg_num(ops[0]), 0)]

    if instr in ("LUI", "AUIPC"):
        return [encode_u(instr, reg_num(ops[0]), imm_of(ops[1]))]

    raise ValueError(f"Unsupported instruction at PC {pc}: {line}")


def second_pass(instructions, labels):
    words = []
    for pc, line in instructions:
        try:
            encoded = assemble_one(pc, line, labels)
        except ValueError as e:
            raise ValueError(f"[PC 0x{pc:08x}] {line}\n  -> {e}")
        for i, w in enumerate(encoded):
            words.append((pc + 4 * i, line if i == 0 else f"  (cont) {line}", w))
    return words


def main():
    if len(sys.argv) != 3:
        print("Usage: asm_to_hex.py input.s output.hex")
        sys.exit(1)

    with open(sys.argv[1]) as f:
        lines = f.readlines()

    labels, instructions = first_pass(lines)
    words = second_pass(instructions, labels)

    with open(sys.argv[2], "w") as f:
        for _, _, word in words:
            f.write(f"{word:08x}\n")

    print(f"Assembled {len(words)} instructions")
    print(f"Wrote {sys.argv[2]}")

    print("\nAssembly listing:")
    for pc, line, word in words:
        print(f"0x{pc:08x}: {word:08x}    {line}")


if __name__ == "__main__":
    main()
