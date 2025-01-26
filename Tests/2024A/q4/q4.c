#include <stdio.h>

unsigned int func(int ArrOne[8], int ArrTwo[8]){
    unsigned int result = 0;
    for(int i = 0; i < 8; i++){
        int shift = ArrTwo[ArrOne[i]];
        unsigned int mask = 1 << shift;
        unsigned int resultBit = mask & ArrOne[i];

        result |= resultBit;
    }
    return result;
}

typedef struct Bitfield{
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int bit5 : 1;
    unsigned int bit6 : 1;
    unsigned int bit7 : 1;
} Bitfield;

// Function to manipulate bits using Bitfields and `if`
unsigned int funcWithBitfields(Bitfield arrOne[8], Bitfield arrTwo[8]) {
    unsigned int result = 0;

    for (int i = 0; i < 8; i++) {
        unsigned int shift;

        // Check the i-th bit of arrTwo[i] and determine the shift
        if (i == 0 && arrTwo[i].bit0) shift = 0;
        else if (i == 1 && arrTwo[i].bit1) shift = 1;
        else if (i == 2 && arrTwo[i].bit2) shift = 2;
        else if (i == 3 && arrTwo[i].bit3) shift = 3;
        else if (i == 4 && arrTwo[i].bit4) shift = 4;
        else if (i == 5 && arrTwo[i].bit5) shift = 5;
        else if (i == 6 && arrTwo[i].bit6) shift = 6;
        else if (i == 7 && arrTwo[i].bit7) shift = 7;
        else continue; // Skip if the bit is not set

        // Extract the bit from arrOne based on the shift
        unsigned int mask = 1 << shift;
        unsigned int resultBit = *((unsigned int*)&arrOne[i]) & mask;

        // Update the result
        result |= resultBit;
    }

    return result;
}

unsigned int extract(unsigned int num){
    unsigned int mask = 0b11111000;
    unsigned int result = (num & mask) >> 3;
    return result;
}

int main(){
    // Example input arrays
    int ArrOne[8] = {3,5,7,6,1,0,4,6};
    int ArrTwo[8] = {1,2,8,3,5,7,0,4};

    unsigned int result = func(ArrOne, ArrTwo);
    printf("Result: %u\n", result);

    return 0;
}