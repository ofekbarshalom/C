#include <stdio.h>

int applyArray(int (*ptrFunc)(int), int arr[]){
    int sum = 0;

    for(int i = 0; i < 4; i++){
        sum += ptrFunc(arr[i]);
    }
    return sum;
}

int f1(int a){
    return a+1;
}

int main(){
    int arr[4]={6,4,3,0};

    int (*ptrFunc)(int) = &f1;

    int result = applyArray(ptrFunc, arr);
    printf("%d\n", result);

    return 0;
}