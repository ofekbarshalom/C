#include "advmath.h"

float power(int a,int b){
    float result = 1.0;
    for(int i = 0; i < b; i++){
        result *= a;
    }
    return result;
}

float square_root(int num){
    float x = num;
    float y = 1;
    float epsilon = 0.000001;
    while (x - y > epsilon)
    {
        x = (x + y) / 2;
        y = num / x;
    }
    return x;
}

int factorial(int num){
    if(num < 0){
        return 0; // Error for negative numbers
    }
    int result = 1;
    for(int i = 1; i <= num; i++){
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