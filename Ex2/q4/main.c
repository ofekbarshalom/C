#include <stdio.h>

void magicMatrixCheck(int n, int mat[n][n]){
    int sum = 0;
    int i, j; 

    // Calculate the sum of the first row as reference
    for(j = 0; j < n; j++){
        sum += mat[0][j];
    }

    // Check sums of all rows
    for(int i = 1; i < n; i++){
        int rowSum = 0;
        for(int j = 0; j < n; j++){
            rowSum += mat[i][j];
        }
        if(rowSum != sum){
            printf("The given Matrix is not a magic.\n");
            return;
        }
    }

    // Check sums of all columns
    for(int j = 0; j < n; j++){
        int colSum = 0;
        for(int i = 0; i < n; i++){
            colSum += mat[i][j];
        }
        if(colSum != sum){
            printf("The given Matrix is not a magic.\n");
            return;
        }
    }

    // Check sum of the main diagonal
    int diagSum1 = 0;
    for(i = 0; i < n; i++) {
        diagSum1 += mat[i][i];
    }
    if(diagSum1 != sum) {
        printf("The given Matrix is NOT a magic square.\n");
        return;
    }

    // Check sum of the secondary diagonal
    int diagSum2 = 0;
    for(i = 0; i < n; i++) {
        diagSum2 += mat[i][n - 1 - i];
    }
    if(diagSum2 != sum) {
        printf("The given Matrix is NOT a magic square.\n");
        return;
    }

    // If all checks pass
    printf("The given Matrix is a magic Matrix with sum of %d", sum);
}

int main(){
    int n;

    printf("Enter the size of the matrix: \n");
    scanf("%d", &n);

    int mat[n][n];

    // Input the matrix elements
    printf("Enter the matrix numbers: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }

    // Print the matrix
    printf("the matrix is: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }

    magicMatrixCheck(n,mat);

    return 0;
}