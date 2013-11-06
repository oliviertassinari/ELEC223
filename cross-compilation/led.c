#include <stdint.h>
#include "led.h"

// PCONC Configures the pins of port C
#define PCONC (*(volatile uint32_t *)0x01D20010)

// PDATC The data register for port C
#define PDATC (*(volatile uint32_t *)0x01D20014)

// PUPC Pull-up disable register for port C
#define PUPC (*(volatile uint32_t *)0x01D20018)


// PCONE Configures the pins of port E
#define PCONE (*(volatile uint32_t *)0x01D20028)

// PDATE The data register for port E
#define PDATE (*(volatile uint32_t *)0x01D2002C)

// PUPE Pull-up disable register for port E
#define PUPE (*(volatile uint32_t *)0x01D20030)


// Write port bits with a mask, other bits left alone
#define setPortBitZero(port, mask) ((port) &= ~(mask))
#define setPortBitOne(port, mask) ((port) |= (mask))


void led_init()
{
  // Input C1
  setPortBitOne(PCONC, 1 << 2);
  setPortBitZero(PCONC, 1 << 3);

  // Input C2
  setPortBitOne(PCONC, 1 << 4);
  setPortBitZero(PCONC, 1 << 5);

  // Input C3
  setPortBitOne(PCONC, 1 << 6);
  setPortBitZero(PCONC, 1 << 7);

  // Disable pull-up C1 - C3
  setPortBitZero(PUPC, 7 << 1);

  // Input E5
  setPortBitOne(PCONE, 1 << 10);
  setPortBitZero(PCONE, 1 << 11);

  // Disable pull-up E5
  setPortBitOne(PUPE, 1 << 5);
}

void led_blink()
{
  // PC1
  setPortBitZero(PDATC, 1 << 1);
  setPortBitOne(PDATC, 1 << 1);
  setPortBitZero(PDATC, 1 << 1);

  setPortBitZero(PDATC, 1 << 2);
  setPortBitOne(PDATC, 1 << 2);
  setPortBitZero(PDATC, 1 << 2);

  setPortBitZero(PDATC, 1 << 3);
  setPortBitOne(PDATC, 1 << 3);
  setPortBitZero(PDATC, 1 << 3);

  setPortBitZero(PDATE, 1 << 5);
  setPortBitOne(PDATE, 1 << 5);
  setPortBitZero(PDATE, 1 << 5);
}
