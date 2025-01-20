#include <stdio.h>
#include <math.h>

int power(int exp, int base){
    int result = 1;

    for(int i = 0; i < exp; i++) {
        if(result >= pow(10, 15)) {
            break;
        }
        result *= base;
    }
    return result;
}

int main(){
    int exp, base;

    printf("Enter the exponent and the base:");
    if (scanf("%d%d", &exp, &base) != 2){
        printf("Error!");
        return 1;
    }
    int result = power(exp, base);

    printf("result: %d", result);

    return 0;
}