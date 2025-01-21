#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(){
    char* word = malloc(100 * sizeof(char));
    if(word == NULL){
        printf("Memory allocation failed. \n");
        return 1;
    }

    printf("Enter the word: ");
    scanf("");
    fgets(word, 100, stdin);

    printf("You entered: %s\n", word);

    free(word);
    return 0;
}