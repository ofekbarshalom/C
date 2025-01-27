#include <stdio.h>

void func(char* filename){
    int num1 = 25;
    int num2 = 50;
    int num3 = 75;
    FILE* file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening the file!");
        return;
    }

    fprintf(file,"%d\n", num1);
    fprintf(file, "%d\n", num2);
    fprintf(file, "%d\n", num3);

    fclose(file);
}

void func2(char* filename){
    int num1, num2, num3;

    FILE* file = fopen(filename, "r+");
    if(file == NULL){
        printf("Error opening the file!");
        return;
    }

    fscanf(file, "%d", &num1);
    fscanf(file, "%d", &num2);
    fscanf(file, "%d", &num3);

    int sum = num1 + num2 + num3;

    fprintf(file, "\nSum: %d\n", sum);

    fclose(file);
}

int main(){
    char* filename = "ofek.txt";

    func(filename);
    func2(filename);

    return 0;
}