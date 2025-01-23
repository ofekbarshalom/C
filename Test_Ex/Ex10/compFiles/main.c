#include <stdio.h>
#include <stdlib.h>

int fileComperator(const char *filename1, const char *filename2){
    FILE *file1 = fopen(filename1,"r");
    FILE *file2 = fopen(filename2,"r");

    if(file1 == NULL || file2 == NULL){
        printf("File could not be opened\n");
        if (file1) fclose(file1);
        if (file2) fclose(file2);
        return -1;
    }

    char file1_char, file2_char;

    while(1){
        size_t read1 = fread(&file1_char, sizeof(char), 1, file1);
        size_t read2 = fread(&file2_char, sizeof(char), 1, file2);

        // Check if both files reached EOF
        if (read1 == 0 && read2 == 0) {
            fclose(file1);
            fclose(file2);
            return 1; // Files are identical
        }

        if (read1!=read2){
            fclose(file1);
            fclose(file2);
            return 0;
        }

        if (file1_char != file2_char){
            fclose(file1);
            fclose(file2);
            return 0;
        }
    }

    fclose(file1);
    fclose(file2);
    return 1;
}

int main(){
    const char *filename1 = "file1.txt";
    const char *filename2 = "file2.txt";

    int result = fileComperator(filename1, filename2);
    printf("result: %d", result);
    return 0;
}