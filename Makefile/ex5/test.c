#include <avr/io.h>
#include <avr/boot.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "config.h"
#include "uart.h"

#define noinline __attribute__((noinline))

/* pin connected to LED */
#define LED_RED PD7
#define LED_BLUE PB0

#define TRI_LED_BLUE PB3
#define TRI_LED_RED PB4
#define TRI_LED_GREEN PB5

/* pin connected to the interruptor */
#define INTERRUPTOR0 PD2


/** block until one character has been read */
static noinline uint8_t uart_getc(void)
{

	/* wait if a byte has been received */
	while (!(_UCSRA_UART0 & _BV(_RXC_UART0)));

	/* return received byte */
	return _UDR_UART0;

}

/** output one character */
static noinline void uart_putc(uint8_t data)
{

	/* loop until data has been transmitted */
	while (!(_UCSRA_UART0 & _BV(_UDRE_UART0)));

	/* put data in buffer */
	_UDR_UART0 = data;

}

/** init the hardware uart */
static inline void init_uart(void)
{

	/* set baud rate */
	_UBRRH_UART0 = (uint8_t)(UART_UBRR >> 8);  /* high byte */
	_UBRRL_UART0 = (uint8_t)UART_UBRR;         /* low byte */

	/* set mode */
	_UCSRC_UART0 = UART_UCSRC;

	/* enable transmitter, receiver */
	_UCSRB_UART0 = _BV(_TXEN_UART0) | _BV(_RXEN_UART0);

}

/** init the hardware for the leds */
static inline void init_led(void)
{
    
	/* set pin as output */
	DDRD|=(1<<LED_RED);
	DDRB|=(1<<LED_BLUE);
	DDRB|=(1<<TRI_LED_BLUE);
	DDRB|=(1<<TRI_LED_RED);
	DDRB|=(1<<TRI_LED_GREEN);

	/* at init time, led is on */
	//PORTD|=(1<<LED_RED);
	//PORTB|=(1<<LED_BLUE);
        PORTB|=(1<<TRI_LED_BLUE);
        PORTB|=(1<<TRI_LED_BLUE);
        PORTB|=(1<<TRI_LED_BLUE);
}

/** init the hardware for the interrupteur */
static inline void init_interruptor(void)
{
	/* set pin as input */
	DDRD&=~(1<<INTERRUPTOR0);

	/* activate the pull-up */
	PORTD |=(1<<INTERRUPTOR0);
}

static inline void toggle_led_blue(void)
{
	PORTB^=(1<<LED_BLUE);
}

static inline void toggle_led_red(void)
{
	PORTD^=(1<<LED_RED); 
}


void send_string(char * line)
{
	while(*line !=0)
	{
		if (*line=='\n')
			uart_putc('\r');
		uart_putc(*line++);
	}
}

int main(void)
{
	int interrupteur, i;

	init_led();
	// Pas besoin d'initialiser l'UART, le bootloader s'en est déjà chargé.
	// Si on le refait, ça parasite le "a" qui est en train d'être envoyé.
	// De plus, après un setup d'UART, il faut attendre un peu...
	init_uart();
	init_interruptor();

	send_string("Hello World !\n");

	/* main loop */
	while (1)
	{
		// on attend 100 ms avant de relire la valeur
		_delay_ms(100);
        
		interrupteur = !(PIND&(1<<INTERRUPTOR0));
		if (interrupteur) {
			send_string("Interrupteur !\n");
			toggle_led_blue();
		}
		interrupteur = 0;

	}
}
