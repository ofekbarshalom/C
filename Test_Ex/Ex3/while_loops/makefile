CC = gcc
CFLAGS = -Wall -I.

SRC = loops.c
OBJ = loops.o

TARGET = loops

all: $(TARGET)

$(TARGET) : $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean