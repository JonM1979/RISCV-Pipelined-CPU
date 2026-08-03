#!/bin/bash
# build_and_convert.sh <input.S> <text_out.hex> [data_out.hex]
#
# Compiles an official riscv-tests source file (or anything written against
# the same riscv_test.h / test_macros.h conventions) into readmemh-format hex
# images matching this core's Harvard memory map.
#
#   <text_out.hex>  instruction image, loaded into imem   (always written)
#   [data_out.hex]  data image, loaded into dmem          (optional)
#
# If a data output path is given, this script always writes it: a real .data
# image for tests that have one, or an all-zero image otherwise, so the
# testbench's unconditional $readmemh never fails on a missing file.
#
# Requires the RISC-V GNU toolchain:
#   sudo apt-get install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf
#
# This is a SEPARATE build path from tools/asm_to_hex.py. The official test
# sources use C-preprocessor #include directives and GNU assembler macros
# (.macro/.endm) that a hand-written two-pass assembler has no way to parse
# without reimplementing a preprocessor. Compiling them for real, through the
# real toolchain, is simpler and more trustworthy than approximating that.
set -euo pipefail

if [ $# -lt 2 ] || [ $# -gt 3 ]; then
    echo "Usage: build_and_convert.sh <input.S> <text_out.hex> [data_out.hex]" >&2
    exit 1
fi

SRC="$1"
OUT_TEXT="$2"
OUT_DATA="${3:-}"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ENV_DIR="$SCRIPT_DIR/env-mini"
VENDOR_DIR="$SCRIPT_DIR/vendor"

if ! command -v riscv64-unknown-elf-gcc >/dev/null 2>&1; then
    echo "ERROR: riscv64-unknown-elf-gcc not found." >&2
    echo "Install it with:" >&2
    echo "  sudo apt-get install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf" >&2
    exit 1
fi

WORK=$(mktemp -d)
trap 'rm -rf "$WORK"' EXIT

riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 \
    -nostdlib -nostartfiles -static \
    -I "$ENV_DIR" -I "$VENDOR_DIR" \
    -T "$ENV_DIR/link.ld" \
    -o "$WORK/out.elf" "$SRC"

# bin2hex: little-endian 32-bit words, one per line, zero-padded to WORDS lines
bin2hex() {
    local bin="$1" hex="$2"
    python3 -c "
import struct, sys
with open('$bin','rb') as f: data = f.read()
while len(data) % 4: data += b'\x00'
words = struct.unpack('<' + 'I'*(len(data)//4), data) if data else ()
with open('$hex','w') as f:
    for w in words: f.write(f'{w:08x}\n')
"
}

# Instruction image: extract only the code sections by name, so the distinct
# .data load address does not blow the binary up with a huge zero gap.
riscv64-unknown-elf-objcopy -O binary \
    -j .text.init -j .text \
    "$WORK/out.elf" "$WORK/text.bin"
bin2hex "$WORK/text.bin" "$OUT_TEXT"

# Data image, only if requested.
if [ -n "$OUT_DATA" ]; then
    # Extract .data/.rodata if present; objcopy yields an empty file if absent.
    riscv64-unknown-elf-objcopy -O binary \
        -j .data -j .rodata \
        "$WORK/out.elf" "$WORK/data.bin" 2>/dev/null || : > "$WORK/data.bin"

    if [ ! -s "$WORK/data.bin" ]; then
        # No data section: emit a single zero word so $readmemh has a valid,
        # non-empty file to load. Unreferenced by tests that have no data.
        printf '00000000\n' > "$OUT_DATA"
    else
        bin2hex "$WORK/data.bin" "$OUT_DATA"
    fi
fi
