#include <stdio.h>
#include <stdlib.h>

union Data{
    int numbers[6];
    char text[21];

};

int main(){
    union Data data;

    for(int i = 0; i < 6; i++){
        data.numbers[i] = i + 1;
    }

    printf("Integer array: \n");
    for(int i = 0; i < 6; i++){
        printf("%d ", data.numbers[i]);
    }
    printf("\n");

    char sampleText[21] = "hello world ofek";
    for(int i = 0; i < 21; i++){
        data.text[i] = sampleText[i];
    }
    
    printf("Character array:\n");
    printf("%s\n", data.text);

    printf("After initializing text, the integers are:\n");
    for(int i = 0; i < 6; i++){
        printf("%d ", data.numbers[i]);
    }
    printf("\n");

    return 0;
}
