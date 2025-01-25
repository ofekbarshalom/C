#include <stdio.h>

void findPairWithTargetSum(int arr[],int length, int target){
    int left = 0;
    int right = length - 1;

    while (left < right){
        // Calculate the sum of elements at the pointers
        int sum = arr[left] + arr[right];

        if(sum == target){
            // If the target is found, print the result
            printf("Number %d at index %d and number %d at index %d sum is %d as required!\n",
                   arr[left], left, arr[right], right, target);
            return;
        } else if (sum < target){
            // If the sum is less than the target, move the left pointer to the right
            left++;
        } else {
            // If the sum is greater than the target, move the right pointer to the left
            right--;
        }
    }

    // If no pair is found
    printf("No such numbers exist in the given array!\n");
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 10};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the target sum: ");
    scanf("%d", &target);

    findPairWithTargetSum(arr, length, target);

    return 0;
}