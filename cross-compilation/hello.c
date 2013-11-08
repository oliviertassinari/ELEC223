#include "serial.h"
#include "led.h"
#include "timer.h"

int bssvalue1;
char bssvalue2;
int data1 = 5;
char data2 = '5';

//       note, periode, frequency.
#define  c     3.83    // 261 Hz
#define  d     3.41    // 293 Hz
#define  e     3.04    // 329 Hz
#define  f     2.86    // 349 Hz
#define  g     2.55    // 392 Hz
#define  a     2.27    // 440 Hz
#define  b     2.03    // 493 Hz
#define  C     1.91    // 523 Hz
#define  R     0 		// Pause

int main()
{
  data1 = 1;

  serial_init();
  serial_puts("Hello World!");

  led_init();
  led_scanner();

  buzzer(2, 1);

  int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
  int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 };
  int MAX_COUNT = sizeof(melody);

  for (int i=0; i<MAX_COUNT; i++)
  {
 	buzzer(melody[i], beats[i]/50);
  }

  return 0;
}
