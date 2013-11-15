#include <stdint.h>
#include "serial.h"
#include "led.h"
#include "timer.h"

char hexToAscii(uint8_t h)
{
  if(h < 10)
    {
      return h + '0';
    }
  else
    {
      return (h - 10) + 'A';
    }
}

uint8_t asciiToHex(char a)
{
  if(a <= '9')
    {
      return a - '0';
    }
  else if(a <= 'F')
    {
      return a - 'A' + 10;
    }
  else if(a <= 'f')
    {
      return a - 'a' + 10;
    }
  else
    {
      return 0;
    }
}


int main()
{
  led_init();
  led_blink();

  serial_init();
  serial_puts("Bootloader ready.\n\r");

  char instruction[13] = "";
  int instruction_ct = 0;
  char getc;

  while(1)
    {
      getc = serial_getc();

      if(getc == '\n' || getc == '\r')
        {
          instruction_ct = 0;
          instruction[12] = '\0';
          serial_puts("\n\rCommande : '");
          serial_puts(instruction);
          serial_puts("'\n\r");
        }
      else if(instruction_ct < 12)
        {
          serial_putc(getc);
          serial_putc(hexToAscii(asciiToHex(getc)));

          instruction[instruction_ct] = getc;
          instruction_ct += 1;
        }
    }

  return 0;
}