TOP_DIR = ..

# Automatic compiler options
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJDUMP = arm-none-eabi-objdump

INCLUDE_DIR = $(TOP_DIR)/lib/

hello.lst: hello
	$(OBJDUMP) -d $< > $@

# Various settings
CFLAGS = -std=gnu99 -O1 -Wall -Wextra -Werror -nostdlib -g -I $(INCLUDE_DIR)
LDFLAGS = -T ldscript.ld -g -L $(INCLUDE_DIR)

include $(INCLUDE_DIR)rules.mk

# Source files
CFILES = $(wildcard *.c) $(LIB_SRC)
OFILES = crt0.o $(CFILES:.c=.o)

.PHONY: clean

hello: $(OFILES)
	$(LD) $(LDFLAGS) $^ -o $@

clean:
	rm -f $(OFILES) hello.lst hello