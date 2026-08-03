/* Linker script for this core's Harvard memory map.
 *
 * The CPU has two physically separate memories, each indexed from address 0:
 *   - instruction memory (imem), fetched by the IF stage
 *   - data memory (dmem), accessed by loads and stores in the MEM stage
 *
 * A load from data address 0 and an instruction fetch from address 0 therefore
 * hit different memories. From the *program's* point of view, both .text and
 * .data must live at virtual address (VMA) 0.
 *
 * A single-address-space linker cannot place two sections at the same address,
 * so .data is given a distinct *load* address (LMA) via AT>, while keeping its
 * VMA at 0. The build script (build_and_convert.sh) extracts each section by
 * name into a separate hex image: .text -> program.hex (imem), .data ->
 * data.hex (dmem). Each memory is then loaded from 0 independently, which is
 * exactly what the hardware does.
 *
 * The LMA base for data (0x10000) is arbitrary: it only has to sit past the
 * end of .text so the two do not overlap in the ELF. It is never seen by the
 * CPU, which loads each hex image at 0.
 */
OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY
{
  IMEM (rx)  : ORIGIN = 0x00000000, LENGTH = 4K
  DMEM (rw)  : ORIGIN = 0x00000000, LENGTH = 4K
}

SECTIONS
{
  /* Instruction memory: VMA and LMA both 0, in IMEM. */
  .text.init : { *(.text.init) } > IMEM
  .text      : { *(.text) }      > IMEM

  /* Data memory: VMA 0 (how the program addresses it) but a distinct LMA
   * (0x10000) so the linker does not see an overlap with .text. */
  .data 0x0 : AT (0x10000) {
    _data_start = .;
    *(.data)
    *(.rodata*)
    _data_end = .;
  }

  .bss (NOLOAD) : { *(.bss) *(COMMON) } > DMEM

  _end = .;
}
