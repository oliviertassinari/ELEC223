SRCFILES := $(wildcard *.c)

hello.lst: $(CFILES:.c=.o)
	arm-none-eabi-gcc -Wl,-c ldscript $^ -o $@

%.o : %.c
	arm-none-eabi-gcc -std=gnu99 -O2 -c $< -o $@

clean:
	rm hello.lst
	rm -f *.o