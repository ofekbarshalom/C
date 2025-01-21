#include <stdio.h>
#include <string.h>

int contains(char* s1, char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int count = 0;

    if(len1 > len2){
        return 0;
    }

    for(int i = 0; i <= len2 - len1; i++){
        char substring[len1 + 1];
        strncpy(substring, &s2[i], len1);
        substring[len1] = '\0';

        if(strcmp(substring, s1) == 0){
            count++;
        }
    }

    return count;
}



int main(){
    char* s2 = "kaba 2 abababaBA$";
    char* s1 = "aba";

    int contain = contains(s1, s2);
    printf("contains: %d", contain);

    return 0;
}