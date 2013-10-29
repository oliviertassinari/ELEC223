SRCFILES := $(wildcard *.c)

.PHONY: clean

hello.lst: $(SRCFILES:.c=.o) ldscript.ld
	arm-none-eabi-gcc -Wl,-T ldscript.ld -O2 $^ -o $@

%.o : %.c
	arm-none-eabi-gcc -std=gnu99 -O2 -c $< -o $@

clean:
	@rm -f hello.lst
	@rm -f *.o