#include <stdio.h>

int getNumber(FILE* file) {
    int firstChar = fgetc(file);
    int number = -1;

    if (firstChar != EOF && firstChar >= '0' && firstChar <= '9') {
        number = firstChar - '0';
    }
    return number;
}

void reverseString(char* fileName) {
    FILE* file = fopen(fileName, "rb+");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    int size = getNumber(file);
    if (size <= 0) {
        printf("Error: Invalid size in file.\n");
        fclose(file);
        return;
    }

    char ch1, ch2;

    for (int i = 0; i < size / 2; i++) {
        // Read the character at position i
        fseek(file, i + 1, SEEK_SET); // Skip the size character
        ch1 = fgetc(file);

        // Read the character at position (size - i - 1)
        fseek(file, size - i, SEEK_SET);
        ch2 = fgetc(file);

        // Swap the characters
        fseek(file, i + 1, SEEK_SET);
        fputc(ch2, file);

        fseek(file, size - i, SEEK_SET);
        fputc(ch1, file);
    }

    fclose(file);
}

int main() {
    char* fileName = "fileName.bin";

    // Create and write to the binary file
    FILE* file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return 1;
    }

    fputc('5', file); // Write the size
    fputs("ABCDE", file); // Write the content
    fclose(file);
    printf("File created\n");

    // Reverse the string in the file
    reverseString(fileName);

    // Open the file to read and print the reversed content
    file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error: Could not open file to read.\n");
        return 1;
    }

    printf("Reversed file:\n");
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    putchar('\n');

    fclose(file);

    return 0;
}