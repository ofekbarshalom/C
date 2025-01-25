#include <stdio.h>

struct status_struct{
    unsigned int : 1;
    unsigned int c1 : 5;
    unsigned int : 1;
    unsigned int c2 : 2;
    unsigned int : 1;
    unsigned int o1 : 1;
    unsigned int : 1;
    unsigned int o2 : 1;
    unsigned int : 1;
};

void statusBitfields(struct status_struct status){
    if(status.o1 && status.o2){
        printf("add: %d", status.c1 / status.c2);
    }
    if(!status.o1 && status.o2){
        printf("sub: %d", status.c1 - status.c2);
    }
    if(status.o1 && !status.o2){
        printf("mult: %d", status.c1 * status.c2);
    }
    if(!status.o1 && !status.o2){
        printf("add: %d", status.c1 + status.c2);
    }
}

void statusMask(unsigned int status){
    // C1
    unsigned int maskC1 = 0b111110;
    unsigned int C1 = (status & maskC1) >> 1;

    printf("C1: %u \n", C1);

    // C2
    unsigned int maskC2 = 0b110000000;
    unsigned int C2 = (status & maskC2) >> 7;

    printf("C2: %u \n", C2);

    // O1
    unsigned int maskO1 = 0b10000000000;
    unsigned int O1 = (status & maskO1) >> 10;

    printf("O1: %u \n", O1);

    // O2
    unsigned int maskO2 = 0b1000000000000;
    unsigned int O2 = (status & maskO2) >> 12;

    printf("O2: %u \n", O2);

    unsigned int O1O2 = (O1 << 1) | O2;
    printf("O1O2: %u \n", O1O2);

    if(O1O2 == 0){
        unsigned int add = C1 + C2;
        printf("add: %u", add);
    }

    if(O1O2 == 1){
        unsigned int sub = C1 - C2;
        printf("sub: %u", sub);
    }

    if(O1O2 == 2){
        unsigned int mult = C1 * C2;
        printf("mult: %u", mult);
    }

    if(O1O2 == 3){
        unsigned int div = C1 / C2;
        printf("div: %u", div);
    }
}

int main(){
    struct status_struct status;
    statusBitfields(status);

    return 0;
}