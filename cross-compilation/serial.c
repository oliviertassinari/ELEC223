#include <stdint.h>
#include "serial.h"

#define baudValue (33000000 / (115200 * 16) + 0.5)

// Status register
#define UTRSTAT0 (*(volatile uint8_t *)0x01D0010)

// Transmission data
#define UTXH0 (*(volatile uint8_t *)0x01D0020)

// Received data
#define URXH0 (*(volatile uint8_t *)0x01D024)

// Line control register
#define ULCON0 (*(volatile uint8_t *)0x01D0000)

// Control register
#define UCON0 (*(volatile uint16_t *)0x01D0004)

// Baud rate divisior
#define UBRDIV0 (*(volatile uint16_t *)0x01D0028)


/**
   Functions designed to use the serial port 0
**/

void serial_init()
{
  ULCON0 = 0x3;
  UCON0 = 0x5;
  UBRDIV0 = 0x22;
}

void serial_putc(char c)
{
  // We wait an empty buffer
  while((UTRSTAT0 & (1 << 1)) == 0){}
  UTXH0 = c;
}

char serial_getc()
{
  // We wait data
  while((UTRSTAT0 & (1 << 0)) == 0){}
  return URXH0;
}

void serial_puts(char string[])
{
  char charCurrent = 0;
  int i = 0;

  do
    {
      charCurrent = string[++i];
      serial_putc(charCurrent);
    }
  while(charCurrent != '\0');
}
