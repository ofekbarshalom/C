#include <stdio.h>
#include <stdlib.h>
#include "q4.h"

typedef struct AdptArray_{
    int ArrSize;
    PElement* pElemArr;
    DEL_FUNC delFunc;
    COPY_FUNC copyFunc;
}AdptArray;

PAdptArray CreateAdptArray(COPY_FUNC copy_func, DEL_FUNC del_func){
    PAdptArray adptArray = (PAdptArray)malloc(sizeof(AdptArray));
    if(adptArray == NULL) {
        printf("Error");
        return NULL;
    }
    adptArray->ArrSize = 0;
    adptArray->pElemArr = NULL;
    adptArray->copyFunc = copy_func;
    adptArray->delFunc = del_func;

    return adptArray;
}

Result SetAdptArrayAt(PAdptArray pArr, int idx, PElement pNewElem){
    PElement* newpElemArr;
    if (pArr == NULL) return FAIL;

    if (idx >= pArr->ArrSize){
        // Extend Array
        if ((newpElemArr = (PElement*)calloc((idx + 1) , sizeof(PElement))) ==NULL){
            return FAIL;
        }

        // Init new array and copy old array to new array
        memcpy(newpElemArr,pArr->pElemArr, (pArr->ArrSize) * sizeof(PElement));
        // Free old array and save new array
        free(pArr->pElemArr);
        pArr->pElemArr = newpElemArr;
    }
    // Delete Previous Elem and Set New Elem
    pArr->delFunc(pArr->pElemArr[idx]);
    pArr->pElemArr[idx] = pArr->copyFunc(pNewElem);

    // Update Array Size
    pArr->ArrSize = (idx >= pArr->ArrSize) ? (idx + 1) : pArr->ArrSize;
    return SUCCESS;
}

void DeleteAdptArray(PAdptArray pArr){
    if(pArr == NULL) return;

    for(int i = 0; i < pArr->ArrSize; i++){
        pArr->delFunc(pArr->pElemArr[i]);
    }
    free(pArr->pElemArr);
    free(pArr);
}