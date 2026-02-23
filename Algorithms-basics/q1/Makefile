all: main

main: main.o
	gcc -Wall -o  main main.o

main.o: main.c
	gcc -Wall  -c main.c -o main.o

clean:
	rm -f main.o main.exe