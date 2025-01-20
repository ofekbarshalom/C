#include <stdio.h>
#include <math.h>
#define PI 3.14
#define RADIUS 3.5

int main(){
    double area = PI * pow(RADIUS, 2);
    double perimeter = 2 * PI * RADIUS;
    
    printf("The area is: %.2f \n The perimeter is: %.2f", area, perimeter);

    return 0;
}

