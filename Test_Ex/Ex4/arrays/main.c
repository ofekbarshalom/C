#include <stdio.h>

void getNumbers(){
    int num = 0;
    int arr[5];
    int index = 0;
    while(num != 99){
        printf("Enter a number: ");
        scanf("%d", num);

        arr[index %5 ] = num;
    }
}

int main(){
    return 0;
}