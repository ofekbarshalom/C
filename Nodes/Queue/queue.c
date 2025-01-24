#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) return NULL;

    q->head = q->tail = NULL;

    return q;
}

void enqueue(Queue* q, int data){
    if(q == NULL) return;

    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;

    if(q->head == NULL){
        q->head = q->tail = p;
    }
    else{
        q->tail->next = p;
        q->tail = p;
    }
}

int dequeue(Queue* q){
    if(q == NULL) return -1;

    if(q->head == NULL){
        return -1;
    }
    Node* temp = q->head;
    int data = temp->data;

    q->head = q->head->next;

    free(temp);
    return data;
}

bool isEmpty(Queue* q){
    return q->head == NULL;
}

void destroyQueue(Queue* q){
    while(!isEmpty(q)){
        dequeue(q);
    }
    free(q);
}
