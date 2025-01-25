.PHONY: all clean

CC = gcc
TARGET = Project
OBJ = main.o student_list.o
CFLAGS = -c -Wall -Werror -I.

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)

main.o: main.c student_list.h
	$(CC) $(CFLAGS) main.c 

student_list.o: student_list.c student_list.h
	$(CC) $(CFLAGS) student_list.c

clean:
	rm -f *.o $(TARGET)