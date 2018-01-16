#include "list.h"

int main(int argc,char** argv)
{
    List *list1 = (List *)malloc(sizeof(List));
    printf("the addhead:\n");
    initList(list1);
    addHead(list1,1);
    addHead(list1,3);
    addHead(list1,5);
    addHead(list1,7);
    addHead(list1,9);
    displayList(list1);
    delete(list1,1);
    displayList(list1);

    return 0;
}
