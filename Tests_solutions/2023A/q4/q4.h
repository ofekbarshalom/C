#ifndef Q4_H
#define Q4_H

typedef struct AdptArray_* PAdptArray;

typedef enum Result {FAIL = 0, SUCCESS} Result;

typedef void* PElement;

typedef void(*DEL_FUNC)(PElement);

typedef PElement(*COPY_FUNC)(PElement);

PAdptArray CreateAdptArray(COPY_FUNC, DEL_FUNC);

void DeleteAdptArray(PAdptArray);

Result SetAdptArrayAt(PAdptArray, int, PElement);

PElement GetAdptArrayAt(PAdptArray, int);

int GetAdptArraySize(PAdptArray);

#endif