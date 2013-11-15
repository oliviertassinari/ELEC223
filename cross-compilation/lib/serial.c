#include <stdint.h>
#include "serial.h"

// Status register
#define UTRSTAT0 (*(volatile uint32_t *)0x01D00010)

// Transmission data
#define UTXH0 (*(volatile uint8_t *)0x01D00020)

// Received data
#define URXH0 (*(volatile uint8_t *)0x01D00024)

// Line control register
#define ULCON0 (*(volatile uint32_t *)0x01D00000)

// Control register
#define UCON0 (*(volatile uint32_t *)0x01D00004)

// Baud rate divisior
#define UBRDIV0 (*(volatile uint32_t *)0x01D00028)


/**
 *  Functions designed to use the serial port 0
 */

void serial_init()
{
  ULCON0 = 0x3;
  UCON0 = 0x5;

  // (round_off)(MCLK / (bps x 16) ) -1
  UBRDIV0 = 0x23;
}

void serial_putc(char c)
{
  // We wait an empty buffer
  while((UTRSTAT0 & (1 << 1)) == 0);
  UTXH0 = c;
}

char serial_getc()
{
  // We wait data
  while((UTRSTAT0 & (1 << 0)) == 0);
  return URXH0;
}

void serial_puts(const char* s)
{
  while(*s != '\0')
    serial_putc(*s++);
}
