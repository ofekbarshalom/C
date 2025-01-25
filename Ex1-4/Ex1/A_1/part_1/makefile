program: main.o other.o
	gcc -o program main.o other.o

main.o: main.c other.h
	gcc -c main.c

other.o: other.c other.h
	gcc -c other.c

.PHONY: clean

clean:
	rm -f *.o program