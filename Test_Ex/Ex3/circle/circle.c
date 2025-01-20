#include <stdio.h>
#include <math.h>
#define PI 3.14


void compute(){
    double r = 3.5;
    double area = PI * pow(r, 2);
    double perimeter = 2 * PI * r;
    
    printf("The area is: %.2f \n The perimeter is: %.2f", area, perimeter);
}

int main(){
    compute();
    return 0;
}

