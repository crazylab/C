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

int areEqual(ArrayUtil first, ArrayUtil second){
    int index;
    char *first_char = (char *)first.base;
    char *second_char = (char *)second.base;
    if(first.length != second.length || first.typeSize != second.typeSize)
        return 0;
    for(index = 0; index < first.length; index++){
        if(first_char[index] != second_char[index])
            return 0;
    }
    return 1;
}
void dispose(ArrayUtil array){
    free(array.base);
}

void pushString(ArrayUtil array){
    char *charecters = (char *)array.base;
    int index;
    for(index = 0; index < array.length; index++)
        charecters[index] = 65 + index;
}
