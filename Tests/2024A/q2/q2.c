#include <stdio.h>
#include <string.h>

void countarg(int argc, char* argv[]){
    if(argc == 1){
        printf("Error: no words given");
        return;
    }

    char* word = argv[1];
    int count = 1;

    for(int i = 2; i < argc; i++){
        if(strcmp(word, argv[i]) == 0) count++;
    }

    printf("%s appears %d times", word, count);
}

int main(int argc, char* argv[]){
    countarg(argc, argv);
    return 0;
}