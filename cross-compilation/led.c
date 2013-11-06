#include <stdint.h>
#include "led.h"
#include "port.h"

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

void led_init()
{
  // Input C1
  setPortOne(PCONC, 2);
  setPortZero(PCONC, 3);

  // Input C2
  setPortOne(PCONC, 4);
  setPortZero(PCONC, 5);

  // Input C3
  setPortOne(PCONC, 6);
  setPortZero(PCONC, 7);

  // Disable pull-up C1 - C3
  setPortMaskZero(PUPC, 7 << 1);

  // Input E5
  setPortOne(PCONE, 10);
  setPortZero(PCONE, 11);

  // Disable pull-up E5
  setPortOne(PUPE, 5);
}

void led_blink()
{
  // C1
  setPortZero(PDATC, 1);
  setPortOne(PDATC, 1);
  setPortZero(PDATC, 1);

  // C2
  setPortZero(PDATC, 2);
  setPortOne(PDATC, 2);
  setPortZero(PDATC, 2);

  // C3
  setPortZero(PDATC, 3);
  setPortOne(PDATC, 3);
  setPortZero(PDATC, 3);

  // E5
  setPortZero(PDATE, 5);
  setPortOne(PDATE, 5);
  setPortZero(PDATE, 5);
}
