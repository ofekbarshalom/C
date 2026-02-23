#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

typedef struct StudentList* StudentListHandle;

StudentListHandle createStudentList();

void destroyStudentList(StudentListHandle list);

void addStudent(StudentListHandle list, char* name, int id);

int removeStudent(StudentListHandle list, int id);

int findStudent(StudentListHandle list, int id, char* outName);

#endif