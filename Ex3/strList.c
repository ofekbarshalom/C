#include "strList.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node{
    char* data;
    struct node *next;
} Node;

typedef struct StrList
{
    Node *head;
    size_t size;
} StrList;

Node* Node_alloc(const char *data, Node *next){
    if(data == NULL) return NULL;
    Node *p = (Node *)malloc(sizeof(Node));
    if(p == NULL) return NULL;
    char* newData = (char*) malloc(sizeof(char)*strlen(data) + 1);
    if(newData == NULL) return NULL;
    strcpy(newData, data);
    p->data = newData;
    p->next = next;
    return p;
}

void Node_free(Node *node){
    free(node->data);
    free(node);
}

StrList* StrList_alloc(){
    StrList *p = (StrList *) malloc(sizeof(StrList));
    if(p == NULL) return NULL;
    p->head = NULL;
    p->size = 0;
    return p;
}

void StrList_free(StrList* StrList){
    if(StrList == NULL) return;
    Node *p1 = StrList->head;
    Node *p2;
    while(p1){
        p2=p1;
        p1 = p1->next;
        Node_free(p2);
    }
    free(StrList);
}

size_t StrList_size(const StrList* StrList){
    if(StrList == NULL) return 0;
    return StrList->size;
}

void StrList_insertLast(StrList* StrList,const char* data){
    Node *p = Node_alloc(data, NULL);
    if(p == NULL){
        printf("Node alloc failed");
         return;
    }
    Node *p1 = StrList->head;

    if(p == NULL){
        StrList->head = p1;
        StrList->size++;
        return;
    }

    while(p1->next){
        p1 = p1->next;
    }

    p1->next = p;
    StrList->size++;
}

void StrList_insertAt(StrList* StrList,const char* data,int index){
    if(index > 0 || index > StrList->size) return;

    Node *p = Node_alloc(data, NULL);
    if(p == NULL){
        printf("Node alloc failed");
         return;
    }


    if(index == 0){
        StrList->head = p;
        StrList->size++;
    } 
    else if(index == StrList->size){
        StrList_insertLast(StrList, data);
    }
    else {
        Node *p1 = StrList->head;
        for(int i = 0; i < index - 1; i++){
            p1->next = p1;
        }
        p1->next = p;
        StrList->size++;
    }
}

char* StrList_firstData(const StrList* StrList){
    if(StrList->head == NULL) return NULL;
    return StrList->head->data;
}

void StrList_print(const StrList* StrList){
    if(StrList->head == NULL) {
        printf("\n");
        return;
    }
    Node* p = StrList->head;

    while(p){
        printf("%s",p->data);
        p = p->next;
    }
    printf("\n");
}

void StrList_printAt(const StrList* Strlist,int index){
    if(index > 0 || index > Strlist->size) return;

    Node *p = Strlist->head;
    for(int i = 0; i < index; i++){
        p = p->next;
    }
    printf("%s\n",p->data);
}

int StrList_printLen(const StrList* Strlist){
    int count = 0;
    Node* p = Strlist->head;
    while(p){
        count += strlen(p->data);
        p = p->next;
    }
    return count;
}

int StrList_count(StrList* StrList, const char* data){
    int count = 0;
    Node* p = StrList->head;
    while(p){
        if(strcmp(p->data, data) == 0){
            count++;
        }
        p = p->next;
    }
    return count;
}

void StrList_remove(StrList* StrList, const char* data){
    if(StrList == NULL) return;

    Node* current = StrList->head;
    Node* perv = NULL;
    Node* temp;

    while(current){
        if(strcmp(current->data,data) == 0){
            temp = current;
            if(perv == NULL){
            StrList->head = current->next;
            }
            else{
                perv->next = current->next;
            }

            current = current->next;
            Node_free(temp);
        }
        else{
            perv = current;
            current = current->next;
        }
    }
}

void StrList_removeAt(StrList* StrList, int index){
    if(index > 0 || index > StrList->size) return;

    Node *current = StrList->head;
    for(int i = 0; i < index-1; i++){
        current = current->next;
    }
    Node* prev = current;
    current=current->next;
    prev->next = current->next;
    Node_free(current);
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if(StrList1->size != StrList2->size){
        return 0;
    }

    Node* p1 = StrList1->head;
    Node* p2 = StrList2->head;

    while(p1){
        if(strcmp(p1->data, p2->data) != 0){
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return 1;
}

StrList* StrList_clone(const StrList* Strlist){
    struct StrList *newList = StrList_alloc();
    if(newList == NULL) return NULL;

    Node* p = Strlist->head;
    while(p){
        char *data = (char*)malloc(strlen(p->data) + 1);
        if(data == NULL) return NULL;
        strcpy(data, p->data);
        StrList_insertLast(newList, data);
        p = p->next;
        free(data);
    }
    return newList;
}

void StrList_reverse( StrList* StrList){
    Node* current = StrList->head;
    Node* pre = NULL;
    Node* next = NULL;

    while(current){
        next = current ->next;
        current -> next = pre;

        pre = current;
        current = next;
    }
    StrList->head = pre;
}

void StrList_sort(StrList* StrList){
    int changes = 1;
    while(changes){
        changes = 0;
        Node *curr = StrList->head;
        while(curr->next){
            if(strcmp(curr->data, curr->next->data)){
                changes = 1;
                char *temp = (char *) malloc(sizeof(char) * (strlen(curr->data) + 1));
                strcpy(temp, curr->data);
                curr->data = realloc(curr->data,sizeof(char) * (strlen(curr->next->data) + 1));
                strcpy(curr->data, curr->next->data);
                curr->next->data = realloc(curr->next->data,sizeof(char) * (strlen(temp) + 1));
                strcpy(curr->next->data, temp);
                free(temp);
            }

            curr = curr->next;
        }
    }
}

int StrList_isSorted(StrList* StrList){
    Node* p = StrList->head;
    if(p == NULL) return 1;
    
    while(p->next){
        if(strcmp(p->data, p->next->data) > 0){
            return 0;
        }
        p = (*p).next;
    }
    return 1;
}