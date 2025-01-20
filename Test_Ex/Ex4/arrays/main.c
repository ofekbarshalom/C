#include <stdio.h>

void getNumbers(){
    int num = 0;
    int arr[5] = {0};
    int index = 0;
    while(num != 99){
        printf("Enter a number: ");
        scanf("%d", num);

        arr[index %5 ] = num;
    }
    
    printf("The array:\n");

    for(int i = 0; i < 5; i++){
        printf("arr[%d] = %d",i,arr[i]);
    }
}

int main(){
    getNumbers();
    return 0;
}