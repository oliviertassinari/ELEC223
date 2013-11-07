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
  // C1 Mode output
  setPort(PCONC, 2, 1);
  setPort(PCONC, 3, 0);
  setPort(PDATC, 1, 0);

  // C2 Mode output
  setPort(PCONC, 4, 1);
  setPort(PCONC, 5, 0);
  setPort(PDATC, 2, 0);

  // C3 Mode output
  setPort(PCONC, 6, 1);
  setPort(PCONC, 7, 0);
  setPort(PDATC, 3, 0);

  // C1 - C3 Disable pull-up
  setPortMask(PUPC, 7 << 1, 0);

  // E5 Mode output
  setPort(PCONE, 10, 1);
  setPort(PCONE, 11, 0);
  setPort(PDATE, 5, 0);

  // E5 Disable pull-up
  setPort(PUPE, 5, 1);
}


/**
 * Create led scanner effect
 **/
void led_scanner()
{
  int i;

  // C1
  setPort(PDATC, 1, 1);
  for(i = 0; i < 500000; i++);
  setPort(PDATC, 1, 0);
  for(i = 0; i < 500000; i++);

  // C2
  setPort(PDATC, 2, 1);
  for(i = 0; i < 500000; i++);
  setPort(PDATC, 2, 0);
  for(i = 0; i < 500000; i++);

  // C3
  setPort(PDATC, 3, 1);
  for(i = 0; i < 500000; i++);
  setPort(PDATC, 3, 0);
  for(i = 0; i < 500000; i++);

  // E5
  setPort(PDATE, 5, 1);
  for(i = 0; i < 500000; i++);
  setPort(PDATE, 5, 0);
}
