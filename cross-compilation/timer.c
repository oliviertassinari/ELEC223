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
#define TCNTB0 (*(volatile uint32_t *)0x01D5000C)

// TCMPB0 Timer 0 compare buffer register
#define TCMPB0 (*(volatile uint32_t *)0x01D50010)

// TCNTO0 Timer 0 count observation register
#define TCNTO0 (*(volatile uint32_t *)0x01D50014)

// TCNTB0 Timer 3 count buffer register
#define TCNTB3 (*(volatile uint32_t *)0x01D50030)

// TCMPB0 Timer 3 compare buffer register
#define TCMPB3 (*(volatile uint32_t *)0x01D50034)

// TCNTO0 Timer 3 count observation register
#define TCNTO3 (*(volatile uint32_t *)0x01D50038)


/**
 * 1 second
 * 32*(249+1)*8250 = 66 000 000
 */

void timer_sleep_1s()
{
  // Wait the end
  while(TCNTO0 != 0);

  // Set prescaler at 249
  setPortGroup(TCFG0, 0xff, 0, 249);

  // Set MUX at 32
  setPortGroup(TCFG1, 0xf, 0, 4);

  // Init count 8250
  TCNTB0 = 8250;
  TCMPB0 = 0;

  // Manual update timer 0
  setPortGroup(TCON, 0xf, 0, 2);

  // Start timer 0
  setPortGroup(TCON, 0xf, 0, 1);

  // Wait initialization
  while(TCNTO0 == 0);

  // Wait the end
  while(TCNTO0 != 0);
}

/**
 * Buzz at around 2kHz
 * 66 000 000 / 2*1*15000 = 2.2 kHz
 **/
void buzzer()
{
  // E6 Mode TOUT3
  setPortGroup(PCONE, 3, 12, 2);

  // E6 Disable pull-up
  setPort(PUPE, 6, 1);

  // Set prescaler at 0
  setPortGroup(TCFG0, 0xff, 8, 0);

  // Set MUX at 2
  setPortGroup(TCFG1, 0xf, 12, 0);

  // Init count 15000
  TCNTB3 = 15000;
  TCMPB3 = 7500;

  // Manual update timer 3
  setPortGroup(TCON, 0xf, 16, 2);

  // Start timer 3
  setPortGroup(TCON, 0xf, 16, 9);
}
