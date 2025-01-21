#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool endsWith(char* s1, char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // If s2 is longer than s1, it can't be a suffix
    if (len2 > len1) {
        return false;
    }

    // Compare the last len2 characters of s1 with s2
    int i = len1 - len2; // Start position in s1
    int j = 0;   


    while(s2[j]){
        if(s1[i] != s2[j]){
            return false;
        }
        i++;
        j++;
    }
    return true;

}


int main(){
    char* s1 = "ofek";
    char* s2 = "ek";

    bool check = endsWith(s1, s2);
    printf("%d\n", check);


    return 0;
}