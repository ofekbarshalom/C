#include <stdio.h>
#include "student_list.h"

int main(){
    // Create list
    StudentListHandle list = createStudentList();

    // Add Students
    char* name = "ofek";
    int id = 324161421;
    addStudent(list, name, id);

    name = "roy";
    id = 323917104;
    addStudent(list, name, id);

    // Find student
    char outName[50];
    int check = findStudent(list, id, outName);
    printf("did we found the student: %d \n", check);

    // Remove student
    check = removeStudent(list, id);
    printf("did we remove the student: %d \n", check);
    
    // Destory student list
    destroyStudentList(list);

    return 0;
}