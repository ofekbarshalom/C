#include <stdio.h>
#include <stdlib.h>

int fileComperator(FILE* file1, FILE* file2){

    file1 = fopen("file1.txt","r");
    file2 = fopen("file2.txt","r");

    if(file1 == NULL || file2 == NULL){
        printf("File could not be opened\n");
        return -1;
    }

    while(feof(file1) == EOF){
        char file1_char, file2_char;
        fread(&file1_char, sizeof(char), 1, file1);
        fread(&file2_char, sizeof(char), 1, file2);

        if(file1_char != file1_char){
            return 0;
        }
    }
    return 1;
}

int main(){
    FILE *file1, *file2;

    int result = fileComperator(file1, file2);
    printf("result: %d", result);
    return 0;
}