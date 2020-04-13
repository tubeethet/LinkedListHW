//
//  slist.c
//  LinkedListAssignment
//
//  Created by Abdultawab Alubidy on 4/12/20.
//  Copyright © 2020 Abdultawab Alubidy. All rights reserved.
//

#include "slist.h"
#include "utils.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


snode* snode_create(int data, snode* next){
   snode*p = (snode*)malloc(sizeof(snode));
    p->data = data;
    p->next = next;
    return p;
}
slist* slist_create(void)
{
    slist *p = (slist*)malloc(sizeof(slist));
    p->head = NULL;
    p->size = 0;
    p->tail = NULL;
    return p;
}

void checkempty(slist *list){
    if(slist_empty(list)){
        fprintf(stderr, "list is empty");
        exit(1);
      }
    }

    bool slist_empty(slist* list) {return list->size==0;}
    size_t slist_size(slist* list) {return list->size;}

void slist_popfront(slist* list)
    {
        snode*p = list->head;
        list->head = list->head->next;
        free(p);
        --list->size;
    }
void slist_popback(slist* list){

        if(slist_empty(list)){fprintf(stderr, "Underflow error\n");}
    
        snode *p = list->head;
        snode *pre;
        while(p->next != NULL){pre =p; p= p->next;}
        pre->next=NULL;
        free(p);
        --list->size;
    }

    
void slist_pushfront(slist* list, int data)           // --- OK
    {
        snode *p = snode_create(data,list->head);
        list->head=p;
        if(list->size==0){list->tail=p;}
        ++list->size;
    }

    void slist_pushback(slist* list, int data){
        if(list->size==0){slist_pushfront(list,data); return;}
        snode*p=snode_create(data,NULL);
        list->tail->next=p;
        list->tail=p;
        ++list->size;
    }

void slist_clear(slist* list)    // --- OK
{
    while (!slist_empty(list)) {
        slist_popback(list);
    }
}

    void slist_print(slist* list, const char* msg){
        printf("%s\n", msg);
        if(slist_empty(list)){printf("List is empty \n"); return; }
        snode *p= list->head;
        while(p!=NULL){
            printf("%d --> %p\n",p->data,p->next);
            p=p->next;
        }
        
    }

int slist_front(slist* list)
{
    checkempty(list);
    return  list->head->data;
}
int slist_back(slist* list)
{
    checkempty(list);
    return list->tail->data;
}

