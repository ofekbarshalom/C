#include <stdio.h>
#define N 5

void read_grades(int grade[]){
    int sum = 0;

    for(int i = 0; i < N; i++ ){
       printf("Enter grade for student #%d , ",i + 1);
       scanf("%d", &grade[i]);
       sum += grade[i];
    }
    printf("\n");

    double average = (double)sum / N;
    printf("The grade avarge is: %.2f \n", average);
    printf("\n");

    printf("The grades above average are:\n");
    for(int i = 0; i < N; i++ ){
        if(grade[i] > average){
            printf("student #%d \n",i + 1);
        }
    }
    printf("\n");
}

int main(){
    int grade[N];  //creates an array of int's with size 50.
    read_grades(grade);
    return 0;
}
