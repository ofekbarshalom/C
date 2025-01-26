#include <stdio.h>
#include "q4.h"

typedef struct AdptArray_{
    int ArrSize;
    PElement* pElemArr;
    DEL_FUNC delFunc;
    COPY_FUNC copyFunc;
}AdptArray;

PAdptArray CreateAdptArray(COPY_FUNC, DEL_FUNC){
    
}