/*
    stack.h
    Data structure of a LIFO stack using a singly linked list.
*/

#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack, void **data);

#define stack_reverse list_reverse
#define stack_size list_size
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#endif