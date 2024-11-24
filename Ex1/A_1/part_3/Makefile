program: main.o libmathlib.a
	gcc main.o -L. -lmathlib -o program

libmathlib.a: mathlib.o
	ar rcs libmathlib.a mathlib.o

mathlib.o: mathlib.c mathlib.h
	gcc -c mathlib.c

main.o: main.c mathlib.h
	gcc -c main.c

clean:
	rm -f *.o libmathlib.a program
