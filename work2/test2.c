#include<stdio.h>

int add(int num1,int num2){
    return num1 + num2;
}
int subtract(int num1,int num2){
    return num1 - num2;
}
int mul(int num1,int num2){
    return num1 * num2;
}
int div(int num1,int num2){
    return num1 / num2;
}
int rem(int num1,int num2){
    return num1 % num2;
}
typedef int (*fptrOperation)(int,int);

int compute(fptrOperation operation,int num1,int num2){
    return operation(num1,num2);
}

int main(int *argc,char **argv){
    printf("%d\n",compute(add,5,6));
    printf("%d\n",compute(subtract,5,6));
    printf("%d\n",compute(mul,5,6));
    printf("%d\n",compute(div,5,6));
    printf("%d\n",compute(rem,5,6));

    return 0;
}
