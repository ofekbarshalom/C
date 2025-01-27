#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);
    if(n <= 0) return 1;

    int *arr = (int*)malloc(n* sizeof(int));
    if(arr == NULL) return 1;

    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
    }

    int* temp = realloc(arr, n *  2 * sizeof(int));
    if(temp == NULL){
        free(arr);
        return 1;
    } 
    arr = temp;

    for(int i = n; i < n * 2; i++){
        arr[i] = i + 1;
    }

    printf("\n");
    for(int i = 0; i < n * 2; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    int* cleanArr = (int*)calloc(n * 2, sizeof(int));
    if(cleanArr == NULL) {
        free(arr);
        return 1;
    }

    for(int i = 0; i < n * 2; i++){
        printf("%d ",cleanArr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;

    free(cleanArr);
    cleanArr = NULL;

    return 0;
}