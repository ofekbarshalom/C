#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void func(int a, int b){
    int count = 0;
    int temp = b;

    while(temp > 0){
        count++;
        temp /= 10;
    }

    int result = b / pow(10,count - a);

    printf("result: %d", result);
}

int func2(char* string, char ch){
    int lestPlace = -1;
    int len = strlen(string);
    
    for(int i = 0; i < len; i++){
        if(string[i] == ch){
            if(lestPlace < i) lestPlace = i;
        }
    }

    return lestPlace;
}

char** func3(char* word){
    int len = strlen(word);
    int spaceCount = 0;

    for(int i = 0; i< len; i++){
        if(word[i] == ' ') spaceCount++;
    }

    char** wordArr = (char**)malloc((spaceCount+1) * sizeof(char*));

    int start, arrIndex = 0;

    for(int i = 0; i <= len; i++){
        if (word[i] == ' ' || word[i] == '\0') {
            int subLen = i - start; // Calculate substring length
            wordArr[arrIndex] = (char*)malloc((subLen + 1) * sizeof(char)); // Allocate memory for substring
            strncpy(wordArr[arrIndex], &word[start], subLen); // Copy substring
            wordArr[arrIndex][subLen] = '\0'; // Null-terminate the substring
            arrIndex++;
            start = i + 1; // Update start to the next word
        }
    }
    
    return wordArr;
}

int main(){
    // int a = 3;
    // int b = 65283;

    // func(a, b);
    
    // int result = func2("oeffffek", 'e');
    // printf("place: %d", result);



    return 0;
}