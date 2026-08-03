/* Linker script matching this core's actual memory map: separate 1024-word
   instruction and data memories (Harvard architecture), both addressed from
   0. Named MEMORY regions handle per-region placement automatically; do not
   manually reset the location counter between sections that target
   different regions, or the LMA calculation collides across regions that
   share the same origin address. */
OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY
{
  IMEM (rx)  : ORIGIN = 0x00000000, LENGTH = 4K
  DMEM (rw)  : ORIGIN = 0x00000000, LENGTH = 4K
}

SECTIONS
{
  .text.init : { *(.text.init) } > IMEM
  .text      : { *(.text) }      > IMEM

  .data      : { *(.data) }      > DMEM
  .bss       : { *(.bss) }       > DMEM
  _end = .;
}
