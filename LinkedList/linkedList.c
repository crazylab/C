#include <stdio.h>
#include <stdLib.h>
#include <string.h>
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

void initializeNode(Node *node){
    node -> previous = NULL;
    node -> next = NULL;
}
int add_to_list(LinkedList *list, void *element){
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    initializeNode(node);
    if(0 == list -> length){
        list -> first = node;
        list -> last = node;
    }
    else{
        node -> previous = list -> last;
        list -> last -> next = node;
        list -> last = node;
    }
    node -> element = element;
    list -> length++;
    return list -> length;
}

void *get_first_element(LinkedList list){
    return list.first -> element;
}

void *get_last_element(LinkedList list){
    return list.last -> element;
}

void forEach(LinkedList *list, ElementProcessor e){
    int index;
    Node *node = list -> first;
    for(index = 0; index < list -> length; index++){
        e(node -> element);
        node = node -> next;
    }
}

void * getElementAt(LinkedList list, int position){
    int index;
    Node *node = list.first;
    for(index = 0; index < position; index++){
        node = node -> next;
    }
    return node -> element;
}

int indexOf(LinkedList list, void *element){
    int index;
    Node *node = list.first;
    for(index = 0; index < list.length; index++){
        if(node -> element == element)
            return index;
        node = node -> next;
    }
    return -1;
}

void * deleteElementAt(LinkedList *list, int position){
    int index;
    void *deleted_element;
    Node *node;
    Node *previous_node;
    Node *next_node;
    node = list -> first;
    for(index = 0; index < position; index++){
        node = node -> next;
    }
    deleted_element = node -> element;
    previous_node = (Node *)node -> previous;
    next_node = (Node *)node -> next;

    if(node == list -> first){
        list -> first = next_node;
        next_node -> previous = NULL;
    }
    else if(node == list -> last){
        list -> last = previous_node;
        previous_node -> next = NULL;
    }
    else{
        previous_node -> next = node -> next;
        next_node -> previous = node -> previous;
    }
    list -> length--;
    free(node);
    return deleted_element;
}

int asArray(LinkedList list, void **arr, int maxElements){
    int index, length;
    Node *node = list.first;
    length = list.length < maxElements ? list.length : maxElements;
    for(index = 0; index < length; index++){
        *arr = node -> element;
        arr++;
        node = node -> next;
    }
    return length;
}

LinkedList filter(LinkedList list, MatchFunc match, void *hint){
    int index;
    LinkedList result = createList();
    Node *node = list.first;
    for(index = 0; index < list.length; index++){
        if(match(hint, node -> element))
            add_to_list(&result, node -> element);
        node = node -> next;
    }
    return result;
};

LinkedList reverse(LinkedList list){
    LinkedList result = createList();
    Node *node = list.last;
    for(int index = 0; index < list.length; index++){
        add_to_list(&result, node -> element);
        node = node -> previous;
    }
    return result;
}

LinkedList map(LinkedList list, ConvertFunc convert, void *hint){
    Node *node = list.first;
    LinkedList result = createList();
    for(int index = 0; index < list.length; index++){
        convert(hint, node -> element, node -> element);
        node = node -> next;
    }
    return list;
}

// void * reduce(LinkedList list, Reducer reduce, void *hint, void *initialValue){
//     Node *node = list.first;
//     void *previousItem = initialValue;
//     void *currentItem = node -> element;
//
//     for(int index = 0; index < list.length; index++){
//         previousItem = reduce(hint, previousItem, currentItem);
//         node = node -> next ;
//         currentItem = node -> element;
//     }
//     return previousItem;
// }
