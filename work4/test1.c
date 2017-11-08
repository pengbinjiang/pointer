#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char **argv){
    char header[] = "Hello,jju!";
    char *header1 = (char*)malloc(strlen("Hello,jju!")+1);
    strcpy(header1,"Hello,jju!");
    printf ("%s\n",header);
    printf("%s\n",header1);
    free(header1);
    return 0;
}
