#include <stdint.h>
#include "serial.h"
#include "led.h"
#include "timer.h"
#include "convert.h"

extern uint32_t _bss_end;

int main()
{
  led_init();
  led_blink();

  char instruction[13];
  int instruction_ct;
  char getc;
  uint32_t address;
  uint32_t * pointer;
  void (*execute)(void);

  serial_init();
  serial_puts("\n\rBootloader ready.\n\r");
  serial_puts("\tL <addr> : load\n\r");
  serial_puts("\tG <addr> : execute\n\r");
  serial_puts("\tR <addr> : read\n\r");
  serial_puts("\t  <addr> : 0x........\n\n\r");

  instruction[12] = '\0';
  serial_puts(">");
  instruction_ct = 0;

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

          if(instruction[2] == '0' && instruction[3] == 'x')
            {
              for(int i = 0; i < 8; i++)
                {
                  address += asciiToHex(instruction[4+i]) << (28 - i*4);
                }
            }

          // Test wrong address
          if(0)
            //if(address <= (uint32_t)(&_bss_end))
            {
              serial_puts("Wrong address : 0x");
              serial_puti32(address);
              serial_puts("\n\rIt must be over 0x");
              serial_puti32(_bss_end);
            }
          else
            {
              switch(instruction[0])
                {
                case 'L':
                  serial_puts("Load : 0x");

                  uint32_t value = 0;
                  int value_ct = 0;

                  pointer = (uint32_t *)address;

                  while(serial_getc_timeout(&getc, 50)) // 5s
                    {
                      serial_putc(getc);

                      value += asciiToHex(getc) << (28 - value_ct++*4);

                      // Load
                      if(value_ct == 8)
                        {
                          *pointer++ = value;
                          value_ct = 0;
                          value = 0;
                          serial_puts(" done\n\rLoad : 0x");
                        }
                    }

                  serial_puts("\n\rTime out 5s");

                  break;
                case 'G':
                  serial_puts("Execute : 0x");
                  serial_puti32(address);
                  execute = (void *)address;
                  execute();
                  break;
                case 'R':
                  serial_puts("Read : 0x");
                  pointer = (uint32_t *)address;
                  serial_puti32(*pointer);
                  break;
                default:
                  serial_puts("Wrong command");
                  break;
                }
            }

          instruction[12] = '\0';
          serial_puts("\n\r>");
          instruction_ct = 0;
        }
    }

  return 0;
}
