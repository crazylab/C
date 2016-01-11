typedef struct linkedList{
    void *first;
    void *last;
    int length;
}LinkedList;

typedef struct node{
    void *element;
    void *previous;
    void *next;
}Node;

LinkedList createList(void);
int add_to_list(LinkedList *, void *);
