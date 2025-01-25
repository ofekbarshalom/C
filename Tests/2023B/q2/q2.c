#include <stdio.h>
#include <math.h>

void print_bits(unsigned int num, int num_bits) {
    for (int i = num_bits - 1; i >= 0; i--) {
        // Isolate the bit at position i by shifting right and ANDing with 1
        int bit = (num >> i) & 1;
        printf("%d", bit);  // Print each bit
    }
    printf("\n");
}

int main(){
    // C2
    unsigned int status = 0b1111111111111111;
    unsigned int maskC2 = 0b11111110 ;
    unsigned int C2 = (status & maskC2) >> 1;

    printf("C2 in binary: ");
    print_bits(C2, 7);

    // C1
    unsigned int maskC1 = 0b1000000000;
    unsigned int C1 = (status & maskC1) >> 9;

    printf("C1 in binary: ");
    print_bits(C1, 1);

    // O1O2
    unsigned int maskO1O2 = 0b1100000000000;
    unsigned int O1O2 = (status & maskO1O2) >> 11;

    printf("O1O2 in binary: ");
    print_bits(O1O2, 2);

    int powow;

    if(O1O2 == 0){
        powow = pow(C2,C1);
        printf("pow: %d", powow);
    }
    if(O1O2 == 1){
        powow = pow(C1,C2);
        printf("pow2: %d", powow);
    }
    if(O1O2 == 2){
        int sub = C2 - C1;
        printf("sub: %d", sub);
    }
    if(O1O2 == 3){
        int add = C2 + C1;
        printf("add: %d", add);
    }

    return 0;
}