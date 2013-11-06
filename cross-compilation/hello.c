#include "serial.h"
#include "led.h"

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
  led_blink();

  return 0;
}
