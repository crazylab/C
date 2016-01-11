#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "linkedList.h"

int passed_test = 0;

void test_createList(){
    LinkedList list;
    list = createList();

    assert(NULL == list.last);
    assert(list.first == NULL);
    assert(list.length == 0);

    printf("test_createList\t\tcreats empty LinkedList\n");
    passed_test++;
}

void test_add_to_list(){
    LinkedList list;
    Node *result;
    int number = 50;
    list = createList();
    int length = add_to_list(&list, &number);
    result = (Node *)list.first;
    assert(1 == length);
    assert(1 == list.length);
    assert(&number == result -> element);
    assert(&number == result -> element);

    printf("test_add_to_list\tadds element in the LinkedList\n");
    passed_test++;
}
int main(){
    test_createList();
    test_add_to_list();

    return 0;
}
