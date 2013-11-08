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
 * @note            66 000 000 / 32*(1+249)*8250 = 1 s
 *
 * @param time      in deca seconde
 */
void timer_sleep(int time)
{
  // Wait stopped timer 0
  while((TCON & 1) == 1);

  // Set prescaler at 249
  setPortGroup(TCFG0, 0xff, 0, 249);

  // Set MUX at 32
  setPortGroup(TCFG1, 0xf, 0, 4);

  // Init count 8250
  TCNTB0 = 825*time;
  TCMPB0 = 0;

  // Manual update timer 0
  setPortGroup(TCON, 0xf, 0, 2);

  // Start timer 0
  setPortGroup(TCON, 0xf, 0, 1);

  // Wait initialization
  while(TCNTO0 == 0);

  // Wait the end
  while(TCNTO0 != 0);

  // Stop timer 0
  setPort(TCON, 0, 0);
}

/**
 * @note                 66 000 000 / 2*(1+32)*1000 = 1 kHz
 *
 * @param periode      in ms
 */
void buzzer_start(int periode)
{
  if(periode != 0)
  {
    // Wait stopped timer 3
    while((TCON & (1 << 16)) == 1);

    // E6 Mode TOUT3
    setPortGroup(PCONE, 3, 12, 2);

    // E6 Disable pull-up
    setPort(PUPE, 6, 1);

    // Set prescaler at 32
    setPortGroup(TCFG0, 0xff, 8, 32);

    // Set MUX at 2
    setPortGroup(TCFG1, 0xf, 12, 0);

    int ct = periode*1000;

    // Init count 3
    TCNTB3 = ct;
    TCMPB3 = ct >> 1;

    // Manual update timer 3
    setPortGroup(TCON, 0xf, 16, 2);

    // Start timer 3
    setPortGroup(TCON, 0xf, 16, 9);
  }
}

void buzzer_end()
{
  // Stop timer 3
  setPort(TCON, 16, 0);
}

void buzzer(int periode, int time)
{
  buzzer_start(periode);
  timer_sleep(time);
  buzzer_end();
}
