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
    int number1 = 50, number2 = 100;
    list = createList();
    int length = add_to_list(&list, &number1);

    assert(1 == length);
    assert(1 == list.length);

    assert(&number1 == list.first -> element);
    assert(NULL == list.first -> previous);
    assert(NULL == list.first -> next);

    assert(&number1 == list.last -> element);
    assert(NULL == list.last -> previous);
    assert(NULL == list.last -> next);

    length = add_to_list(&list, &number2);
    assert(2 == length);
    assert(2 == list.length);

    assert(&number1 == list.first -> element);
    assert(NULL == list.first -> previous);
    assert(NULL != list.first -> next);

    assert(&number2 == list.last -> element);
    assert(NULL != list.last -> previous);
    assert(NULL == list.last -> next);

    printf("test_add_to_list\tadds element in the LinkedList\n");
    passed_test++;
}
int main(){
    test_createList();
    test_add_to_list();

    return 0;
}
