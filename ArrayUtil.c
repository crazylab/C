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

int main(void) {
    test_int_create();
    test_resize();
    return 0;
}
