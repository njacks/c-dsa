/*
    stack.c
    Implementations of a LIFO stack data structure.
*/

#include <stdlib.h>

#include "./data-structures/list.h"
#include "./data-structures/stack.h"

/*
    stack_push
    
    Adds a node to the top of the stack. 
*/
int stack_push(Stack *stack, const void *data) {
    return list_ins_next(stack, NULL, data);
}

/*
    stack_pop
    
    Removes a node from the top of the stack. 
*/
int stack_pop(Stack *stack, void **data) {
    return list_rem_next(stack, NULL, data);
}