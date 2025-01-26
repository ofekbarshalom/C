#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString(char *src, char *dst, int len){
    for (int i = 0; i < len; i++) {
        dst[i] = src[i];
    }
}

int main(){
    char *hello = "Hello";
    char *names[] = {"Yehonatan", "Libi"};
    char name[10] = {0}; // initializes all chars in name to \0

    copyString(names[0], name, strlen(names[0]));
    printf("%d: %s %s\n", 0, hello, name);
    
    copyString(names[1], name, strlen(names[1]));
    printf("%d: %s %s\n", 1, hello, name);

    return EXIT_SUCCESS;
}