#include <stdio.h>
#include <stdlib.h>

typedef struct Worker{
    char* name;
    int id;
    struct Worker* next[5];
} Worker;

Worker* CreateWorker(char* name, int id){
    Worker* worker = (Worker*)malloc(sizeof(Worker));
    if(worker == NULL) return NULL;

    worker->name = strdup(name);
    if(worker->name == NULL){
        free(worker);
        return NULL;
    }
    worker->id = id;
    
    for(int i = 0; i < 5; i++){
        worker->next[i] = NULL;
    }

    return worker;
}

void addWorker(Worker* company,Worker* worker, int id){
    if(company == NULL) return NULL;

    if(company->id == id){
        company->next[0] = worker;
    } else {
        for(int i = 0; i < 5; i++){
            addWorker(company->next[i], worker, id);
        }
    }
}