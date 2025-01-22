#include <stdio.h>

struct Vehicle {
    unsigned int type : 3;
    unsigned int color : 4;
    unsigned int num_wheels : 3;
    unsigned int is_electric : 1;
};

int main(){
    struct Vehicle myVehicle;

    myVehicle.type = 1;
    myVehicle.color = 5;
    myVehicle.num_wheels = 6;
    myVehicle.is_electric = 1;

    printf("vehicle information:\n");
    printf("Type: %u\n", myVehicle.type);
    printf("color: %u\n", myVehicle.color);
    printf("num_wheels: %u\n", myVehicle.num_wheels);
    printf("is_electric: %u\n", myVehicle.is_electric);
    printf("size of vechicle: %d\n", sizeof(struct Vehicle));

    return 0;
}