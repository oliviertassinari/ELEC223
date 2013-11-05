#include <stdint.h>

extern uint32_t _bss_start, _bss_end;

void init()
{
  uint32_t *p1 = &_bss_start;
  uint32_t *p2 = &_bss_end;

  // BSS segment initialization
  while(p1 < p2)
    *p1++ = 0;
}
