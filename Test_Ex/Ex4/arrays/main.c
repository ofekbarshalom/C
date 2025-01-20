#include <stdio.h>

void getNumbers(){
    int num = 0;
    int arr[5] = {0};
    int index = 0;
    while(1){
        printf("Enter a number: ");
        scanf("%d", &num);

        if(num == 99){
            break;
        }
        
        arr[index % 5] = num;
        index++;
    }
    
    printf("The array:\n");

    for(int i = 0; i < 5; i++){
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}

int main(){
    getNumbers();
    return 0;
}