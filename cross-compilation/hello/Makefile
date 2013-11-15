TOP_DIR = ..

# Automatic compiler options
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJDUMP = arm-none-eabi-objdump

all: hello
	$(OBJDUMP) -d $< > $@

# Various settings
CFLAGS = -std=gnu99 -O1 -Wall -Wextra -Werror -nostdlib -g -I $(TOP_DIR)/lib/
LDFLAGS = -T ldscript.ld -g -L $(TOP_DIR)/lib/

include $(TOP_DIR)/lib/rules.mk

# Source files
CFILES = $(wildcard *.c) $(LIB_SRC)
OFILES = crt0.o $(CFILES:.c=.o)

.PHONY: clean



hello: $(OFILES)
	$(LD) $(LDFLAGS) $^ -o $@




clean:
	rm -f $(OFILES) hello.lst hello