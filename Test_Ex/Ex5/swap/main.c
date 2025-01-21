#include <stdio.h>
#include <string.h>

void swap_first_last(char arr[]) {
    int len = strlen(arr);
    int first_start = 0, first_end = 0;
    int middle_start = 0, middle_end = 0;
    int last_start = 0, last_end = len - 1;

    // Find the first word
    while (arr[first_end] != '\0' && arr[first_end] != ' ') {
        first_end++;
    }

    // Find the middle word
    middle_start = first_end + 1;
    while (arr[middle_start] == ' ') {
        middle_start++;
    }
    middle_end = middle_start;
    while (arr[middle_end] != '\0' && arr[middle_end] != ' ') {
        middle_end++;
    }

    // Find the last word
    last_start = middle_end + 1;
    while (arr[last_start] == ' ') {
        last_start++;
    }
    last_end = last_start;
    while (arr[last_end] != '\0' && arr[last_end] != ' ') {
        last_end++;
    }

    // Swap first and last words manually
    int first_len = first_end - first_start;
    int last_len = last_end - last_start;

    // Store the last word temporarily
    char temp[last_len + 1];
    for (int i = 0; i < last_len; i++) {
        temp[i] = arr[last_start + i];
    }
    temp[last_len] = '\0';

    // Shift the first word into the last word's position
    for (int i = 0; i < first_len; i++) {
        arr[last_start + i] = arr[first_start + i];
    }

    // Place the last word in the first word's position
    for (int i = 0; i < last_len; i++) {
        arr[first_start + i] = temp[i];
    }
}

int main() {
    char arr[] = "HELLO MY WORLD";
    printf("Before: %s\n", arr);

    swap_first_last(arr);

    printf("After: %s\n", arr);
    return 0;
}
