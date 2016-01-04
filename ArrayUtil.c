#include <stdio.h>
#include <assert.h>
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
    array = create(1, 10);
    assert(array.length == 10);
    assert(array.typeSize == 1);

    array = resize(array, 15);
    assert(array.length == 15);

    array = resize(array, 12);
    assert(array.length == 12);

    printf("test_resize\tresized array to the given size\n");
    passed_test++;
}
void test_areEqual() {
    ArrayUtil array1, array2;
    char *charecters;
    array1 = create(1, 10);
    array2 = create(1, 10);

    assert(areEqual(array1, array2) == 1);
    charecters = (char *)array1.base;
    charecters[5] = 'a';
    assert(areEqual(array1, array2) == 0);

    printf("test_areEqual\tchecked whether 2 array's are same or not\n");
    passed_test++;
}
int main(void) {
    test_create();
    test_resize();
    test_areEqual();

    printf("\n%d tests are passed\n", passed_test);
    return 0;
}
