#include <stdio.h>

int main(){
    unsigned int num;
    unsigned int pos;

    printf("Enter a number: ");
    scanf("%u", &num);
    printf("\n");

    printf("Enter a position: ");
    scanf("%u", &pos);
    printf("\n");

    num = num | (1 << pos);
    printf("num: %u\n", num);

    num = num & ~(1 << pos);
    printf("num: %u\n", num);

    num = num ^ (1 << pos);
    printf("num: %u\n", num);

    if ((num & (1 << pos)) != 0) printf("bit is 1\n");
    else printf("bit is 0\n");

    return 0;
}