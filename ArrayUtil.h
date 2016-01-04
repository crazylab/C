typedef struct arrayUtil{
    void *base;
    int typeSize;
    int length;
} ArrayUtil;

ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil array, int length);
