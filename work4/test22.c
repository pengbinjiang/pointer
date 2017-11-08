#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(char *comand,char *comand1);
void copy(char *comand,char *comand1);
void cat(char *comand,char *comand1);

int main(int argc,char *argv){
    char arr[] = "Jiu Jiang";
    char arr1[] = "University";
    char arr2[] = "University";
    char arr3[] = "JiuJiang ";
//比较
    if (compare(arr,arr1)==1)  printf("The comand dayu comand1\n");
    if (compare(arr,arr1)==-1) printf("The comand xiaoyu comand1\n");
    if (compare(arr,arr1)==0)  printf("The comand dengyu comand1\n");
//复制    
    int t1,t2;
    t1=strlen(arr);
    t2=strlen(arr2);
    copy(arr,arr2);
    if(t1>t2){
	for(int i=0;i<t2+1;i++){
	    printf("%c",*(arr +i));
	}
	printf("\n");
    }	
    else {
	for(int i=0;i<t1+1;i++){
	    printf("%c",*(arr +i));
	}
	printf("\n");
    }
//拼接
    cat(arr3,arr1);
    for(int i=0;i<t1+t2;i++){
	printf("%c",*(arr3 + i));
    }
    printf("\n");

} 


//比较函数
int compare(char *comand ,char *comand1){
    int t,t1,t2;
    int j=0;
    t1=strlen(comand);
    t2=strlen(comand1);
    if(t1>t2) t=t1,t1=t2,t2=t;
    for(int i=0;i<t1+1;i++){
    if(comand[i]>comand1[i])
    {
    return 1;
    break;
    }
    if(comand[i]<comand1[i])
    {
    return -1;
    break;
    } 
    if(comand[i]==comand1[i]) j++;
    }
    if(j==t2+1) {
    return 0;
} 
}

//复制函数
void copy(char *comand,char *comand1){
    int t,t1,t2;
    t1=strlen(comand);
    t2=strlen(comand1);
    //if(t1<t2){
    //char *newcomand = realloc(comand,t1=t1+0);
    //for(int i=0;i<t2;i++){
//	*(comand + i) = *(comand1 +i); 
  //  }
   // }
    if(t1>t2) t=t1,t1=t2,t2=t;
   // else{
    for(int i=0;i<t1;i++){
	*(comand + i) = *(comand1 +i); 
    }
    return ;
//} 
} 
//剪切函数
void cat(char *comand,char *comand1){
    int t1,t2;
    t1=strlen(comand);
    t2=strlen(comand1);
    for(int i=0;i<t2;i++){
	*(comand + t1 +i) = *(comand1 +i);
    }
    return; 
}
