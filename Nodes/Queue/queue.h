#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* head;
    Node* tail;
} Queue;

Queue* createQueue();
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
bool isEmpty(Queue* queue);
void destroyQueue(Queue* queue);








#endif