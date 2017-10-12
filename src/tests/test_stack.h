/*
    test_stack.c
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "../data-structures/stack.h"
#include "common.h"

void test_stack_implementation() {
    Stack stack;
    stack_init(&stack, free);
    int *data, i; 
    
    assert(stack_size(&stack) == 0);
    assert(list_head(&stack) == NULL);
    assert(list_tail(&stack) == NULL);

    /* Push 6 nodes onto stack */
    for (i = 0; i < 7; i++) {
        assert((data = (int *)malloc(sizeof(int))) != NULL);
        *data = i;
        assert(stack_push(&stack, data) == 0);
    }
    
    assert(stack_peek(&stack) != NULL);
    
    /* Pop all nodes off stack */
    while ((list_head(&stack) != NULL) && (stack_size(&stack) > 0)) {
       assert(stack_pop(&stack, (void **)&data) == 0);
    }
    
    assert(stack_peek(&stack) == NULL);
    
    stack_destroy(&stack);
    PRINT_SUCCESS();
    return;
}