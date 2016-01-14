typedef void (*ElementProcessor)(void *);
typedef int (MatchFunc)(void *, void *);
typedef void (ConvertFunc)(void *, void *, void *);
typedef void *(Reducer)(void *, void *, void *);

typedef struct node{
    void *element;
    struct node *previous;
    struct node *next;
}Node;

typedef struct linkedList{
    Node *first;
    Node *last;
    int length;
}LinkedList;

LinkedList createList(void);
int add_to_list(LinkedList *, void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList *, ElementProcessor e);
void * getElementAt(LinkedList, int );
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int maxElements);
LinkedList filter(LinkedList, MatchFunc, void * );
LinkedList reverse(LinkedList);
LinkedList map(LinkedList, ConvertFunc, void * );
void * reduce(LinkedList, Reducer, void *hint, void *initialValue);
