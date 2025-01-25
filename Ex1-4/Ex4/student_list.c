#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_list.h"

typedef struct Student {
    char name[50];
    int id;
    struct Student* next;
} Student;

struct StudentList {
    Student* head;
};

StudentListHandle createStudentList(){
    StudentListHandle list = (StudentListHandle)malloc(sizeof(*list));
    if(list){
        list->head = NULL;
    }
    return list;
}

void destroyStudentList(StudentListHandle list){
    if(!list) return;

    Student* current = list->head;
    while(current){
        Student* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

void addStudent(StudentListHandle list, char* name, int id){
    if(list == NULL) return;

    Student* newStudent = (Student*)malloc(sizeof(Student));
    if(newStudent == NULL) return;

    newStudent->id = id;
    strncpy(newStudent->name, name, sizeof(newStudent->name));
    newStudent->name[sizeof(newStudent->name) - 1] = '\0';

    newStudent->next = list->head;
    list->head = newStudent;
}

int removeStudent(StudentListHandle list, int id){
    if(list == NULL) return 0;

    Student* current = list->head;
    Student* prev = NULL;

    while(current){
        if(current->id == id){
            if(prev == NULL){
                list->head = current->next;
            }
            else{
                prev->next = current->next;
            }
            free(current);
            return 1;
        }
        else{
            prev = current;
            current = current->next;
        }
    }
    return 0;
}

int findStudent(StudentListHandle list, int id, char* outName){
    if(list == NULL) return 0;

    Student* current = list->head;

    while(current){
        if(current->id == id){
            strcpy(outName, current->name);
            return 1;
        }
        else{
            current = current->next;
        }
    }
    return 0;
}