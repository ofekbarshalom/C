#include <stdio.h>
#define n 2

void transpose(int mat[n][n]){
    // Perform the transpose
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    // print the transposed matrix
    printf("the matrix you entered is:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int mat[n][n]; // a 2D array of n by n
    // init the matrix
    printf("Enter numbers to fill the matrix");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    //print the matrix
    printf("the matrix you entered is:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }

    transpose(mat);

    return 0;
}