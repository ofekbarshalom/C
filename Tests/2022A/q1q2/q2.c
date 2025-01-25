#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int capacity;
    int count;
    int *arr;
    int head;
    int tail;
} Queue;

Queue* createQueue(int capacity){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL) return NULL;

    q->arr = (int*)malloc(sizeof(int) * capacity);
    if(q->arr) return NULL;

    q->capacity = capacity;
    q->count = 0;
    q->head = 0;
    q->tail = -1;

    return q;
 }

 int enqueue(Queue* q, int data){
    if(q->count >= q->capacity){
        return -1;
    }
    q->tail = q->tail + 1;
    q->arr[q->tail] = data;
    q->count++;

    return 0;
 }

 int dequeue(Queue* q){
    if(q->count == 0){
        return -1;
    }
    q->head = q->head + 1;
    q->count--;

    return 0;
 }