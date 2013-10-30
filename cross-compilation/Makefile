CC = arm-none-eabi-gcc
CFLAGS = -std=gnu99 -O1 -Wall -Wextra -Werror -nostdlib
LDFLAGS = -Wl,-T ldscript.ld
SRCFILES = $(wildcard *.c)

.PHONY: clean

hello.lst: $(SRCFILES:.c=.o)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

serial.o: serial.h

clean:
	rm -f *.o hello.lst