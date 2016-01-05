#include "ArrayUtil.h"
#include "stdlib.h"
#include <string.h>
#include <stdio.h>
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
    int compare_result, size;
    if(first.length != second.length || first.typeSize != second.typeSize)
        return 0;
    size = first.typeSize * first.length;
    compare_result = memcmp(first.base, second.base, size);
    return !compare_result;
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

void * findFirst(ArrayUtil array, MatchFunc match, void* hint){
    int index;
    int *items = array.base;
    for(index = 0; index < array.length; index++){
        if(match(hint, &items[index]) == 1){
            return &items[index];
        }
    }
    return NULL;
}

void * findLast(ArrayUtil array, MatchFunc match, void* hint){
    int index;
    int *items = array.base;
    for(index = array.length - 1; index != 0; index--){
        if(match(hint, &items[index]) == 1){
            return &items[index];
        }
    }
    return NULL;
}

void pushValue(ArrayUtil array, int start){
    char *charecters = (char *)array.base;
    int index;
    for(index = 0; index < array.length; index++)
        charecters[index] = start + index;
}
