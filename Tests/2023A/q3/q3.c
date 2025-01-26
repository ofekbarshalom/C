#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct QUEUE{
    struct Node* head;
    struct Node* tail;
} queue, *pqueue;

void push(queue* q, int num){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->data = num;
    newNode->next = NULL;
    
     if (q->tail == NULL) {
        // If the queue is empty, the new node becomes both the head and tail
        q->head = newNode;
        q->tail = newNode;
    } else {
        // Add the new node to the tail and update the tail pointer
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

void pop(queue* q){
    if(q->head == NULL) return;

    Node* temp = q->tail;
    q->head = q->head->next;
    free(temp);

    if(q->head == NULL){
        q->tail = NULL;
    }
    
}

int main(){
    queue* q = {NULL, NULL};
    
    push(q, 10);
    push(q, 20);
    push(q, 30);

    return 0;
}