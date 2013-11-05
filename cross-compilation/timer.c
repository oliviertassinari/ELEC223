#include <stdint.h>
#include "timer.h"

// TCON Timer control register
#define TCON (*(volatile uint32_t *)0x01D50008)

// TCNTB0 Timer 0 count buffer register
#define TCNTB0 (*(volatile uint32_t *)0x01D5000C)

void timer_init()
{
	
}

void timer_sleep_1s()
{

}