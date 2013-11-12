#include "serial.h"
#include "led.h"
#include "timer.h"

int bssvalue1;
char bssvalue2;
int data1 = 5;
char data2 = '5';

int main()
{
  data1 = 1;

  serial_init();
  serial_puts("Hello World!");

  led_init();
  led_scanner();

  buzzer(0.5, 10); // Buzz 2kHz 1s

  return 0;
}
