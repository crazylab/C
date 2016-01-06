#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "ArrayUtil.h"

int passed_test = 0;

void test_create(){
    ArrayUtil array;
    int *numbers;
    array = create(4, 10);
    assert(array.length == 10);
    assert(array.typeSize == 4);

    numbers = (int *)array.base;
    assert(numbers[0] == 0);

    printf("test_create\tcreated array of given size\n");
    passed_test++;
}
void test_resize() {
    ArrayUtil array;
    char *charecters;

    array = create(1, 5);
    assert(array.length == 5);
    assert(array.typeSize == 1);

    pushValue(array, 65);
    charecters = (char *)array.base;
    assert(strcmp(charecters, "ABCDE") == 0);

    array = resize(array, 7);
    assert(array.length == 7);
    charecters = (char *)array.base;
    charecters[5] = 'K';
    assert(strcmp(charecters, "ABCDEK") == 0);

    array = resize(array, 3);
    assert(array.length == 3);
    charecters = (char *)array.base;
    charecters[2] = '\0';
    assert(strcmp(charecters, "AB") == 0);

    printf("test_resize\tresized array to the given size\n");
    passed_test++;
}
void test_areEqual() {
    ArrayUtil array1, array2;
    char *charecters;
    array1 = create(1, 10);
    array2 = create(1, 10);

    pushValue(array1, 65);
    pushValue(array2, 65);

    assert(areEqual(array1, array2) == 1);
    charecters = (char *)array1.base;
    charecters[5] = 'a';
    assert(areEqual(array1, array2) == 0);

    printf("test_areEqual\tchecked whether 2 array's are same or not\n");
    passed_test++;
}
void test_dispose() {
    ArrayUtil array;
    array = create(1, 10);
    dispose(array);

    printf("test_dispose\tdisposed the allocated memory. *No assert is here*\n");
    passed_test++;
}
void test_findIndex() {
    ArrayUtil array;
    int element = 259;
    array = create(1, 8);
    pushValue(array, 255);
    assert(findIndex(array, &element) == 4);
    element = 6000;
    assert(findIndex(array, &element) == -1);

    printf("test_findIndex\t finds the index of a number if present or gives -1\n");
    passed_test++;
}

int isEven(void *hint, void *item){
    int *number = (int *)item;
    return !(*number % 2);
}
int isDivisible(void* hint, void* item){
    int *numerator = (int *)item;
    int *denomenator = (int *)hint;
    return !(*numerator % *denomenator);
}

void test_findFirst(){
    ArrayUtil array = create(4,5);
    int *numbers = (int *)(array.base);

    numbers[0] = 1;
    numbers[1] = 3;
    numbers[2] = 6;
    numbers[3] = 8;
    numbers[4] = 5;

    void * hint = NULL;
    int * result = (int *)findFirst(array, &isEven, hint);
    assert(*result == 6);

    hint = (void *)&numbers[1];
    result = (int *)findFirst(array, &isDivisible, hint);
    assert(*result == 3);

    printf("test_findFirst\t finds the first element which matches the criteria\n");
    passed_test++;
}

void test_findLast(){
    ArrayUtil array = create(4,5);
    int *numbers = (int *)(array.base);

    numbers[0] = 1;
    numbers[1] = 3;
    numbers[2] = 6;
    numbers[3] = 8;
    numbers[4] = 5;

    void * hint = NULL;
    int * result = (int *)findLast(array, &isEven, hint);
    assert(*result == 8);

    hint = (void *)&numbers[1];
    result = (int *)findLast(array, &isDivisible, hint);
    assert(*result == 6);

    printf("test_findLast\t finds the last element which matches the criteria\n");
    passed_test++;
}

void test_count(){
    ArrayUtil array = create(4,5);
    int *numbers = (int *)(array.base);

    numbers[0] = 1;
    numbers[1] = 3;
    numbers[2] = 6;
    numbers[3] = 8;
    numbers[4] = 5;

    void * hint = NULL;
    assert(count(array, &isEven, hint) == 2);

    hint = (void *)&numbers[0];
    assert(count(array, &isDivisible, hint) == 5);

    printf("test_findLast\t number of matched criteria\n");
    passed_test++;
}
void test_filter(){
    ArrayUtil array = create(4,5);
    int *numbers = (int *)(array.base);
    int destination[5];
    void *dest_ptr = &destination;
    numbers[0] = 1;
    numbers[1] = 3;
    numbers[2] = 6;
    numbers[3] = 8;
    numbers[4] = 5;

    void * hint = NULL;
    int count = filter(array, &isEven, hint, &dest_ptr, 5);
    assert(count == 2);

    int *dest = (int *)dest_ptr;
    assert(*dest == 6);
    assert(*(dest+1) == 8);

    printf("test_filter\t gives an array of pointers which are matched\n");
    passed_test++;
}

int main(void) {
    test_create();
    test_resize();
    test_areEqual();
    test_dispose();
    test_findIndex();
    test_findFirst();
    test_findLast();
    test_count();
    test_filter();

    printf("\n%d tests are passed\n", passed_test);
    return 0;
}
