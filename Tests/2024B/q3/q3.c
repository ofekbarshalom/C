#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(char* words[], char* filename){
    FILE* file = fopen(filename, "w");

    int size = 0;
    int i = 0;

    while(words[i++] != NULL) size++;

    for(int i = 0; i < size; i++){
        fprintf(file," %d %s\n",strlen(words[i]), words[i]);
    }
    fclose(file);
}

char** read(char* filename){
    FILE* file = fopen(filename, "rb");
    if(file == NULL) return NULL;

    char** words = (char*)malloc(100* sizeof(char*));
    if(words == NULL) {
        fclose(file);
        return NULL;
    }

    int i = 0;

    while(!feof(file)){
         int length;
        // Read the length of the word
        if (fread(&length, sizeof(int), 1, file) != 1) {
            break; // End of file or read error
        }

        // Allocate memory for the word
        words[i] = (char*)malloc((length + 1) * sizeof(char)); // +1 for the null terminator
        if (words[i] == NULL) {
            printf("Error: Memory allocation failed.\n");
            fclose(file);
            return NULL;
        }

        // Read the word itself
        fread(words[i], sizeof(char), length, file);

        // Null-terminate the string
        words[i][length] = '\0';

        i++;

    }
    words[i] = NULL;
    fclose(file);
    return words;
}