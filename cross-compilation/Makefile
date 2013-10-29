SRCFILES := $(wildcard *.c)

.PHONY: clean

hello.lst: $(CFILES:.c=.o)
	arm-none-eabi-gcc -Wl,-c ldscript $^ -o $@

%.o : %.c %.h
	arm-none-eabi-gcc -std=gnu99 -O2 -c $< -o $@

clean:
	@rm -f hello.lst
	@rm -f *.o