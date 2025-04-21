#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void func(void* element){
//     return;
// }

// void modifyArrayGeneric(void* arr, int size, int sizeofvar, void(*func)(void*)){
//     for(int i = 0; i < size; i++){
//         func((char*)arr + (sizeofvar * i));
//     }
// }

// void swapBytes(void* var1, void* var2, size_t size){
//     unsigned char temp;
//     unsigned char* byte1 = (unsigned char*)var1;
//     unsigned char* byte2 = (unsigned char*)var2;

//     for(int i = 0; i < size; i++){
//         temp = byte1[i];
//         byte1[i] = byte2[i];
//         byte2[i] = temp;
//     }
// }

void printStudents(int size){
    if(size <= 0) return;

    char* words[size];
    for(int i = 0; i < size; i++){
        words[i] = (char*)malloc(100 * sizeof(char));
        if(words[i] == NULL) return;
    }


    for(int i = 0; i < size; i++){
        printf("Enter name: \n");
        scanf("%99s", words[i]);
    }
    printf("\n");

    for(int i = size -1; i >= 0; i--){
        int sizeOfWord = strlen(words[i]);
        for(int j = sizeOfWord - 1; j >= 0; j--){
            printf("%c", words[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < size; i++){
        free(words[i]);
    }
}

int main(){
    printStudents(3);
    return 0;
}