#include <stdio.h>
#define INT_MAX 111111;

typedef struct item{
    int value;
    struct item *next;
} item;

// Function to merge k sorted linked lists
void multimerger(item* arr[], int size, item **pNewList) {
    int i, ind, min = INT_MAX;

    // If all the lists are empty
    if (size == 0) {
        *pNewList = NULL;
        return;
    }

    // Find the minimum element from the heads of all lists
    for (i = 0; i < size; i++) {
        if (arr[i] && arr[i]->value < min) {
            min = arr[i]->value;
            ind = i;
        }
    }

    // Create a new node with the minimum value and recursively merge the remaining lists
    *pNewList = arr[ind];
    arr[ind] = arr[ind]->next; // Move the pointer to the next element in the list

    // Recursively call multimerger for the remaining elements
    multimerger(arr, size, &((*pNewList)->next));
}

int main(){

    return 0;
}