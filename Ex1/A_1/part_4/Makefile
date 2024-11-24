program: main.o libadvmath.so
	gcc main.o -L. -ladvmath -o program

libadvmath.so: advmath.o
	gcc -shared -o libadvmath.so advmath.o

advmath.o: advmath.c advmath.h
	gcc -fPIC -c advmath.c

main.o: main.c advmath.h
	gcc -c main.c

clean:
	rm -f *.o libadvmath.so program
