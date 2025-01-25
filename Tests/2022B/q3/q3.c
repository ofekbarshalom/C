#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int max_new_increase_substr(char* string){
    int max = 0;
    for(int i = 1; i <strlen(string); i++){
        int count = 0;
        bool newLetter = false;
        bool biggerLetter = false;
        for(int j = i - 1; j >= 0; j--){
            if(string[i] == string[j]) newLetter = true;
            if(string[i] < string[j]) biggerLetter = true;
            if(newLetter && biggerLetter) break;
            count++;
        }
        if(count > max) max = count;
    }
    return max;
}

int main(){
    int size = 10;

    char* word = (char*)malloc(sizeof(char) * (size+1));
    if(word == NULL) return 1;
    
    char ch;
    int i = 0;

    while(ch != '\0'){
        if(i >= size - 1){
            size = size*2;
            char* temp = realloc(word,size);
            if(temp == NULL){
                free(word);
                return 1;
            }
            word = temp;
        }
        scanf("%c", &ch);
        word[i++] = ch;
    }
        int maxInword = max_new_increase_substr(word);
    printf("Max in word: %d", maxInword);

    free(word);

    return 0;
}