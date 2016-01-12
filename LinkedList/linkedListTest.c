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

void test_get_first_element(){
    LinkedList list;
    int number1 = 50, number2 = 100;
    list = createList();
    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    assert(2 == list.length);

    void *element = get_first_element(list);
    assert(&number1 == element);

    printf("test_get_first_element\tgives the first element address in the list\n");
    passed_test++;
}

void test_get_last_element(){
    LinkedList list;
    int number1 = 50, number2 = 100;
    list = createList();
    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    assert(2 == list.length);

    void *element = get_last_element(list);
    assert(&number2 == element);

    printf("test_get_last_element\tgives the last element address in the list\n");
    passed_test++;
}

void increment(void *value) {
    int *number = (int *)value;
    *number += 1;
}
void test_forEach(){
    LinkedList list;
    int number1 = 50, number2 = 100, number3 = 150, number4 = 200, number5 = 250;
    list = createList();
    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    add_to_list(&list, &number3);
    add_to_list(&list, &number4);
    add_to_list(&list, &number5);

    assert(5 == list.length);

    forEach(&list, &increment);
    int *first_element = (int *)get_first_element(list);
    int *last_element = (int *)get_last_element(list);

    assert(51 == *first_element);
    assert(251 == *last_element);

    printf("test_forEach\toperates over each element in the list\n");
    passed_test++;
}

int main(){
    test_createList();
    test_add_to_list();
    test_get_first_element();
    test_get_last_element();
    test_forEach();

    return 0;
}
