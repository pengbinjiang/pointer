#include<stdio.h>
#define SIZE 10

char *sort(char *);
int main(int argc,char **argv){
    char arr[SIZE] = {4,3,6,9,7,2,8,10,1,5};
    sort(arr);
    for(int i=0;i<SIZE;i++)
    printf("%d ",*(arr+i));
    printf("\n");
} 


char *sort(char *arr)
{
    char *ptr = arr; 
    for(int i=0;i<SIZE-1;i++)
	for(int j=0;j<SIZE-1-i;j++) {
	    if(arr[j]>arr[j+1]) 
	    {
		int var = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = var;
	    }
	} 
    return ptr;
}

