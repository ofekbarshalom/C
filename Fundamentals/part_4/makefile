.PHONY: clean all

CC = gcc
TARGET = program
OBJ = main.o libadvmath.so
CFLAGS = -c -Wall -Werror

all : $(TARGET)

$(TARGET): $(OBJ)
	$(CC) main.o -L. -ladvmath -o $@

libadvmath.so: advmath.o
	$(CC) -shared -o $@ $<

advmath.o: advmath.c advmath.h
	$(CC) -fPIC $(CFLAGS) -o $@ $<

main.o: main.c advmath.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o libadvmath.so $(TARGET)