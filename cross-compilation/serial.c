#define UTRSTAT0 (*(volatile uint8_t *)0x01D0010)
#define UTXH0 (*(volatile uint8_t *)0x01D0020)
#define URXH0 (*(volatile uint8_t *)0x01D024)
#define ULCON0 (*(volatile uint8_t *)0x01D0000)
#define UCON0 (*(volatile uint16_t *)0x01D0004)
#define UBRDIV0 (*(volatile uint16_t *)0x01D0028)

void serial_init()
{
  ULCON0 = 0x3;
  UCON0 = 0x5;
  UBRDIV0 = (uint16_t)(33000000 / (115200 x 16)+0.5) - 1;
}

void serial_putc(uint8_t c)
{
	while(UTRSTAT0 & (1 << 1) == 0){}

	UTXH0 = c;
}

uint8_t serial_getc()
{

}

void serial_puts(char s)
{
}
