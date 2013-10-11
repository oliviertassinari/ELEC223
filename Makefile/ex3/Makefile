%.o: %.c
	gcc -c $< -o $@

main.o: main.c
	gcc -c $< -o $@

main: main.o, a.o, b.o, c.o, b.o, e.o, f.o, g.o, h.o, i.o, j.o, k.o, l.o
	gcc -g $^ -lfl -o $@

clean:
	rm -f main
	rm -f *.o