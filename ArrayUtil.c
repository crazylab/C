#include <assert.h>
#include "ArrayUtil.h"

void test_int_create(){
    ArrayUtil array;
    int *numbers;
    array = create(4, 10);
    assert(array.length == 10);
    assert(array.typeSize == 4);

    numbers = (int *)array.base;
    assert(numbers[0] == 0);
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
}
int main(void) {
    test_int_create();
    test_resize();
    return 0;
}
