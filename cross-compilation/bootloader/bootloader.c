#include "serial.h"
#include "led.h"
#include "timer.h"

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
          serial_puts("\n\rCommande : ");
          serial_puts(instruction);
          serial_puts("\n\r");
        }
    }

  return 0;
}
