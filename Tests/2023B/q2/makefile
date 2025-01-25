.PHONY: all clean

CC = gcc
TARGET = Project
CFALGS = -c -Wall -Werror
OBJ = q2.o
C_FILE = q2.c
LDFLAGS = -lm

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(C_FILE) $(LDFLAGS)

$(OBJ): $(C_FILE)
	$(CC) $(CFALGS) -o $@ $<

clean:
	rm -f *.o $(TARGET)