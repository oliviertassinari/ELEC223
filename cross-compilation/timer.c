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

// TCNTO0 Timer 0 count observation register
#define TCNTO0 (*(volatile uint16_t *)0x01D50014)


/**
 * 1 second
 * 32*(249+1)*8250 = 66 000 000
 */

void timer_sleep_1s()
{
  // Set prescaler at 249
  setPortGroup(TCFG0, 0xff, 0, 249);

  // Set MUX at 32
  setPortGroup(TCFG1, 0xf, 0, 4);

  // Init count
  TCNTB0 = 8250;

  // Start timer 0
  setPortGroup(TCON, 0xf, 0, 3);

  while(TCNTO0 != 0);
}
