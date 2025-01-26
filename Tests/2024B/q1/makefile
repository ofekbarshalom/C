.PHONY: all clean

CC = gcc
TARGET = Project
CFALGS = -c -Wall -Werror
OBJ = q1.o
C_FILE = q1.c

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(C_FILE)

$(OBJ): $(C_FILE)
	$(CC) $(CFALGS) -o $@ $<

clean:
	rm -f *.o $(TARGET)