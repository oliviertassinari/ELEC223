
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

  char instruction[13] = "";
  int instruction_ct = 0;
  char getc = 0;
  uint32_t address = 0;

  serial_init();
  serial_puts("\n\rBootloader ready.\n\r");
  serial_puts("\tL <addr> : load\n\r");
  serial_puts("\tG <addr> : execute\n\r");
  serial_puts("\tR <addr> : read\n\r");
  serial_puts("\t  <addr> : 0x........\n\n\r");
  serial_puts(">");

  while(1)
    {
      getc = serial_getc();

      if(instruction_ct < 12)
        {
          serial_putc(getc);
          instruction[instruction_ct++] = getc;
        }
      else if(getc == '\n' || getc == '\r') //Entrer
        {
          serial_puts("\n\rCommande : '");
          serial_puts(instruction);
          serial_puts("'\n\r");

          address = 0;

          for(int i = 0; i < 8; i++)
            {
              address += asciiToHex(instruction[4+i]) << (28 - i*4);
            }

          uint32_t * pointer = (uint32_t *)address;

          switch(instruction[0])
          {
            case 'L':
              break;
            case 'G':
              break;
            case 'R':
              serial_puts("Read : ");
              for(int j = 7; j >= 0; j--)
                {
                  serial_putc(hexToAscii((*pointer >> 4*j) & 0xf));
                }
              break;
          }

          serial_puts("\n\r>");
          instruction[12] = '\0';
          instruction_ct = 0;
        }
    }

  return 0;
}
