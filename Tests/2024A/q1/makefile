.PHONY: all clean

CC = gcc
TARGET = myprogram
CFLAGS = -c -Wall -Werror
OBJ = source1.o source2.o source3.o

all : $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)

source1.o: source1.c source1.h
	$(CC) $(CFALGS) -o $@ $<

source2.o: source2.c source2.h
	$(CC) $(CFALGS) -o $@ $<

source3.o: source3.c source3.h
	$(CC) $(CFALGS) -o $@ $<

clean:
	rm -f *.o $(TARGET)