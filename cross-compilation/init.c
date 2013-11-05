#include <stdint.h>

// BSS segment start and end
extern uint8_t _bss_start, _bss_end;

void init()
{
  // BSS segment initialization
  uint8_t *p1 = &_bss_start;
  uint8_t *p2 = &_bss_end;

  while(p1 < p2)
    *p1++ = 0;
}
