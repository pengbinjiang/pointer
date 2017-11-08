#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv){
    int t;
    int size;    
    int *ptr_arr = (int *)malloc(sizeof(int)*size);
    printf("请输入所申请指针内存的大小： ");
    scanf("%d",&size);
    printf("请输入变量的初始化值： ");
    scanf("%d",&t);
    //ptr_arr = &t;
    printf("请输入初始值的增加量： ");
    int add;
    scanf("%d",&add);
    int *ptr_arr1 = ptr_arr;
    for(int i = 0;i<size;i++) {
    *(ptr_arr + i) = t+add*i;
} 
    for(int i = 0;i<size;i++) {
    printf("value:%d,address:%p \n",*(ptr_arr + i),ptr_arr + i);
} 
    free(ptr_arr);
    printf("%p",ptr_arr);
    free(ptr_arr);
    return 0;
} 
