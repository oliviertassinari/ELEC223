#ifndef _UART_H
#define _UART_H

/* define uart baud rate and mode (8N1) */

/* in atmega8, we need a special switching bit
 * for addressing UCSRC but in atmega88, 
 * this isn't needed any more */
#define UART_UCSRC (_BV(_UCSZ0_UART0) | _BV(_UCSZ1_UART0))

/* define UBRR value (see datasheet */
#define UART_UBRR 10 /* 20mhz, 115200 */

#endif /* _UART_H */
