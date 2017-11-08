#include<stdio.h>

void swapWithPointers(int* pnum1,int* pnum2){
    int tmp;
    tmp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = tmp;
}
void swap (int num1,int num2){
    int tmp1;
    tmp1 = num1;
    num1 = num2;
    num2 = tmp1;
}
int main(){
    int n1 = 5;
    int n2 = 10;
    int n3 = 5;
    int n4 = 10;
    swapWithPointers(&n1,&n2);
    swap(n3,n4);
    printf("%d,%d\n",n1,n2);
    printf("%d,%d\n",n3,n4);
    return 0;
}
