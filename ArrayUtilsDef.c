#include "ArrayUtil.h"
#include "stdlib.h"
#include <string.h>

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

int findIndex(ArrayUtil array, void *element){
    int index, inner_index;
    char *array_element = (char *)array.base;

    for(index = 0; index < array.length; index++){
        if(memcmp(array.base, element, array.typeSize) == 0)
            return index;
        array.base += array.typeSize;
    }
    return -1;
}

void pushValue(ArrayUtil array, int start){
    char *charecters = (char *)array.base;
    int index;
    for(index = 0; index < array.length; index++)
        charecters[index] = start + index;
}
