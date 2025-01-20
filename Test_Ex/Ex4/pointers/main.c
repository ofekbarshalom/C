#include <stdio.h>

void swap(int* a, int* b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

void swap3(int* a, int* b, int* c){
    if(*a > *b){ swap(a, b); }
    if(*b > *c){ swap(b, c); }
    if(*a > *c){ swap(a, c); }
}

int main(){
    int a = 4;
    int b = 2;
    int c = 3;

    swap3(&a, &b, &c);
    printf("a: %d, b: %d c: %d", a, b, c);

    return 0;
}