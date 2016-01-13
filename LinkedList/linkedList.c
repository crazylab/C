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
    Node *node = list -> first;
    for(index = 0; index < position; index++){
        node = node -> next;
    }
    deleted_element = node -> element;
    Node *previous_node = (Node *)node -> previous;
    Node *next_node = (Node *)node -> next;
    next_node -> previous = node -> previous;
    previous_node -> next = node -> next;
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
