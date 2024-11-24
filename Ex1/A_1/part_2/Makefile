.PHONY: clean

Project: character.o armor.o shiny.o main.o
	gcc character.o armor.o shiny.o main.o -o Project

character.o: src/character.c Include/character.h
	gcc -c -I Include/ src/character.c

armor.o: src/armor.c Include/armor.h
	gcc -c -I Include/ src/armor.c

shiny.o: src/shiny.c Include/shiny.h
	gcc -c -I Include/ src/shiny.c

main.o: src/main.c Include/character.h Include/armor.h Include/shiny.h
	gcc -c -I Include/ src/main.c

clean:
	rm -f *.o Project