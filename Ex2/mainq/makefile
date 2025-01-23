.PHONY: all clean

CC = gcc
TARGET = program
CFLAGS = -c -Wall -Werror
SRC = main.c
OBJ = $(SRC: .c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $<

$(OBJ): main.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o $(TARGET)
