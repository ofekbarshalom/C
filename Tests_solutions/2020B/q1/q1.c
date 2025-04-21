#include <stdio.h>
void init_array(const double array1[], double array2[]){
    size_t num_items = sizeof(array1) / sizeof(array1[0]);
    for (int i = 0; i< num_items; ++i){
        array2[i] = 2*array1[i];
    }
}

int main(){
    double array1[7] = {1.2,2.4,4.8};
    double array2[7];
    init_array(array1,array2);
    for(size_t i=0; i<7; ++i) {
        printf("%f, ", array2[i]);
    }

    return 0;
}