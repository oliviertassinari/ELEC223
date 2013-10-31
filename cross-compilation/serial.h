#ifndef SERIAL_H
#define SERIAL_H

void serial_init();
void serial_putc(char c);
char serial_getc();
void serial_puts(const char* s);

#endif
