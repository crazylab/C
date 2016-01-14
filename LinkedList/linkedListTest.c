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

    printf("test_forEach\t\toperates over each element in the list\n");
    passed_test++;
}

void test_getElementAt(){
    LinkedList list;
    int number1 = 50, number2 = 100, number3 = 150, number4 = 200, number5 = 250;
    list = createList();
    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    add_to_list(&list, &number3);
    add_to_list(&list, &number4);
    add_to_list(&list, &number5);

    assert(5 == list.length);
    void *element = getElementAt(list, 3);
    assert(&number4 == element);

    printf("test_getElementAt\tgives the element reference at the specified position\n");
    passed_test++;
}

void test_indexOf(){
    LinkedList list;
    int number = 0, number1 = 50, number2 = 100, number3 = 150, number4 = 200, number5 = 250;
    list = createList();
    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    add_to_list(&list, &number3);
    add_to_list(&list, &number4);
    add_to_list(&list, &number5);

    assert(5 == list.length);
    assert(indexOf(list, &number3) == 2);
    assert(indexOf(list, &number) == -1);

    printf("test_indexOf\t\tgives the first index at which this element occurs in a list.\n");
    passed_test++;
}

void test_deleteElementAt(){
    LinkedList list;
    int number1 = 50, number2 = 100, number3 = 150, number4 = 200, number5 = 250, number = 0;
    list = createList();
    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    add_to_list(&list, &number3);
    add_to_list(&list, &number4);
    add_to_list(&list, &number5);

    assert(5 == list.length);
    assert(deleteElementAt(&list, 3) == &number4);
    assert(getElementAt(list, 3) == &number5);

    assert(deleteElementAt(&list, 0) == &number1);
    assert(getElementAt(list, 0) == &number2);
    assert(list.first -> element == &number2);

    assert(deleteElementAt(&list, 2) == &number5);
    assert(list.last -> element == &number3);
    // assert(getElementAt(list, 2) == NULL);

    printf("test_deleteElementAt\tdeletes the element at that list. Returns the data referenced by the node at that position.\n");
    passed_test++;
}

void test_asArray(){
    LinkedList list;
    int number1 = 50, number2 = 100, number3 = 150, number4 = 200, number5 = 250, number = 0;
    list = createList();
    int *arr[10], maxElements = 10;
    void **arr_ptr = (void **)&arr[0];

    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    add_to_list(&list, &number3);
    add_to_list(&list, &number4);
    add_to_list(&list, &number5);

    assert(5 == list.length);
    assert(5 == asArray(list, arr_ptr, maxElements));

    assert(arr[0] == &number1);
    assert(arr[1] == &number2);
    assert(arr[2] == &number3);
    assert(arr[3] == &number4);
    assert(arr[4] == &number5);

    printf("test_asArray\t\tpopulates an array with all the element in the list\n");
    passed_test++;
}

int divisible_by(void* hint, void* item){
    int *numerator = (int *)item;
    int *denomenator = (int *)hint;
    return !(*numerator % *denomenator);
};

void test_filter(){
    LinkedList list, result;
    int number1 = 50, number2 = 100, number3 = 150, number4 = 200, number5 = 250, number = 0;
    list = createList();
    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    add_to_list(&list, &number3);
    add_to_list(&list, &number4);
    add_to_list(&list, &number5);

    assert(5 == list.length);
    int hint = 100;
    result = filter(list, &divisible_by, &hint);
    assert(2 == result.length);
    assert(&number2 == result.first -> element);
    assert(&number4 == result.last -> element);

    printf("test_filter\t\tfilteres element from the list\n");
    passed_test++;
}

void test_reverse(){
    LinkedList list, result;
    int number1 = 50, number2 = 100, number3 = 150, number4 = 200, number5 = 250;
    list = createList();
    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    add_to_list(&list, &number3);
    add_to_list(&list, &number4);
    add_to_list(&list, &number5);

    assert(5 == list.length);
    result = reverse(list);
    assert(5 == result.length);
    assert(&number5 == result.first -> element);
    assert(&number4 == result.first -> next -> element);
    assert(&number3 == result.first -> next -> next -> element);
    assert(&number2 == result.first -> next -> next -> next -> element);
    assert(&number1 == result.first -> next -> next -> next -> next -> element);
    assert(&number1 == result.last -> element);

    printf("test_reverse\t\tgives the reverse of the given list\n");
    passed_test++;
}

void subtract(void* hint, void* sourceItem, void *destinationItem){
    int *subtractor = (int *)hint;
    int *number2 = (int *)sourceItem;
    int *dest_data = (int *)destinationItem;
    int result = (*number2) - (*subtractor);
    *dest_data = result;
}

void test_map(){
    LinkedList list, result;
    int number1 = 50, number2 = 100, number3 = 150, number4 = 200, number5 = 250;
    list = createList();
    add_to_list(&list, &number1);
    add_to_list(&list, &number2);
    add_to_list(&list, &number3);
    add_to_list(&list, &number4);
    add_to_list(&list, &number5);
    assert(5 == list.length);

    int hint = 50;
    result = map(list, &subtract, &hint);
    assert(5 == result.length);

    assert(0 == *(int *)result.first -> element);
    assert(200 == *(int *)result.last -> element);

    printf("test_map\t\toperates over each element of the list\n");
    passed_test++;
}

void* find_sum(void* hint, void* previousItem, void* item){
    int *item_ptr = (int *)item;
    int *previousItem_ptr = (int *)previousItem;
    *previousItem_ptr = (*previousItem_ptr) + (*item_ptr);
    return previousItem;
}

// void test_reduce(){
//     LinkedList list;
//     int number1 = 50, number2 = 100, number3 = 150, number4 = 200, number5 = 250;
//     list = createList();
//     add_to_list(&list, &number1);
//     add_to_list(&list, &number2);
//     add_to_list(&list, &number3);
//     add_to_list(&list, &number4);
//     add_to_list(&list, &number5);
//     assert(5 == list.length);
//
//     int initial = 0;
//     int *sum = (int *)reduce(list, &find_sum, NULL, &initial);
//     assert(750 == *sum);
//
//     printf("test_reduce\t\treduces the list by considering each element in the list\n");
//     passed_test++;
// }

int main(){
    test_createList();
    test_add_to_list();
    test_get_first_element();
    test_get_last_element();
    test_forEach();
    test_getElementAt();
    test_indexOf();
    test_deleteElementAt();
    test_asArray();
    test_filter();
    test_reverse();
    test_map();
    // test_reduce();

    return 0;
}
