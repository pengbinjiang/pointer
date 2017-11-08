#include<stdio.h>
#include<string.h>


char *copy(char *strDest,const char *strsrc){
    char *tempptr = strDest;
    while((*strDest++ = *strsrc++) != '\0');
    return tempptr;

}

char *copy(char*,const char*);
int main(int argc,char *argv){
    
    char arr[] = "Jiu Jianhg";
    char arr2[] = "vyufkuyfkUniversity";
    cpy(arr2,arr);
    printf("%s",arr);
} 
