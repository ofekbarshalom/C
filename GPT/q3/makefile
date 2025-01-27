.PHONY: all clean

CC = gcc
CFLAGS = -c -Wall -Werror
TARGET = Project
OBJ = q3.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean: 
	rm -f *.o $(TARGET)