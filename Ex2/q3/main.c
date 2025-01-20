#include <stdio.h>
#define n 2

void transpose(int mat[n][n]) {
    // Perform the transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap mat[i][j] with mat[j][i]
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    // Print the transposed matrix
    printf("The transpose of the matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[n][n]; // an n x n matrix

    // initialize the matrix
    printf("Enter numbers to fill the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // print the matrix
    printf("The matrix you entered is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    transpose(mat);

    return 0;
}