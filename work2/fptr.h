#include<stdio.h>

#ifndef fptr_h
#define fptr_h

int add(int,int);
int subtract(int,int);
int mul(int,int);
int div(int,int);
int rem(int,int);
typedef int (*fptrOperation)(int,int);
int evaluate(char,int,int);

#endif
