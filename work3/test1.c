#include<stdio.h>
#define SIZE 10

int main(int argc,char **argv){
    int arr[SIZE] = {4,3,6,9,7,2,8,10,1,5} ;
    for(int i=0;i<SIZE-1;i++)
	for(int j=0;j<SIZE-1-i;j++) {
	    if(arr[j]>arr[j+1]) 
	    {
		int var = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = var;
	    }
	} 
    for(int k=0;k<SIZE;k++)
    printf("%d\t",arr[k]);
    printf("\n");
    return 0;
}
