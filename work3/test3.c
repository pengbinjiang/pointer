#include<stdio.h>
#include<stdlib.h>
#define SIZE 35

char* getLine(void){
    const size_t sizelncrement = 15; //需要增大时内存的增量
    char* buffer = (char*)malloc(SIZE);  //指向读入字符的指针
    char* currentPosition = buffer;  //指向缓冲区中下一个空白位置的指针
    size_t maximumLength = SIZE;
    size_t length = 0;
    int character;

    if(currentPosition == NULL){ 
	return NULL;
    }   
    while(1){
	character = getc(stdin);
	if(character == '\n'){
	    break;
    }
    if(++length >= maximumLength){
	char* newBuffer = realloc(buffer,maximumLength += sizelncrement);
	if(newBuffer == NULL){
	    free(buffer);
	    return NULL;
    }
    currentPosition = newBuffer + (currentPosition - buffer);
    buffer = newBuffer;
    }
    *currentPosition++ = character;
    }
    *currentPosition = '\0';

    return buffer;
}

int main(int argc,char** argv)
{
    printf("Please input string:\n");
    char* ptr_c = getLine();
    while(*ptr_c != '\0'){
	printf("%c",*ptr_c++); 
}
    printf("\n");

    return 0;
}
