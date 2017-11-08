#include<stdio.h>

int main(int argc,char **argv){
    int (*(arr[])) = {
	(int[]) {1,2,3,4,5} ,
	(int[]) {6,7,8},
	(int[]) {9,10,11,12},
	(int[]) {13,14} 
    } ;

    int row =0;
    for(int j=0;j<5;j++){
    printf("arr[%d][%d] Address: %p Value: %d \n",row,j,&arr[row][j],*(arr[row]+j));
    } 
    printf("\n");
 
    row =1;
    for(int j=0;j<3;j++){
    printf("arr[%d][%d] Address: %p Value: %d \n",row,j,&arr[row][j],*(arr[row]+j));
    } 
    printf("\n");

    row =2;
    for(int j=0;j<4;j++){
    printf("arr[%d][%d] Address: %p Value: %d \n",row,j,&arr[row][j],*(arr[row]+j));
    } 
    printf("\n");

    row =3;
    for(int j=0;j<2;j++){
    printf("arr[%d][%d] Address: %p Value: %d \n",row,j,&arr[row][j],arr[row][j]);

    } 
    printf("\n");

    return 0;
}
