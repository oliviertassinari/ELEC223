#ifndef SERIAL_H
#define SERIAL_H

void serial_init();
void serial_putc(char c);
char serial_getc();
char serial_getc_timeout(int time);
void serial_puts(const char* s);

#endif
