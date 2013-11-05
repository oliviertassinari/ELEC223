#include "serial.h"

int bssvalue1;
int bssvalue2;
int data1 = 5;

int main()
{
  serial_init();
  serial_puts("Hello World!");

  return 0;
}
