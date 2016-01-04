#include "ArrayUtil.h"
#include "stdlib.h"

ArrayUtil create(int typeSize, int length){
    ArrayUtil result_array;

    result_array.base = calloc(length, typeSize);
    result_array.typeSize = typeSize;
    result_array.length = length;

    return result_array;
}
