#include <stdio.h>
#define N 3

int maxCol(int arr[][]){
    int maxCountInRow = 0
    for(int i = 0; i < N; i++){
        int maxCountInCol = 0;
        for(int j = 0; j < N - 1; j++){
            int count = 0
            if(arr[j][i] < arr[j+1][i]){
                count++;
            }
            else{
                count = 0;
            }
            if (count > maxCountInRow){
                maxCountInRow = count;
            }
        }
        if (maxCountInRow < maxCountInCol){
            maxCountInRow = maxCountInRow;
        }
    }
    return maxCountInRow;
}

int main(){
    int arr[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("Enter [%d][%d]", i, j);
            scanf("%d", arr[i][j]);
        }
    }

    int max = maxCol(arr);
    return 0;
}