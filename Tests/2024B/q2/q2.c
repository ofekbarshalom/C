#include <stdio.h>

unsigned int encode(char ch){
    unsigned int result = 0;
    unsigned int letter = 0;

    if(ch >= 'a' && ch <= 'z'){
        result |= 1;
        letter = ch - 'a' + 1;
    } 
    if(ch >= 'A' && ch <= 'Z'){
        letter = ch - 'A' + 1;
    }

    letter <<= 1;
    result |= letter;

    return result;
}

// Encode two characters into a single result
unsigned int encode2(char ch1, char ch2) {
    unsigned int result = 0;

    // Encode the first character
    unsigned int encode_ch1 = encode(ch1);

    // Encode the second character
    unsigned int encode_ch2 = encode(ch2);

    // Extract the LSB of ch1's encoding and place it as the first bit in the result
    unsigned int ch1_bit = encode_ch1 & 1; // LSB of ch1
    result |= ch1_bit; // Add to the result

    // Extract the LSB of ch2's encoding and place it as the second bit in the result
    unsigned int ch2_bit = encode_ch2 & 1; // LSB of ch2
    result |= (ch2_bit << 1); // Add to the result, shifted left by 1 bit

    // Add the remaining bits of ch1's encoding
    result |= (encode_ch1 & ~1) << 1; // Shift left by 1 bit to make room for the 2 bits

    // Add the remaining bits of ch2's encoding
    result |= (encode_ch2 & ~1) << (1 + 5); // Shift left by 6 bits to align after ch1

    return result;
}

typedef struct Bitfields{
    unsigned int ch1IsUpper : 1;
    unsigned int ch2IsUpper : 1;
    unsigned int ch1 : 5;
    unsigned int ch2 : 5;
} Bitfields;

// Encode two characters into a Bitfields struct
Bitfields encode2(char ch1, char ch2) {
    Bitfields encoded = {0};

    // Determine if ch1 is uppercase or lowercase
    encoded.ch1IsUpper = (ch1 >= 'A' && ch1 <= 'Z') ? 0 : 1;

    // Determine if ch2 is uppercase or lowercase
    encoded.ch2IsUpper = (ch2 >= 'A' && ch2 <= 'Z') ? 0 : 1;

    // Get the alphabet position of ch1
    encoded.ch1 = (ch1 >= 'a' && ch1 <= 'z') ? (ch1 - 'a' + 1) : (ch1 - 'A' + 1);

    // Get the alphabet position of ch2
    encoded.ch2 = (ch2 >= 'a' && ch2 <= 'z') ? (ch2 - 'a' + 1) : (ch2 - 'A' + 1);

    return encoded;
}

int main(){
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);

    unsigned int encodedValue = encode(ch);
    if (encodedValue > 0) {
        printf("Encoded value for '%c': %u\n", ch, encodedValue);
    }

    return 0;
}