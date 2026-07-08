#!/usr/bin/env python3

import sys
import re

OPCODES = {
    "R":      0b0110011,
    "I":      0b0010011,
    "LOAD":   0b0000011,
    "STORE":  0b0100011,
    "BRANCH": 0b1100011,
    "JALR":   0b1100111,
    "JAL":    0b1101111,
    "LUI":    0b0110111,
}

FUNCT3 = {
    "ADD":  0b000,
    "SUB":  0b000,
    "ADDI": 0b000,

    "SLL":  0b001,
    "SLLI": 0b001,

    "SLT":  0b010,
    "SLTI": 0b010,

    "XOR":  0b100,
    "XORI": 0b100,

    "SRL":  0b101,
    "SRLI": 0b101,

    "OR":   0b110,
    "ORI":  0b110,

    "AND":  0b111,
    "ANDI": 0b111,

    "LW":   0b010,
    "SW":   0b010,

    "BEQ":  0b000,
    "BNE":  0b001,
    "BLT":  0b100,
    "BGE":  0b101,

    "JALR": 0b000,
}

FUNCT7 = {
    "ADD": 0b0000000,
    "SUB": 0b0100000,
    "SLL": 0b0000000,
    "SLT": 0b0000000,
    "XOR": 0b0000000,
    "SRL": 0b0000000,
    "OR":  0b0000000,
    "AND": 0b0000000,
}

REG_ALIASES = {
    "zero": 0,
    "ra": 1,
    "sp": 2,
    "gp": 3,
    "tp": 4,
}


def clean_line(line):
    line = line.split("#")[0]
    line = line.split("//")[0]
    return line.strip()


def parse_int(value):
    value = value.strip()

    if value.lower().startswith("0x"):
        return int(value, 16)

    return int(value, 10)


def reg_num(reg):
    reg = reg.strip().lower()

    if reg in REG_ALIASES:
        return REG_ALIASES[reg]

    if not reg.startswith("x"):
        raise ValueError(f"Invalid register name: {reg}")

    n = int(reg[1:])

    if n < 0 or n > 31:
        raise ValueError(f"Register out of range: {reg}")

    return n


def parse_imm(value, labels, pc):
    value = value.strip()

    if value in labels:
        return labels[value] - pc

    return parse_int(value)


def parse_absolute_or_imm(value, labels):
    value = value.strip()

    if value in labels:
        return labels[value]

    return parse_int(value)


def parse_mem_operand(text):
    """
    Parses memory operand format:
        imm(rs1)

    Example:
        0(x0)
        8(x2)
        -4(x5)
    """
    text = text.strip()

    match = re.match(
        r"(-?\d+|0x[0-9a-fA-F]+)\((x\d+|zero|ra|sp|gp|tp)\)",
        text
    )

    if not match:
        raise ValueError(f"Invalid memory operand: {text}")

    imm = parse_int(match.group(1))
    rs1 = reg_num(match.group(2))

    return imm, rs1


def split_operands(text):
    if text.strip() == "":
        return []

    return [part.strip() for part in text.split(",")]


def encode_r(instr, rd, rs1, rs2):
    return (
        (FUNCT7[instr] << 25)
        | (rs2 << 20)
        | (rs1 << 15)
        | (FUNCT3[instr] << 12)
        | (rd << 7)
        | OPCODES["R"]
    )


def encode_i_alu(instr, rd, rs1, imm):
    imm &= 0xFFF

    return (
        (imm << 20)
        | (rs1 << 15)
        | (FUNCT3[instr] << 12)
        | (rd << 7)
        | OPCODES["I"]
    )


def encode_shift_i(instr, rd, rs1, shamt):
    shamt &= 0x1F

    return (
        (0b0000000 << 25)
        | (shamt << 20)
        | (rs1 << 15)
        | (FUNCT3[instr] << 12)
        | (rd << 7)
        | OPCODES["I"]
    )


def encode_lw(rd, rs1, imm):
    imm &= 0xFFF

    return (
        (imm << 20)
        | (rs1 << 15)
        | (FUNCT3["LW"] << 12)
        | (rd << 7)
        | OPCODES["LOAD"]
    )


def encode_sw(rs2, rs1, imm):
    imm &= 0xFFF

    imm_11_5 = (imm >> 5) & 0x7F
    imm_4_0  = imm & 0x1F

    return (
        (imm_11_5 << 25)
        | (rs2 << 20)
        | (rs1 << 15)
        | (FUNCT3["SW"] << 12)
        | (imm_4_0 << 7)
        | OPCODES["STORE"]
    )


def encode_branch(instr, rs1, rs2, imm):
    if imm % 2 != 0:
        raise ValueError(f"Branch immediate must be 2-byte aligned: {imm}")

    imm &= 0x1FFF

    bit_12    = (imm >> 12) & 0x1
    bit_11    = (imm >> 11) & 0x1
    bits_10_5 = (imm >> 5)  & 0x3F
    bits_4_1  = (imm >> 1)  & 0xF

    return (
        (bit_12 << 31)
        | (bits_10_5 << 25)
        | (rs2 << 20)
        | (rs1 << 15)
        | (FUNCT3[instr] << 12)
        | (bits_4_1 << 8)
        | (bit_11 << 7)
        | OPCODES["BRANCH"]
    )


def encode_jal(rd, imm):
    if imm % 2 != 0:
        raise ValueError(f"JAL immediate must be 2-byte aligned: {imm}")

    imm &= 0x1FFFFF

    bit_20     = (imm >> 20) & 0x1
    bits_10_1  = (imm >> 1)  & 0x3FF
    bit_11     = (imm >> 11) & 0x1
    bits_19_12 = (imm >> 12) & 0xFF

    return (
        (bit_20 << 31)
        | (bits_10_1 << 21)
        | (bit_11 << 20)
        | (bits_19_12 << 12)
        | (rd << 7)
        | OPCODES["JAL"]
    )


def encode_jalr(rd, rs1, imm):
    imm &= 0xFFF

    return (
        (imm << 20)
        | (rs1 << 15)
        | (FUNCT3["JALR"] << 12)
        | (rd << 7)
        | OPCODES["JALR"]
    )


def encode_lui(rd, imm20):
    imm20 &= 0xFFFFF

    return (
        (imm20 << 12)
        | (rd << 7)
        | OPCODES["LUI"]
    )


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
            instructions.append((pc, line))
            pc += 4

    return labels, instructions


def second_pass(instructions, labels):
    words = []

    for pc, line in instructions:
        parts = line.split(None, 1)
        instr = parts[0].upper()
        operand_text = parts[1] if len(parts) > 1 else ""
        operands = split_operands(operand_text)

        if instr == "NOP":
            word = 0x00000013

        elif instr == "HALT":
            word = 0x00500013

        elif instr in ["ADD", "SUB", "AND", "OR", "XOR", "SLT", "SLL", "SRL"]:
            rd = reg_num(operands[0])
            rs1 = reg_num(operands[1])
            rs2 = reg_num(operands[2])
            word = encode_r(instr, rd, rs1, rs2)

        elif instr in ["ADDI", "ANDI", "ORI", "XORI", "SLTI"]:
            rd = reg_num(operands[0])
            rs1 = reg_num(operands[1])
            imm = parse_absolute_or_imm(operands[2], labels)
            word = encode_i_alu(instr, rd, rs1, imm)

        elif instr in ["SLLI", "SRLI"]:
            rd = reg_num(operands[0])
            rs1 = reg_num(operands[1])
            shamt = parse_int(operands[2])
            word = encode_shift_i(instr, rd, rs1, shamt)

        elif instr == "LW":
            rd = reg_num(operands[0])
            imm, rs1 = parse_mem_operand(operands[1])
            word = encode_lw(rd, rs1, imm)

        elif instr == "SW":
            rs2 = reg_num(operands[0])
            imm, rs1 = parse_mem_operand(operands[1])
            word = encode_sw(rs2, rs1, imm)

        elif instr in ["BEQ", "BNE", "BLT", "BGE"]:
            rs1 = reg_num(operands[0])
            rs2 = reg_num(operands[1])
            imm = parse_imm(operands[2], labels, pc)
            word = encode_branch(instr, rs1, rs2, imm)

        elif instr == "JAL":
            rd = reg_num(operands[0])
            imm = parse_imm(operands[1], labels, pc)
            word = encode_jal(rd, imm)

        elif instr == "JALR":
            rd = reg_num(operands[0])
            imm, rs1 = parse_mem_operand(operands[1])
            word = encode_jalr(rd, rs1, imm)

        elif instr == "LUI":
            rd = reg_num(operands[0])
            imm20 = parse_int(operands[1])
            word = encode_lui(rd, imm20)

        else:
            raise ValueError(f"Unsupported instruction at PC {pc}: {line}")

        words.append((pc, line, word))

    return words


def main():
    if len(sys.argv) != 3:
        print("Usage: asm_to_hex.py input.s output.hex")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    with open(input_file, "r") as f:
        lines = f.readlines()

    labels, instructions = first_pass(lines)
    words = second_pass(instructions, labels)

    with open(output_file, "w") as f:
        for _, _, word in words:
            f.write(f"{word:08x}\n")

    print(f"Assembled {len(words)} instructions")
    print(f"Wrote {output_file}")

    print("\nAssembly listing:")
    for pc, line, word in words:
        print(f"0x{pc:08x}: {word:08x}    {line}")


if __name__ == "__main__":
    main()