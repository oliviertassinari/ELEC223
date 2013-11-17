_start:
    // Initialization
    ldr r13,=0x0c7ffff0
	bl init
    bl main
    b _end

_end:
    //.word 0xdeeedeee
    // Prevent the end of the program
    b _end
