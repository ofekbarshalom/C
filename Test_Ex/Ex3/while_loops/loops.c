#include <stdio.h>
#include "loops.h"

int main(){
    int num;
    printf("Enter a number:");
    scanf("%d", &num);
    
    int count = countLoops(num);

    printf("Division by 2 happened %d times", count);
}

int countLoops(int num){
    int count = 0;

    while(num >= 1){
        num = num / 2;
        count ++;
    }

    return count;
}