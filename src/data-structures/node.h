/* 
    node.h 
    Data structure of a singly linked list node.
*/

#ifndef NODE_H
#define NODE_H

typedef struct Node_ {
    void *data;
    struct Node_ *next;
} Node;

#endif