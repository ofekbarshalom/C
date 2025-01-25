.PHONY: clean

CC = gcc
CFLAGS = -c -I Include/ -Wall -Werror
SRC_DIR = src
OBJ_FILES = character.o armor.o shiny.o main.o
TARGET = Project

$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

character.o: $(SRC_DIR)/character.c Include/character.h
	$(CC) $(CFLAGS) $(SRC_DIR)/character.c

armor.o: $(SRC_DIR)/armor.c Include/armor.h
	$(CC) $(CFLAGS) $(SRC_DIR)/armor.c

shiny.o: $(SRC_DIR)/shiny.c Include/shiny.h
	$(CC) $(CFLAGS) $(SRC_DIR)/shiny.c

main.o: $(SRC_DIR)/main.c Include/character.h Include/armor.h Include/shiny.h 
	$(CC) $(CFLAGS) $(SRC_DIR)/main.c

clean:
	rm -f *.o $(TARGET)