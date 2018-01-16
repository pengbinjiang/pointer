#ifndef list_h
#define list_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int DataType;

typedef struct _node{
    DataType Data;
    struct _node *next;
} Node;

typedef struct _list{
    Node *head;
    Node *tail;
} List;
void initList(List *);
void addHead(List*,DataType);
void addTall(List*,DataType);
void delete(List*,DataType);
Node *getNode(List*,DataType);
void displayList(List*);

#endif
