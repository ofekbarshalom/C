.PHONY: all clean

CC = gcc
CFLAGS = -c -Wall -Werror
TARGET = Project
OBJ = q2.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean: 
	rm -f *.o $(TARGET)