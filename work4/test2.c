
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(char *,char *);
char *copy(char *,const char *);
char *cat(char *,char *);

int main(int argc,char *argv){
    char arr[] = "Jiu Jiang";
    char arr1[] = "University";
    char arr2[] = "JiuJiang University";
    char arr3[] = "JiuJiang ";

//比较
    if (compare(arr,arr1)==1)  printf("The comand dayu comand1\n");
    if (compare(arr,arr1)==-1) printf("The comand xiaoyu comand1\n");
    if (compare(arr,arr1)==0)  printf("The comand dengyu comand1\n");
//复制    
    copy(arr,arr2);
    printf("%s\n",arr);
//拼接
    cat(arr3,arr1);
    printf("%s\n",arr3);

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
char *copy(char *comand,const char *comand1){
    char *ptr = comand;
    while((*comand++ = *comand1++) != '\0');
    return ptr;

}
//拼接函数
char *cat(char *comand,char *comand1){
    int t1,t2;
    t1=strlen(comand);
    t2=strlen(comand1);
    char *ptr1 = comand;
    for(int i=0;i<t2;i++){
	*(comand + t1 +i) = *(comand1 +i);
    }
    return ptr1; 
}
