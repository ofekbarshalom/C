#include <stdio.h>

int main(){
    char testarr[] = {'A','B','C'};
    char * ptr=testarr;
    char val;
    val = *++ptr;
    printf("%c,%c\n",val,*ptr);
    val = *ptr++;
    printf("%c,%c\n",val,*ptr);

    return 0;
}
