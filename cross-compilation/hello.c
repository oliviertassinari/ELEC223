#include "serial.h"

int bssvalue1;
char bssvalue2;
int data1 = 5;
char data2 = '5';

int main()
{
  data1 = 1;

  serial_init();
  serial_puts("Hello World!");

  return 0;
}
