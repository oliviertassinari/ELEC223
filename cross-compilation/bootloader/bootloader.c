
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
      return (h - 10) + 'a';
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
  serial_puts("\n\rBootloader ready.\n\r>");

  char instruction[13] = "";
  int instruction_ct = 0;
  char getc;
  uint32_t address = 0;



  while(1)
    {
      getc = serial_getc();

      if(instruction_ct < 12)
        {
          serial_putc(getc);

          instruction[instruction_ct] = getc;
          instruction_ct += 1;
        }
      else if(getc == '\n' || getc == '\r')
        {
          instruction_ct = 0;
          instruction[12] = '\0';
          serial_puts("\n\rCommande : '");
          serial_puts(instruction);
          serial_puts("'\n\r");

          for(int i = 0; i < 8; i++)
            {
              address += asciiToHex(instruction[4+i]) << (28 - i*4);
            }

          uint32_t * pointer = (uint32_t *)address;

          for(int j = 7; j >= 0; j--)
            {
              serial_putc(hexToAscii((*pointer >> 4*j) & 0xf));
            }

          serial_puts("\n\r>");
        }
    }

  return 0;
}
