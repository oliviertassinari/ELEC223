#ifndef SERIAL_H
#define SERIAL_H

void serial_init();
void serial_putc(uint8_t c);
uint8_t serial_getc();
void serial_puts(char s);

#endif
