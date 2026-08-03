#!/bin/bash
# build_and_convert.sh <input.S> <output.hex>
#
# Compiles an official riscv-tests source file (or anything written against
# the same riscv_test.h / test_macros.h conventions) into a readmemh-format
# hex image, using this core's actual memory map.
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

if [ $# -ne 2 ]; then
    echo "Usage: build_and_convert.sh <input.S> <output.hex>" >&2
    exit 1
fi

SRC="$1"
OUT_HEX="$2"

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

riscv64-unknown-elf-objcopy -O binary "$WORK/out.elf" "$WORK/out.bin"

python3 -c "
import struct
with open('$WORK/out.bin', 'rb') as f:
    data = f.read()
while len(data) % 4 != 0:
    data += b'\x00'
words = struct.unpack('<' + 'I' * (len(data) // 4), data)
with open('$OUT_HEX', 'w') as f:
    for w in words:
        f.write(f'{w:08x}\n')
"
