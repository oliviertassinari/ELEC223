_start:
    bl main
    b _end

_end:
    //.word 0xdeeedeee
    b _end