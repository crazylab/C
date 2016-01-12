typedef void (*ElementProcessor)(void *);
typedef struct node{
    void *element;
    void *previous;
    void *next;
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
