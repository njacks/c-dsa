/*
    qsort_list.c
    Implementation of quick sort algorithm for singly linked lists.
*/

#include <stdlib.h>

#include "sort.h"
#include "../data-structures/list.h"

/*
    get_list_tail
    
    Returns a pointer to the last node of a linked list given another node.
*/
Node *get_tail(Node *current) {
    while (current != NULL && current->next != NULL)
        current = current->next;
    return current;
}

/*
    list_partition
    
    Partitions a list of nodes using the last node as a pivot.
*/
Node *list_partition(Node *head, Node *tail, Node **new_head, Node **new_tail,
    int (*compare)(const void *data1, const void *data2)) {
    
    Node *pivot = tail;
    Node *previous = NULL;
    Node *current = head;
    Node *end = pivot;
    
    while (current != pivot) {
        if (compare(current->data, pivot->data) == 0) {
            if (*new_head == NULL) {
                *new_head = current;
            }
            previous = current;
            current = current->next;
        }
        else {
            if (previous != NULL) {
                previous->next = current->next;
            }
            Node *temp = current->next;
            current->next = NULL;
            end->next = current;
            end = current;
            current = temp;
        }
    }
    
    if (*new_head == NULL) {
        *new_head = pivot;
    }
    
    *new_tail = end;
    
    return pivot;
}

/*
    qsort_list_recursive
*/
Node *qsort_list_recursive(Node *head, Node *tail, 
    int (*compare)(const void *data1, const void *data2)) {
    
    if (!head || head == tail) {
        return head;
    }
    
    Node *new_head = NULL;
    Node *new_tail = NULL;
    
    Node *pivot = list_partition(head, tail, &new_head, &new_tail, compare);
    
    if (new_head != pivot) {
        Node *temp = new_head;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = NULL;
        
        new_head = qsort_list_recursive(new_head, temp, compare);
        
        temp = get_tail(new_head);
        temp->next = pivot;
    }
    
    pivot->next = qsort_list_recursive(pivot->next, new_tail, compare);
    
    return new_head;
}

/*
    qsort_list
    
    Sorts a linked list in an order according to a user supplied compare function.
    Makes use of a trailing pointer.
*/
int qsort_list(void *data, int (*compare)(const void *data1, const void *data2)) {

    Node *head = ((List *)data)->head;
    if (!head || !(head->next)) {
        return 0;
    }
    
    Node *tail = ((List *)data)->tail;

    ((List *)data)->head = qsort_list_recursive(head, tail, compare);
    
    ((List *)data)->tail = get_tail(((List *)data)->head);
    
    return 0;
}