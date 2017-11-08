#include "fptr.h"

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
fptrOperation select(char opcode){
    switch(opcode){
	case '+':return add;
	case '-':return subtract;
	case '*':return mul;
	case '/':return div;
	case '%':return rem;
    }
}
int evaluate(char opcode,int num1,int num2){
    fptrOperation operation = select(opcode);
    return operation(num1,num2);
}

