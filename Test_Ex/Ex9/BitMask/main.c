#include <stdio.h>

struct Bitfield {
    unsigned bit : 1;
};

unsigned and_using_masks(unsigned x, unsigned y, int n){
    unsigned result = 0;

    for(int i = 0; i < n; i++){
        unsigned bit_x = (x >> i) & 1;
        unsigned bit_y = (y >> i) & 1;

        unsigned bit_result = bit_x & bit_y;

        result |= (bit_result << i);
    }

    return result;
}

unsigned and_using_bitfields(unsigned x, unsigned y, int n){
    unsigned result = 0;
    struct Bitfield bx, by, br;

    for(int i = 0; i < n; i++){
        bx.bit = (x >> i) & 1;
        by.bit = (y >> i) & 1;

        br.bit = bx.bit & by.bit;

        result |= (br.bit << i);
    }
    
    return result;
}

int main(){

    return 0;
}