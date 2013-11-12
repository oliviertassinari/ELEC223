#include "serial.h"
#include "led.h"
#include "timer.h"

int bssvalue1;
char bssvalue2;
int data1 = 5;
char data2 = '5';

//       note, periode(ms), frequency.
#define  MI6     0.753    // 1328 Hz
#define  SI5     0.101    // 988 Hz
#define  DO6     0.956    // 1046 Hz
#define  RE6     0.851    // 1175 Hz
#define  LA5     1.13    // 880 Hz
#define  SOL6    0.638    // 1568 Hz
#define  FA6     0.716    // 1397 Hz
#define  LA6     0.568    // 1760 Hz
#define  R       0 		// Pause

int main()
{
  data1 = 1;

  serial_init();
  serial_puts("Hello World!");

  led_init();
  led_scanner();

  buzzer(0.5, 10); // Buzz 2kHz 1s

  // Tetris melody

  int melody[] = {MI6, R,  SI5, DO6, SI5, R, LA5, DO6, MI6, R, RE6, DO6, SI5, R, RE6};
  int MAX_COUNT = sizeof(melody);

  for (int i=0; i<MAX_COUNT; i++)
  {
 	buzzer(melody[i], 4);
  }

  return 0;
}
