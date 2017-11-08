#include "fptr.h"

int main(int argc,char **argv){
    printf("%d\n",evaluate('+',5,6));
    printf("%d\n",evaluate('-',5,6));
    printf("%d\n",evaluate('*',5,6));
    printf("%d\n",evaluate('/',5,6)); 
    printf("%d\n",evaluate('%',5,6));

    return 0;

}
