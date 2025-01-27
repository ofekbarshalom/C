#include <stdio.h>

void createFile(char* filename){
    FILE* file = fopen(filename, "w");
    if(file == NULL) return;

    fputs("This is a test\n" , file);
    fputs("Let's count characters and read it.\n", file);

    fclose(file);
}

void readFile(char* filename){
    int count = 0;
    char line[1024];
    char ch = 0;

    FILE* file = fopen(filename, "r");
    if(file == NULL) return;

    while(fgets(line, sizeof(line), file)){
        printf("%s\n", line);
    }

    fseek(file, 0, SEEK_SET);

    while(fgetc(file) != EOF){
        if(ch != '\n') count++;
    }

    printf("count: %d\n", count);

    fclose(file);
}

int main(){
    char* filename = "output.txt";
    createFile(filename);
    readFile(filename);

    return 0;
}