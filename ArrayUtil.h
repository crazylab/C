typedef int (MatchFunc)(void *, void *);
typedef void (ConvertFunc)(void *, void *, void *);
typedef void (OperationFunc)(void *, void *);
typedef void *(ReducerFunc)(void *, void *, void *);

typedef struct arrayUtil{
    void *base;
    int typeSize;
    int length;
} ArrayUtil;

ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil array, int length);
int areEqual(ArrayUtil first, ArrayUtil second);
void dispose(ArrayUtil array);
int findIndex(ArrayUtil array, void *element);
void * findFirst(ArrayUtil array, MatchFunc *match, void *hint);
void * findLast(ArrayUtil array, MatchFunc *match, void *hint);
int count(ArrayUtil array, MatchFunc *match, void *hint);
int filter(ArrayUtil array, MatchFunc* match, void* hint, void** destination, int maxItems);
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
void forEach(ArrayUtil array, OperationFunc* operation, void* hint);
void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);

void pushValue(ArrayUtil array, int start);
