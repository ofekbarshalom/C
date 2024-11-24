#include <math.h>
#include "advmath.h"

float power(int a,int b){
    float result = 1.0;
    for(int i = 0; i < b; i++){
        result *= a;
    }
    return result;
}

float square_root(int a){
    if(a < 0){
        return -1; // Error for negative input
    }
    return sqrt(a);
}

int factorial(int a){
    if(a < 0){
        return 0; // Error for negative numbers
    }
    int result = 1;
    for(int i = 1; i <= a; i++){
        result *= i;
    }
    return result;
}

float average(int arr[], int size){
    if(size <= 0){
        return 0; // Avoid division by zero
    }
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (float)sum / size; // Cast sum to float 
}