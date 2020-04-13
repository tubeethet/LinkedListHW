#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include "dlist.h"
#include "utils.h"


dnode* dnode_create(int data, dnode* prev, dnode* next){
    dnode*p = (dnode*)malloc(sizeof(dnode));
    p->data= data;
    p->prev = prev;
    p->next = next;
    return p;
}
dlist* dlist_create(void){
    dlist *p= (dlist*)malloc(sizeof(dlist));
    p->head = NULL;
    p->size = 0;
    p->tail = NULL;
    return p;
}

bool dlist_empty(dlist* list){
    return list->size==0;
}
size_t dlist_size(dlist* list){
    return list->size;
}

void dlist_popfront(dlist* list){
    dnode *p= list->head;
    list->head= list->head->next;
    list->head->prev= NULL;
    free(p);
    --list->size;
}
void dlist_popback(dlist* list){
    dnode *p = list->head;
    dnode*prev= p;
    while(p->next!=NULL){prev=p; p=p->next;}
    prev->next=NULL;
    free(p);
    list->tail=prev;
    --list->size;
    
}

void dlist_pushfront(dlist* list, int data){
    dnode* p = dnode_create(data,NULL,list->head);
    list->head=p;
    if(list->size==0){list->tail= p;}
    ++list->size;
}
void dlist_pushback(dlist* list, int data){
    if(list->size==0){dlist_pushfront(list,data); return;}
    dnode * p = dnode_create(data, list->size==1?NULL: list->tail,NULL);
    list->tail->next=p;
    list->tail= p;
    ++list->size;
}

void dlist_clear(dlist* list){
    while(!dlist_empty(list)){
        dlist_popback(list);
    }
}
void dlist_print(dlist* list, const char* msg){
    printf("%s \n", msg);
    if(dlist_empty(list)){printf("List is empty \n"); return ;}
    dnode *p= list->head;
    while(p!=NULL){
        printf(" %p <-- %d --> %p \n", p->prev,p->data, p->next);
        p=p->next;
    }
}

int dlist_front(dlist* list){
    return list->head->data;
    
}
int dlist_back(dlist* list){
    return list->tail->data;
}
