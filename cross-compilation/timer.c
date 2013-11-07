#include <stdint.h>
#include "timer.h"
#include "port.h"

// TCFG0 Configures the three 8-bit prescalers
#define TCFG0 (*(volatile uint32_t *)0x01D50000)

// TCFG1 6-MUX & DMA mode selecton register
#define TCFG1 (*(volatile uint32_t *)0x01D50004)

// TCON Timer control register
#define TCON (*(volatile uint32_t *)0x01D50008)

// TCNTB0 Timer 0 count buffer register
#define TCNTB0 (*(volatile uint16_t *)0x01D5000C)

// TCNTB0 Timer 1 count buffer register
#define TCNTB1 (*(volatile uint16_t *)0x01D50018)

/**
 * 1 second
 * 32*(249+1)*8250 = 66 000 000
 */

void timer_sleep_1s()
{
  while(TCNTB0 != 0 && TCNTB1 != 0);


}
