/* 
    list.c
    Implementations of a singly linked list data strcutre.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./data-structures/list.h"

/*
    list_init
    
    Initializies a linked list. 
    Sets size to 0, sets destroy member, sets head and tail pointers to NULL.
*/
void list_init(List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
    return;
}

/*
    list_destroy
    
    Destroys a linked list, removes all nodes from the list.
    Uses the destroy function set in list_init.
*/
void list_destroy(List *list) {
    void *data;
    while ((list_size(list) > 0) && (list_head(list) != NULL)) {
        if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }
    /* The next line falsely assumes a NULL pointer value is represesnted by all zeroes. */
    memset(list, 0, sizeof(List));
    return;
}

/*
    list_ins_next
    
    Inserts a node into a linked list after a specified node.
*/
int list_ins_next(List *list, Node *node, const void *data) {
    Node *new_node;

    if ((new_node = (Node *)malloc(sizeof(Node))) == NULL) {
        return -1;
    }
    new_node->data = (void *)data;

    /* Insert at head */
    if (node == NULL) {
        if (list_size(list) == 0) {
            list->tail = new_node;
        }
        new_node->next = list->head;
        list->head = new_node;
    }
    /* Insert elsewhere */
    else {
        if (node->next == NULL) {
            list->tail = new_node;
        }
        new_node->next = node->next;
        node->next = new_node;
    }
    
    list->size++;
    return 0;
}

/*
    list_rem_next
    
    Removes a node from a linked list after a specified node.
*/
int list_rem_next(List *list, Node *node, void **data) {
    Node *old_node;
    
    if (list_size(list) == 0) {
        return -1;
    }
    
    /* Remove from head */
    if (node == NULL) {
        *data = list->head->data;
        old_node = list->head;
        list->head = list->head->next;
        
        if (list_size(list) == 1) {
            list->tail = NULL;
        }
    }
    /* Remove elsewhere */
    else {
        if (node->next == NULL) {
            return -1;
        }
        *data = node->next->data;
        old_node = node->next;
        node->next = node->next->next;
        
        if (node->next == NULL) {
            list->tail = node;
        }
    }
    
    free(old_node);
    list->size--;
    return 0;
}

/* 
    list_reverse

    Reverses the order of a linked list and then updates head and tail pointers.
*/
int list_reverse(List *list) {

    if (list->size < 2) {
        return 0;
    }
    
    Node *current = list->head;
    Node *next = NULL;
    Node *previous = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    list->tail = list->head;
    list->head = previous;
    return 0;
}

/*
    list_display
    
    Displays a linked list in the console.
*/
void list_display(List *list) {
    Node *current = list->head;
    int *data, i;
    i = 0;

    while (1) {
        
        if ((list->size == 0) && (list->head == NULL)) {
            fprintf(stdout, "List empty!");
            break;
        }
        
        data = list_data(current);
        if (data == NULL) {
            fprintf(stdout, "NULL --> ");
        }
        else {
            fprintf(stdout, "%03d --> ", *data);
        }

        i++;

        if (list_is_tail(current))
            break;
        else
            current = list_next(current);
    }
    fprintf(stdout, "\nLength: %d\n", list_size(list));
    if ((list->size > 0) && (list->head != NULL)) {
        if (list->head->data != NULL) {
            fprintf(stdout, "Head: %03d\n", *((int *)list->head->data));
            fprintf(stdout, "Tail: %03d\n", *((int *)list->tail->data));
        }
    }
    fprintf(stdout, "\n");
}
