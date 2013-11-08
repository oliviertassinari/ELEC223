
# Automatic compiler options
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJDUMP = arm-none-eabi-objdump

# Various settings
CFLAGS = -std=gnu99 -O1 -Wall -Wextra -Werror -nostdlib -g
LDFLAGS = -T ldscript.ld -g

# Source files
CFILES = $(wildcard *.c)
OFILES = crt0.o $(CFILES:.c=.o)

.PHONY: clean

hello.lst: hello
	$(OBJDUMP) -d $< > $@

hello: $(OFILES)
	$(LD) $(LDFLAGS) $^ -o $@

serial.o: serial.h
led.o: led.h port.h
timer.o: timer.h port.h


clean:
	rm -f *.o hello.lst hello