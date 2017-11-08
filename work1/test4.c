#include<stdio.h>

int main(int argc,char **argv){

    //(1)
    int var1;
    printf("请输入变量var1的值： ");
    scanf("%d",&var1);
    int *ptr_arr1 = &var1;
    ++var1;
    printf("(1) var1:%d\n",var1);
    ++*ptr_arr1;
    printf("(1) *ptr_arr1:%d\n",*ptr_arr1);

    //(2)
    const int cvar1;
    printf("请输入常量cvar1的值： ");
    scanf("%d",&cvar1);
    const int *ptr_cvar1;
    ptr_cvar1 = &var1;
    ++var1;
    printf("(2) var1:%d\n",*ptr_cvar1);
    
    //(3) 
    const int var2;
    int *const cptr_var1 = &var1;
    const int * cptr_var2 = &var2;
    ++var1;
    *cptr_var1 = var1;
    printf("(3) var1:%d\n",*cptr_var1);

    //(4)
    const int * const cptr_cvar1 = &cvar1;
    cptr_cvar1 = &var1;
    *cptr_cvar1 = 20;
    return 0;
}
