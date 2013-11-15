#include "serial.h"
#include "led.h"
#include "timer.h"

int main()
{
  led_init();
  led_blink();

  serial_init();
  serial_puts("Bootloader ready.\n\r");

  while(1){
    serial_putc(serial_getc());
  }

  return 0;
}
