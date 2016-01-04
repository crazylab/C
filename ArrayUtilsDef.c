#include "ArrayUtil.h"
#include "stdlib.h"

ArrayUtil create(int typeSize, int length){
    ArrayUtil result_array;

    result_array.base = calloc(length, typeSize);
    result_array.typeSize = typeSize;
    result_array.length = length;

    return result_array;
}

ArrayUtil resize(ArrayUtil array, int length){
    int size_needed = (length * array.typeSize);
    array.base = realloc(array.base, size_needed);
    array.length = length;
    return array;
}
