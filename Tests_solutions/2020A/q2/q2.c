#include <stdio.h>

#define COLS 5
#define ROWS 3

int Get_1D_Array (int arr[][COLS], int n){
    int count = 0;
    while(n >= COLS){
            count++;
            n %= COLS;
    }
    return arr[count][n];
}

int main () {
    int arr[ROWS][COLS] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    printf ("%d\n", Get_1D_Array(arr,5));

    return 0;
}