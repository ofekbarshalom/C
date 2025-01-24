#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL) return NULL;

    stack->top = NULL;

    return stack;
}

void push(Stack* stack, int data){
    if(stack == NULL) return;

    Node* p = (Node*)malloc(sizeof(Node));
    if(p == NULL) return;

    p->data = data;
    p->next = stack->top;
    stack->top = p;
}

int pop(Stack* stack){
    if(isEmpty(stack)) return -1;

    Node* temp = stack->top;
    Node* next = temp->next;
    stack->top = next;
    int data = temp->data;

    free(temp);

    return data;
}

int peek(Stack* stack){
    if(isEmpty(stack)) return -1;

    return stack->top->data;
}

bool isEmpty(Stack* stack){
    return stack->top == NULL;
}

void destroyStack(Stack* stack){
    while(!isEmpty(stack)){
        pop(stack);
    }
    free(stack);
}