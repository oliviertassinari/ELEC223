#include <stdint.h>
#include "timer.h"
#include "port.h"

/**
 * @note            66 000 000 / 32*(1+249)*8250 = 1 s
 *
 * @param time      in deca seconde
 **/
void timer_start(int time)
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
}

void timer_stop()
{
  // Stop timer 0
  setPort(TCON, 0, 0);
}

void timer_sleep(int time)
{
  timer_start(time);

  // Wait the end
  while(TCNTO0 != 0);

  timer_stop();
}

/**
 * @note               66 000 000 / 2*(1+32)*1000 = 1 kHz
 *
 * @param periode      in micro seconde
 **/
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

      // Init count 3
      TCNTB3 = periode;
      TCMPB3 = periode >> 1;

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
