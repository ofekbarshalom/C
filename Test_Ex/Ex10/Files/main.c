#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE* ptr;

    ptr = fopen("myfile.bin","rb+");
    if(ptr == NULL){
        perror("Error: Could not open file\n");
        return 1;
    }

    int count;
    fread(&count, sizeof(int), 1, ptr);

    if(count > 1){
        for(int i = 0; i < count / 2; i++){
            long pos1 = sizeof(int) + i * sizeof(char); // Position of the i-th character
            long pos2 = sizeof(int) + (count - i - 1) * sizeof(char); // Position of the (count-i-1)th character

            char char1, char2;

            fseek(ptr, pos1, SEEK_SET);
            fread(&char1, sizeof(char), 1, ptr);

            fseek(ptr, pos2, SEEK_SET);
            fread(&char2, sizeof(char), 1, ptr);

            fseek(ptr, pos1, SEEK_SET);
            fwrite(&char2, sizeof(char), 1, ptr);

            fseek(ptr, pos2, SEEK_SET);
            fwrite(&char1, sizeof(char), 1, ptr);
        }
    }
    fclose(ptr);

    printf("Characters reversed in file!");
}
