#include <stdio.h>
#include <stdlib.h>

// Matrix structure definition
typedef struct MATRIX {
    int rows;
    int cols;
    int **mat;
} Matrix, *pmat;

// Function to create a matrix
pmat CreateMatrix(int rows, int cols) {
    pmat mat = (pmat)malloc(sizeof(Matrix));
    if (!mat) return NULL;
    mat->rows = rows;
    mat->cols = cols;
    mat->mat = (int**)malloc(rows * sizeof(int*));
    if (!mat->mat) {
        free(mat);
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        mat->mat[i] = (int*)calloc(cols, sizeof(int));
        if (!mat->mat[i]) {
            // Free previously allocated rows on failure
            for (int j = 0; j < i; j++) {
                free(mat->mat[j]);
            }
            free(mat->mat);
            free(mat);
            return NULL;
        }
    }
    return mat;
}

// Function to assign values to a matrix
void assignMat(pmat mat, int arr[][4]) { // Assuming fixed column size (4) for simplicity
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mat->mat[i][j] = arr[i][j];
        }
    }
}

// Function to add two matrices
pmat addMat(pmat mat1, pmat mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        printf("Error: Matrices must have the same dimensions to be added.\n");
        return NULL;
    }

    pmat newMat = CreateMatrix(mat1->rows, mat1->cols);
    if (!newMat) return NULL;

    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            newMat->mat[i][j] = mat1->mat[i][j] + mat2->mat[i][j];
        }
    }
    return newMat;
}

// Function to print a matrix
void printMat(pmat mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to free the allocated memory for a matrix
void destMat(pmat mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}

// Main function
int main() {
    // Initialize the input matrix
    int mm[][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {7, 8, 9, 10}};

    // Create a matrix and assign values
    pmat mat = CreateMatrix(3, 4);
    assignMat(mat, mm);
    printf("Original Matrix:\n");
    printMat(mat);

    // Add the matrix to itself
    pmat newMat = addMat(mat, mat);
    if (newMat) {
        printf("Added Matrix:\n");
        printMat(newMat);
        destMat(newMat); // Free the added matrix
    }

    // Free the original matrix
    destMat(mat);

    return 0;
}
