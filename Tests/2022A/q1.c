#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString(){
    int size = 10;
    char* word = malloc(size);

    if(word == NULL){
        printf("Memory allocation failed!\n");
        return NULL;
    }

    int i = 0;
    char ch;

    printf("Enter a word: ");
    while(1){
        scanf("%c", &ch);

        if (ch == '\n') break;

        if(i >= size - 1){
            size *= 2;
            char* temp = realloc(word, size * sizeof(char));

            if(temp == NULL){
                printf("Memory allocation failed!\n");
                return NULL;
            }
            word = temp;

        }

        word[i++] = ch;      
    }

    word[i] = '\0';

    return word;
}

int main(){
    char* word = getString();
    if(word != NULL){
        printf("you entered: %s \n", word);
        free(word);
    }
    return 0;
}