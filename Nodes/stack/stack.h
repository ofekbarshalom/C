#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Structure for a stack node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure for the stack
typedef struct Stack {
    Node* top; // Points to the top of the stack
} Stack;

// Function prototypes
Stack* createStack();
void push(Stack* stack, int data);
int pop(Stack* stack);
int peek(Stack* stack);
bool isEmpty(Stack* stack);
void destroyStack(Stack* stack);

#endif
