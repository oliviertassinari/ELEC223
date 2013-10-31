#include <stdint.h>

extern uint32_t _bss_start, _bss_end;

void bootloader()
{
	// BSS segment initialization
	while(_bss_start < _bss_end)
		*_bss_start++ = 0;
}