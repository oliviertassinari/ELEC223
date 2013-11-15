#include <stdint.h>
#include "led.h"
#include "port.h"
#include "timer.h"

void led_init()
{
  // C1 Mode output
  setPortGroup(PCONC, 3, 2, 1);
  setPort(PDATC, 1, 0);

  // C2 Mode output
  setPortGroup(PCONC, 3, 4, 1);
  setPort(PDATC, 2, 0);

  // C3 Mode output
  setPortGroup(PCONC, 3, 6, 1);
  setPort(PDATC, 3, 0);

  // C1 - C3 Disable pull-up
  setPortMask(PUPC, 7 << 1, 0);

  // E5 Mode output
  setPortGroup(PCONC, 3, 10, 1);
  setPort(PDATE, 5, 0);

  // E5 Disable pull-up
  setPort(PUPE, 5, 1);
}

void led_blink()
{
  setPort(PDATC, 1, 1);
  setPort(PDATE, 5, 1);

  timer_sleep(5);

  setPort(PDATC, 1, 0);
  setPort(PDATE, 5, 0);

  setPort(PDATC, 2, 1);
  setPort(PDATC, 3, 1);

  timer_sleep(5);

  setPort(PDATC, 2, 0);
  setPort(PDATC, 3, 0);
}

/**
 * Create led scanner effect
 **/
void led_scanner()
{
  // C1
  setPort(PDATC, 1, 1);
  timer_sleep(10);
  setPort(PDATC, 1, 0);
  timer_sleep(10);

  // C2
  setPort(PDATC, 2, 1);
  timer_sleep(10);
  setPort(PDATC, 2, 0);
  timer_sleep(10);

  // C3
  setPort(PDATC, 3, 1);
  timer_sleep(10);
  setPort(PDATC, 3, 0);
  timer_sleep(10);

  // E5
  setPort(PDATE, 5, 1);
  timer_sleep(10);
  setPort(PDATE, 5, 0);
}
