#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct Node {
    int data;              // Data stored in the node
    struct Node* next;     // Pointer to the next node in the list
} Node;

// Function prototypes
void printList(Node* head);
void freeList(Node* head);
void deleteValue(Node** head, int value);

int main() {
    // Create the head of the linked list
    Node* head = NULL;

    // Dynamically allocate memory for nodes and populate the list
    Node* node1 = malloc(sizeof(Node));
    Node* node2 = malloc(sizeof(Node));
    Node* node3 = malloc(sizeof(Node));
    Node* node4 = malloc(sizeof(Node));
    Node* node5 = malloc(sizeof(Node));

    if (node1 == NULL || node2 == NULL || node3 == NULL || node4 == NULL || node5 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the nodes
    node1->data = 10;
    node1->next = node2;

    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = node4;

    node4->data = 20;
    node4->next = node5;

    node5->data = 40;
    node5->next = NULL;

    // Set the head of the list
    head = node1;

    // Print the original list
    printf("Original list:\n");
    printList(head);

    // Delete all nodes with value 20
    printf("\nDeleting all nodes with value 20...\n");
    deleteValue(&head, 20);
    printList(head);

    // Delete all nodes with value 10
    printf("\nDeleting all nodes with value 10...\n");
    deleteValue(&head, 10);
    printList(head);

    // Delete all nodes with value 50 (not in the list)
    printf("\nDeleting all nodes with value 50...\n");
    deleteValue(&head, 50);
    printList(head);

    // Free the remaining list
    freeList(head);

    return 0;
}


// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteValue(Node** head, int value){
    if(*head == NULL){
        printf("The list is empty.\n");
        return;
    }

    Node* current = *head;
    Node* previous = NULL;


    while (current != NULL)
    {
        if(current->data == value){
            Node* temp = current;
            if(previous == NULL){
                *head = current->next;
            }
            else {
                previous->next = current->next;
            }
            current = current->next;
            free(temp);
        }
        else{
            previous = current;
            current = current->next;
        }
    }
}
