/* LDSCRIPT */

MEMORY
{
       FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
       RAM (!rx) :  ORIGIN = 0x0C000000, LENGTH = 1M
}

SECTIONS
{
       .text :
       {
                *(.text)
                *(.text*)
       } >RAM

       .rodata :
       {
                *(.rodata)
                *(.rodata*)
       } >RAM

       .data :
       {
                *(.data)
       } >RAM

       .bss :
       {
                _bss_start = .;
                *(.bss)
                *(COMMON)
                _bss_end = .;
       } >RAM
}