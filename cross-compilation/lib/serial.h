#ifndef SERIAL_H
#define SERIAL_H

void serial_init();
void serial_putc(char c);
void serial_puts(const char* s);
void serail_puti32(uint32_t i);
char serial_getc();
int serial_getc_timeout(char * c, int time);

#endif
