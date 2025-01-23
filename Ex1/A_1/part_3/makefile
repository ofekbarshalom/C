.PHONY: clean all

CC = gcc
TARGET = program
OBJ = main.o libmathlib.a
AR = ar
ARFLAGS = rcs
CFLAGS = -c -Wall -Werror 

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc main.o -L. -lmathlib -o $@

libmathlib.a: mathlib.o
	$(AR) $(ARFLAGS) $@ $<

mathlib.o: mathlib.c mathlib.h
	$(CC) $(CFLAGS) -o $@ $<

main.o: main.c mathlib.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o libmathlib.a $(TARGET)