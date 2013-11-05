_start:
    // Initialization
	bl init
    bl main
    b _end

_end:
    //.word 0xdeeedeee
    // Prevent the end of the program
    b _end