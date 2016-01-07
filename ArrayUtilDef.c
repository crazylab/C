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
    void *item = array.base;
    void *end = array.base + (array.length * array.typeSize);
    for( ; item != end; ){
        if(match(hint, item))
            return item;
        item += array.typeSize;
    }
    return NULL;
}

void * findLast(ArrayUtil array, MatchFunc match, void* hint){
    void *item = array.base + (array.length * array.typeSize);
    for( ; item != array.base; ){
        item -= array.typeSize;
        if(match(hint, item))
            return item;
    }
    return NULL;
}

int count(ArrayUtil array, MatchFunc *match, void *hint){
    int count = 0;
    void *item = array.base;
    void *end = array.base + (array.length * array.typeSize);
    for( ; item != end; ){
        if(match(hint, item))
            count++;
        item += array.typeSize;
    }
    return count;
}
int filter(ArrayUtil array, MatchFunc* match, void* hint, void** destination, int maxItems){
    int index, count = 0;
    void *item = array.base;
    void *end = array.base + (array.length * array.typeSize);

    for( ; item != end; ){
        if(match(hint, item) && count < maxItems){
            destination[count] = item;
            count++;
        }
        item += array.typeSize;
    }
    return count;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
    void *sourceItem = source.base;
    void *end = source.base + (source.length * source.typeSize);
    void *destinationItem = destination.base;

    for( ; sourceItem != end; ){
        convert(hint, sourceItem, destinationItem);
        sourceItem += source.typeSize;
        destinationItem += source.typeSize;
    }
};

void forEach(ArrayUtil source, OperationFunc* doOperation, void* hint){
    void *sourceItem = source.base;
    void *end = source.base + (source.length * source.typeSize);

    for( ; sourceItem != end; ){
        doOperation(hint, sourceItem);
        sourceItem += source.typeSize;
    }
}

void* reduce(ArrayUtil array, ReducerFunc* reducer, void* hint, void* initialValue){
    void *previousItem = initialValue;
    void *currentItem = array.base;
    void *end = array.base + (array.length * array.typeSize);

    for( ; currentItem != end; ){
        previousItem = reducer(hint, previousItem, currentItem);
        currentItem += array.typeSize;
    }
    return previousItem;
}

void pushValue(ArrayUtil array, int start){
    char *charecters = (char *)array.base;
    int index;
    for(index = 0; index < array.length; index++)
        charecters[index] = start + index;
}
