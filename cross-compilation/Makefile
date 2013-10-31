CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJDUMP = arm-none-eabi-objdump

CFLAGS = -std=gnu99 -O1 -Wall -Wextra -Werror -nostdlib
LDFLAGS = -T ldscript.ld
CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o) crt0.o

.PHONY: clean

hello.lst: hello
	$(OBJDUMP) -d $< >> $@

hello: $(OFILES)
	$(LD) $(LDFLAGS) $^ -o $@

serial.o: serial.h

clean:
	rm -f *.o hello.lst hello