#include <stdio.h>

int main()
{
//Basic primitive types
printf("sizeof(char) = %zu\n",sizeof(char));
printf("sizeof(int) = %zu\n",sizeof(int));
printf("sizeof(float) = %zu\n",sizeof(float));
printf("sizeof(double) = %zu\n",sizeof(double));
//Other types:
printf("sizeof(void*) = %zu\n",sizeof(void*));
printf("sizeof(long double)= %zu\n",sizeof(long double));
return 0;
} 