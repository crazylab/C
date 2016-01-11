#include <stdio.h>
#include "linkedList.h"

void initializeList(LinkedList *list){
    list -> first = NULL;
    list -> last = NULL;
    list -> length = 0;
}
LinkedList createList(void){
    LinkedList list;
    initializeList(&list);
    return list;
}
