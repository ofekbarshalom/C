#include <stdio.h>
#define N 3

void xyz(){
    double arr[N][3];
    double centerMessPoint[3] = {0.0, 0.0, 0.0};
    double x, y, z;

    for(int i = 0; i < N; i++){

        printf("Enter x:");
        scanf("%lf", &x);

        printf("Enter y:");
        scanf("%lf", &y);

        printf("Enter z:");
        scanf("%lf", &z);

        arr[i][0] = x;
        arr[i][1] = y;
        arr[i][2] = z;

        centerMessPoint[0] += x;
        centerMessPoint[1] += y;
        centerMessPoint[2] += z;
    }
    centerMessPoint[0] /= N;
    centerMessPoint[1] /= N;
    centerMessPoint[2] /= N;

    printf("The center of mass point is:\n");
    printf("x: %lf  y: %lf z: %lf \n", centerMessPoint[0], centerMessPoint[1], centerMessPoint[2]);
}

int main(){
    xyz();
    return 0;
}