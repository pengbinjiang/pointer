#include<stdio.h>

int swap(int *p1,int *p2)
{
    int p;
    p=*p1;*p1=*p2;*p2=p;
}
int main()
{
    int a,b;int *pt1,*pt2;
    scanf("%d,%d",&a,&b);
    pt1=&a;pt2=&b;
    if(a<b) swap(pt1,pt2);

    printf("%d,%d \n",*pt1,*pt2);
    return 0;
}
//原因：行参的值无论如何改变都不能影响实参的值
