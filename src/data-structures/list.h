/*
    list.h 
    Data strucutre of a singly linked list.
*/

#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct List_ {
    int size;
    
    void (*destroy)(void *data);
    
    Node *head;
    Node *tail;
} List;

void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, Node *node, const void *data);
int list_rem_next(List *list, Node *node, void **data);
int list_reverse(List *list);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, node) ((node) == (list)->head ? 1 : 0)
#define list_is_tail(node) ((node)->next == NULL ? 1 : 0)
#define list_data(node) ((node)->data)
#define list_next(node) ((node)->next)

#endif
