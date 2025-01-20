#include <stdio.h>

void check(int num, int arr[10]){
    int left = 0;
    int right = 9;
    int found = 0;
    while(left <= right){
        if(arr[left] + arr[right] == num){
            printf("The numbers are: %d and %d", arr[left], arr[right]);
            found = 1;
            break;
        }
        if(arr[left] + arr[right] < num){
            left++;
        }
        else{
            right--;
        }
    }
    if(found == 0){
        printf("No match found");
    }
}
    

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num = 6;
    check(num, arr);

    return 0;
}