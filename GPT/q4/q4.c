#include <stdio.h>
#include <string.h>

int main(){
    char src[] = "Hello, World!";
    char dest[100];
    char input[100];
    char copy[100];

    strcpy(dest, src);
    printf("strcpy: %s \n",dest);

    printf("Enter a string: ");
    scanf("%99s", input);

    int comp = strcmp(input, dest);
    if(comp == 0) printf("\nStrings are equal.\n ");
    else printf("Strings are not equal.\n");

    memset(dest, 'X', 5);
    dest[5] = '\0';
    printf("dest: %s\n", dest);

    memcpy(copy, src, 5);
    copy[5] = '\0';
    printf("copy: %s\n", copy);


    return 0;
}