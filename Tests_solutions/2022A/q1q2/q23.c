#include <stdio.h>

int main(){
    char word[100];
    int i = 0;
    int countBig = 0;
    int countSmall = 0;

    printf("Enter a word: ");
    scanf("%99s", word);

    while(word[i] != '\0'){
        char letter = word[i];

        if(letter >= 'a' && 'z'>= letter){
            countSmall++;
        }
        if(letter >= 'A' && 'Z' >= letter){
            countBig++;
        }

        i++;
    }

    printf("Big letters: %d \n", countBig);
    printf("Small letters: %d \n", countSmall);

    return 0;
}