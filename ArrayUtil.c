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
int main(void) {
    test_create();
    test_resize();
    test_areEqual();
    test_dispose();
    test_findIndex();

    printf("\n%d tests are passed\n", passed_test);
    return 0;
}
