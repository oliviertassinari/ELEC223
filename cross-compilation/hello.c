#include "serial.h"
#include "led.h"
#include "timer.h"

int bssvalue1;
char bssvalue2;
int data1 = 5;
char data2 = '5';

//       note, frequency.
#define  c     0.261    // 261 Hz
#define  d     0.293    // 293 Hz
#define  e     0.329    // 329 Hz
#define  f     0.349    // 349 Hz
#define  g     0.392    // 392 Hz
#define  a     0.440    // 440 Hz
#define  b     0.493    // 493 Hz
#define  C     0.523    // 523 Hz
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
