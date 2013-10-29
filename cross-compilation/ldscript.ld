/* LDSCRIPT */

MEMORY
{
       rom (rx) : ORIGIN = 0, LENGTH = 256K
       ram (!rx): ORIGIN = 0x0C000000, LENGTH = 1M
}

SECTIONS
{
       .text :
       {
                *(.text)
       } > ram

       .rodata :
       {
                *(.rodata)
       } > ram

       .data :
       {
                *(.data)
       } > ram

       .bss :
       {
                __bss_start__ = .;
                *(.bss)
                __bss_end__ = .;
       } > ram

       _exit = .;
}