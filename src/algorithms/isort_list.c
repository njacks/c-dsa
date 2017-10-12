/*
    isort_list.c
    Implementation of insertion sort algorithm for singly linked lists.
*/

#include <stdlib.h>

#include "sort.h"
#include "../data-structures/list.h"

/*
    isort_list
    
    Sorts a linked list in an order according to a user supplied compare function.
    Makes use of a trailing pointer.
*/
int isort_list(void *data, int (*compare)(const void *data1, const void *data2)) {

    Node *unsorted = ((List *)data)->head;
    if (!unsorted || !(unsorted->next)) {
        return 0;
    }
    
    Node *sorted = NULL;
    
    while (unsorted != NULL) {
        Node *head = unsorted;
        Node **trail = &sorted;

        unsorted = unsorted->next;
        
        while (!(*trail == NULL || (compare(head->data, (*trail)->data) == 0))) {
            trail = &(*trail)->next;
            if (*trail == NULL) {
                ((List *)data)->tail = head;
            }
        }

        head->next = *trail;
        *trail = head;
    }
    
    ((List *)data)->head = sorted;
    return 0;
}