typedef int (MatchFunc)(void *, void *);

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

void pushValue(ArrayUtil array, int start);
