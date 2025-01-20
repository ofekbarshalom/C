#include <stdio.h>

void subarraySize(void *ptr1, void *ptr2, int sizeOfType){
    int subarraySize = ((char *)ptr2 - (char *)ptr1) / sizeOfType + 1;
    printf("The subarray size between the two given pointers is: %d", subarraySize);
}

int main(){
    int array[] = {0, 1, 2, 3, 4, 5}; // Example array
    int sizeOfType = sizeof(int);    // Size of the type
    
    void *ptr1 = &array[1];
    void *ptr2 = &array[4];

    subarraySize(ptr1, ptr2, sizeOfType);

    return 0;
}