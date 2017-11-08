#include<stdio.h>

int main(int argc,char **argv){
    int (*(arr[])) = {
	(int[]) {1,2,3,4,5} ,
	(int[]) {6,7,8},
	(int[]) {9,10,11,12},
	(int[]) {13,14} 
    } ;
    for(int i=0;i<4;i++){
	for(int j=0;j<5;j++){
	printf("arr[%d][%d] Address: %p Value: %d \n",i,j,&*(arr[i]+j),*(arr[i]+j));
	} 
	printf("\n");
} 

    return 0;
}
