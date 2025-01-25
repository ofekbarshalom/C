#include <stdio.h>
#include <stdlib.h>

int length(int num) {
    if (num == 0) return 1;  // Special case for zero
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

char* toString(int num) {
    int len = length(num);
    int tmp = num;
    int i = 0;
    int isNegative = 0;

    // Handle negative numbers
    if (num < 0) {
        isNegative = 1;
        tmp = -tmp;  // Work with the positive equivalent of num
        len++;  // Account for the minus sign
    }

    char* str = (char*)malloc((len + 1) * sizeof(char));  // Allocate memory for the string
    if (str == NULL) {
        printf("allocation error");
        exit(1);
    }

    // Handle negative numbers by adding '-' at the start
    if (isNegative) {
        str[i++] = '-';
    }

    // Convert number to string by extracting digits from right to left
    for (int j = len - 1; j >= i; j--) {
        str[j] = (tmp % 10) + '0';  // Convert digit to character
        tmp /= 10;
    }

    str[len] = '\0';  // Null-terminate the string
    return str;  // Return the resulting string
}

int main() {
    int num = -123;
    char* str = toString(num);
    printf("String: %s\n", str);  // Print the resulting string
    free(str);  // Free the allocated memory after use
    return 0;
}
