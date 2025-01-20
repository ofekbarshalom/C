#include <stdio.h>
#define N 5

int maxCol(int arr[][N]) {
    int maxCountInCol = 0;  // Stores the overall maximum count across columns

    for (int i = 0; i < N; i++) {  // Iterate through columns
        int count = 0;  // Reset count for each column
        for (int j = 0; j < N - 1; j++) {
            if (arr[j][i] < arr[j + 1][i]) {
                count++;
                if (count > maxCountInCol) {
                    maxCountInCol = count;  // Update maximum count if necessary
                }
            } else {
                count = 0;  // Reset count if sequence breaks
            }
        }
    }

    return maxCountInCol + 1;  // Add 1 to include the first element in the sequence
}

int main(){
    int arr[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int max = maxCol(arr);
    printf("max: %d", max);
    return 0;
}