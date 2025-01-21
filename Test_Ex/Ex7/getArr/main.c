#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int sum = 0;

    printf("Enter a limit: ");
    scanf("%d", &n);

    int* arr = malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed. \n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("Enter a number:");
        scanf("%d", &arr[i]);

        sum += arr[i];
    }

    for(int i = 0; i < n; i++){
        printf("%d , ", arr[i]);
    }
    printf("\n");
    printf("sum: %d", sum);

    free(arr);

    return 0;
}