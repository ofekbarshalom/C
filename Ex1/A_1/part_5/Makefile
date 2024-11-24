program: main.o libmathlib.a libadvmath.so
	gcc main.o -L. -lmathlib -ladvmath -o program

libmathlib.a: mathlib.o
	ar rcs libmathlib.a mathlib.o

mathlib.o: mathlib.c mathlib.h
	gcc -c mathlib.c

libadvmath.so: advmath.o
	gcc -shared -o libadvmath.so advmath.o

advmath.o: advmath.c advmath.h
	gcc -fPIC -c advmath.c

main.o: main.c mathlib.h advmath.h
	gcc -c main.c

clean:
	rm -f *.o libmathlib.a libadvmath.so program
