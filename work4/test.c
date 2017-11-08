
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc,char **argv){
    //char* arr[] = {"Bob","Ted","Carol","Alice","alice"};
    char arr[] = "JJU Jiang";
    int length = strlen(arr);
    for(int i=0;i<length;i++){

    arr[i] = tolower(arr[i]);
    } 
    printf("%s\n",arr);
    //for(int i=0;i<5;i++){
    //printf("%s\t",arr[i]);
    //} 
    //printf("\n");
}
