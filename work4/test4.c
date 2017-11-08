#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int compare(const char*,const char*);
int compareIgnoreCase(const char*,const char*);
char* stringToLower(const char*);
typedef int(fptrOperation)(const char*,const char*);
void sort(char**,int,fptrOperation operation);
void displayArr(char**,int);

int main(int argc,char **argv){
    char* arr[] = {"Bob","Ted","Carol","Alice","alice"};
    sort(arr,5,compare);
    displayArr(arr,5);

    sort(arr,5,compareIgnoreCase);
    displayArr(arr,5);
}


int compare(const char* s1,const char* s2){
    return strcmp(s1,s2);
}
int compareIgnoreCase(const char* s1,const char* s2){
    char* t1 = stringToLower(s1);
    char* t2 = stringToLower(s2);
    int result = strcmp(t1,t2);
    free(t1);
    free(t2);
    return result;
}

char* stringToLower(const char* string){
    char *tmp = (char*)malloc(strlen(string)+1);
    char *start = tmp;
    while (*string != 0){
	*tmp++ = tolower(*string++);
    }
    *tmp = 0;
    return start;
}

typedef int (fptrOperation)(const char*,const char*);

void sort(char *array[],int size,fptrOperation operation){
    int swap = 1;
    while(swap){
	swap = 0;
	for(int i=0;i<size-1;i++){
	    if(operation(array[i],array[i+1])>0){
		swap = 1;
		char *tmp = array[i];
		array[i] = array[i+1];
		array[i+1] = tmp;
	    }
	}
    }
}

void displayArr(char* arr[],int size){
    for(int i=0;i<size;i++){
	printf("%s  ",arr[i]);
    }
    printf("\n");
}
