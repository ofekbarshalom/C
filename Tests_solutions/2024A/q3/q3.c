#include <stdio.h>
#include <stdlib.h>

typedef struct Nums{
    int small;
    long big;
} Nums;

Nums* createNums(){
    int size, small, big;

    printf("Enter the numbers of Nums: \n");
    scanf("%d", &size);
    if(size <= 0) return NULL;

    Nums* numArray = (Nums*)malloc(size * sizeof(Nums));
    if(numArray == NULL) return NULL;

    for(int i = 0; i < size; i++){
        printf("Enter an int: \n");
        scanf("%d", &small);
        printf("Enter an long: \n");
        scanf("%ld", &big);

        numArray[i].small = small;
        numArray[i].big = big;
    }
    return numArray;
}

void writeUsing(Nums* numArray){
    return;
}

void WritrArrayToFile(Nums* numArray, void (*writeUsing)(Nums*)){
    writeUsing(numArray);
}

Nums* readFromFile(char* filename, int i){
    FILE* file = fopen(filename, "r");
    if(file == NULL) return NULL;

    int count = 0;
    int small, big;

    while(fscanf(file, "%d %ld",&small, &big) == 2){
        if(count = i){
            Nums* num = (Nums*)malloc(sizeof(Nums));
            num->small = small;
            num->big = big;
            return num;
        }
    }
    return NULL;
}

int main(){

    return 0;
}