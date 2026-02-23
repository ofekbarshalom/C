#include <stdio.h>
#include <string.h>
#define N 100

void pailindromeCheck(const char *word){
    int length = strlen(word);
    for(int i = 0; i < length /2; i++){
        if(word[i] != word[length - i - 1]){
            printf("\"%s\" is not a palindrom.\n", word);
            return; // Exit as soon as a mismatch is found
        }
    }
    // If we reach here, no mismatches were found
    printf("\"%s\" is a palindrom.\n", word);
}

int main(){
    char word[N];
    printf("Enter a word: ");
    scanf("%99s", word); // reads a single word, up to 99 chars + '\0'
    pailindromeCheck(word);
    return 0;
}