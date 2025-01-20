#include <stdio.h>

int pointersCount(int* arr[], int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == NULL){
            count++;
        }
    }
    return count;
}

int main(){
    int a,b,c;
    int *p = NULL;
    int* arr[] = {&a,&b,p,&c};

    int count = pointersCount(arr, 4);

    printf("Number of NULL pointers: %d\n", count);

    return 0;
}