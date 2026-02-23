# C Student List

This exercise implements a simple singly linked list for student records in C.

## Files

- `student_list.h` — public API
- `student_list.c` — list implementation
- `main.c` — usage example (add, find, remove, destroy)
- `makefile` — build script

## Public API

- `createStudentList()`
- `destroyStudentList(StudentListHandle list)`
- `addStudent(StudentListHandle list, char* name, int id)`
- `removeStudent(StudentListHandle list, int id)`
- `findStudent(StudentListHandle list, int id, char* outName)`

## Build and Run

```bash
make
./Project
make clean
```

## Notes

- New students are inserted at the head of the list.
- `removeStudent` and `findStudent` return `1` on success and `0` on failure.
- Call `destroyStudentList` to free all allocated memory.
