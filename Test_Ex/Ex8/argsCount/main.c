#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc == 2){
        printf("The word appears ones.");
        return 0;
    }

        if(argc == 1){
        printf("No words received");
        return 0;
    }

    char* word = argv[1];
    int count = 1;
    for(int i = 2; i < argc; i++){
        if(strcmp(argv[i], word) == 0){
            count++;
        }
    }

    printf("%s appears %d times",word,count);
    
    return 0;
}