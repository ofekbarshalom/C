#include <stdio.h>
#include <stdbool.h>

bool isSubarray(int A[], int n, int B[], int m, int **start, int **end){
     for (int i = 0; i <= n - m; i++) { // Iterate through A, ensuring space for B
        bool match = true;

        for (int j = 0; j < m; j++) { // Check if B matches A at index i
            if (A[i + j] != B[j]) {
                match = false;
                break;
            }
        }

        if (match) { // If match found
            *start = &A[i];           // Pointer to the start of B in A
            *end = &A[i + m - 1];     // Pointer to the end of B in A
            return true;
        }
    }

    *start = NULL; // If no match found
    *end = NULL;
    return false;
}

int main(){
    int n, m;

    // Input the size of array A
    printf("Enter the size of array A: ");
    scanf("%d", &n);
    int A[n]; // Dynamically allocate array A

    // Input the elements of array A
    printf("Enter the elements of array A: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Input the size of array B
    printf("Enter the size of array B: ");
    scanf("%d", &m);
    int B[m]; // Dynamically allocate array B

    // Input the elements of array B
    printf("Enter the elements of array B: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    int *start = NULL; // Pointer to the start of B in A
    int *end = NULL; // Pointer to the end of B in A

    if (isSubarray(A, n, B, m, &start, &end)) {
        printf("Subarray found! Start at %d, End at %d\n", *start, *end);
    } else {
        printf("Subarray not found!\n");
    }
    return 0;
}