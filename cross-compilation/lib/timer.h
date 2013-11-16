#ifndef TIMER_H
#define TIMER_H

// TCFG0 Configures the three 8-bit prescalers
#define TCFG0 (*(volatile uint32_t *)0x01D50000)

// TCFG1 6-MUX & DMA mode selecton register
#define TCFG1 (*(volatile uint32_t *)0x01D50004)

// TCON Timer control register
#define TCON (*(volatile uint32_t *)0x01D50008)

// TCNTB0 Timer 0 count buffer register
#define TCNTB0 (*(volatile uint32_t *)0x01D5000C)

// TCMPB0 Timer 0 compare buffer register
#define TCMPB0 (*(volatile uint32_t *)0x01D50010)

// TCNTO0 Timer 0 count observation register
#define TCNTO0 (*(volatile uint32_t *)0x01D50014)

// TCNTB0 Timer 3 count buffer register
#define TCNTB3 (*(volatile uint32_t *)0x01D50030)

// TCMPB0 Timer 3 compare buffer register
#define TCMPB3 (*(volatile uint32_t *)0x01D50034)

// TCNTO0 Timer 3 count observation register
#define TCNTO3 (*(volatile uint32_t *)0x01D50038)

void timer_start(int time);
void timer_stop();
void timer_sleep(int time);

void buzzer_start(int periode);
void buzzer_end();
void buzzer(int periode, int time);

#endif

