.PHONY: clean all

CC = gcc
TARGET = program
CFLAGS = -c -Wall -Werror
OBJ = main.o libmathlib.a libadvmath.so

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) main.o -L. -lmathlib -ladvmath -o $@

libmathlib.a: mathlib.o
	ar rcs $@ $<

mathlib.o: mathlib.c mathlib.h
	$(CC) $(CFLAGS) -o $@ $<

libadvmath.so: advmath.o 
	$(CC) -shared -o $@ $<

advmath.o: advmath.c advmath.h
	$(CC) -fPIC $(CFLAGS) -o $@ $<

main.o: main.c mathlib.h advmath.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o libmathlib.a libadvmath.so $(TARGET)

