#include <stdio.h>

char* strcat(char* dest, char* src){
    int i = 0;
    int j = 0;

    while(dest[i]){
        i++;
    }

    while(src[j]) {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';

    return dest;
}

int main(){
    char dest[100] = "ofek";
    char src[] = "roy";

    char* s = strcat(dest, src);
    printf("%s\n", s);

    return 0;
}