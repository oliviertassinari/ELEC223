#include "serial.h"
#include "led.h"
#include "timer.h"

int bssvalue1;
char bssvalue2;
int data1 = 5;
char data2 = '5';

//       note, periode(ms), frequency.
#define  MI6     753    // 1328 Hz
#define  SI5     101    // 988 Hz
#define  DO6     956    // 1046 Hz
#define  RE6     851    // 1175 Hz
#define  LA5     113    // 880 Hz
#define  SOL6    638    // 1568 Hz
#define  FA6     716    // 1397 Hz
#define  LA6     568    // 1760 Hz
#define  R       0 		// Pause

int main()
{
  data1 = 1;

  serial_init();
  serial_puts("Hello World!");

  led_init();
  led_scanner();

  // Buzz 2kHz 1s
  buzzer(500, 10);
  timer_sleep(10);
  buzzer(500, 10);

  // Tetris melody
  int melody[] = {MI6, R,  SI5, DO6, SI5, R, LA5, DO6, MI6, R, RE6, DO6, SI5, R, RE6};

  for (int i=0; i<14; i++)
  {
 	buzzer(melody[i], 4);
  }

  return 0;
}
