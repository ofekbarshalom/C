#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* CreateNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

void AddNode(Node* list, int data){
    if(list == NULL) return;

    Node* current = list;
    Node* prev = NULL;

    Node* newNode = CreateNode(data);
    if(newNode == NULL) return;

    while(current && current->data < data){
        prev = current;
        current = current->next;
    }

    if(prev == NULL){
        newNode->next = list;
        list = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}

void PrintNodes(Node* list){
    Node* current = list;

    while(current){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void PrintBiggerNodes(Node* list, int num){
    Node* current = list;

    while(current && current->data < num){
        current = current->next;
    }

    PrintNodes(current);
}

Node* reverseList(Node* list){
    if(list == NULL) return NULL;

    Node* current = list;
    Node* prev = NULL;
    Node* temp;

    while(current){
        temp = current->next;  // Store next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev to current node
        current = temp;        // Move to the next node
    }

    return prev;
}

Node* freeList(Node* list){
    Node* current = list;
    Node* temp;

    while(current){
        temp = current->next;
        free(current);
        current = temp;
    }
}

int main(){
    Node* head = CreateNode(1);

    AddNode(head, 3);
    AddNode(head, 2);

    PrintNodes(head);

    // PrintBiggerNodes(head, 2);

    head = reverseList(head);

    printf("Reversed list: \n");
    PrintNodes(head);

    return 0;
}