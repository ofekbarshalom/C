#include <stdio.h>

int* findLoop(int size, int arr[]) {
    // 1 if the index is visited, 0 if not
    int loopArr[size];

    // Initialize loopArr to 0
    for (int i = 0; i < size; i++) {
        loopArr[i] = 0;
    }

    int i = 0;

    // Traverse the array to detect a loop
    while (i >= 0 && i < size) { // Ensure i stays within bounds
        if (loopArr[i] == 1) { // Loop detected
            return &arr[i];
        }
        loopArr[i] = 1; // Mark index as visited
        i += arr[i];    // Jump to the next index
    }

    // If no loop is found
    return NULL;
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the loop
    int* loopStart = findLoop(n, arr);

    if (loopStart != NULL) {
        printf("The loop starts at value: %d \n", *loopStart);
    } else {
        printf("No loop found in the array.\n");
    }

    return 0;
}
