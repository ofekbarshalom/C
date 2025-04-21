#include <stdio.h>
#include <stdlib.h>

typedef struct MatrixNode{
    int mat[2][3];
    struct MatrixNode* next;
} MatrixNode;

MatrixNode* createMatrixNode(int mat[2][3]){
    MatrixNode* node = (MatrixNode*)malloc(sizeof(MatrixNode));
    if(node == NULL) return NULL;

    node->next = NULL;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            node->mat[i][j] = mat[i][j];
        }
    }
    return node;
}

void addMatrixNode(MatrixNode* node, int mat[2][3]){
    if(node == NULL) return;

    MatrixNode* newNode = createMatrixNode(mat);
    if(newNode == NULL) return;

    MatrixNode* current = node;

    while(current->next != NULL) current = current->next;

    current->next = newNode;
}

void printMatrix(int mat[2][3]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void printMatrixNode(MatrixNode* node){
    if(node == NULL) return;

    MatrixNode* current = node;

    while(current){
        printMatrix(current->mat);
        printf("\n");
        current = current->next;
    }
    printf("NULL");
}

void freeMatrixNode(MatrixNode* node){
    if(node == NULL) return;

    MatrixNode* current = node;
    MatrixNode* temp;

    while(current){
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main(){
    int mat1[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int mat2[2][3] = { {7, 8, 9}, {10, 11, 12} };
    int mat3[2][3] = { {13, 14, 15}, {16, 17, 18} };

    MatrixNode* node = createMatrixNode(mat1);
    if(node == NULL) return 1;

    // Add more nodes
    addMatrixNode(node, mat2);
    addMatrixNode(node, mat3);

    // Print the linked list
    printf("Linked list of matrices:\n");
    printMatrixNode(node);

    // Free the linked list
    freeMatrixNode(node);

    return 0;
}