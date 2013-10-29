#include "serial.h"

int main()
{
  serial_init();
  serial_putc("A");
  serial_puts("Hello World!");

  return 1;
}
