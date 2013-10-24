#include <stdint.h>
#include <stdio.h>

int32_t x = 34;
int32_t xx = 35;
int32_t xxx = 36;
int32_t xxxx = 37;
int32_t y;
int64_t a;
int16_t b;
int8_t c;
__int128_t cc = 1;

typedef struct dada1
{
    int64_t d1;
    int64_t d2;
}dada1;

typedef struct dada2
{
    int64_t d1;
    int64_t d2;
   	int8_t c;
}dada2;

struct dada1 DaVinciCode1;
struct dada2 DaVinciCode2;

const char mesg[] = "Hello World!\n";

int main()
{
	static uint8_t z;
	static uint32_t zz;
	static uint32_t zzz;
	uint16_t t;

	a = 1;
	b = 2;
	c = 3;

	y = 12;
	z = z + 1;
	t = y+z;
	printf(mesg);
	printf("x = %d, y = %d, z = %d, t = %d\n",
	       x, y, z, t);
	return 0;
}