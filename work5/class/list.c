#include "list.h"

void initList(List *list){
    list->head = NULL;
    list->tail = NULL;
}

void addHead(List *list,DataType idata){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = idata;
    if(list->head == NULL){
	list->tail = node;
	node->next = NULL;
    }else{
	node->next = list->head;
}
    list->head = node;
} 

void addTall(List *list,DataType idata){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = idata;
    node->next = NULL;
    if(list->head == NULL){
	list->head = node;
    }else{
	list->tail->next = node;
    }
    list->tail = node;
}

void delete(List *list,DataType node){
    if(node == list->head->data){
	if (list->head->next == NULL){
	    list->head = list->tail = NULL;
	}else{
	    list->head = list->head->next;
	}
    }else{
	Node *tmp = list->head;
	while(tmp != NULL && tmp->next != node){
	    tmp = tmp->next;
	}
	if(tmp != NULL){
	    tmp->next = node->next;
	}
    }
    free(node);
}

Node *getNode(List *list,DataType data){
    Node *node = list->head;
    while (node !=NULL){
	if (compare(node->data,data) ==0){
	    return node;
	}
	node = node->next;
    }
    return NULL;
}

void displsyList(List *list){
    printf("\nList\n");
    Node *current = list->head;
    while(current != NULL){
	displayList(current->Data);
	current = current->next;
    }
}
