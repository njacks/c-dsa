/*
    test_queue.c
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "../data-structures/queue.h"
#include "common.h"

void test_queue_implementation() {
    Queue queue;
    queue_init(&queue, free);
    int *data, i; 
    
    assert(queue_size(&queue) == 0);
    assert(list_head(&queue) == NULL);
    assert(list_tail(&queue) == NULL);

    /* Enqueue 6 nodes into queue */
    for (i = 0; i < 7; i++) {
        assert((data = (int *)malloc(sizeof(int))) != NULL);
        *data = i;
        assert(queue_enqueue(&queue, data) == 0);
    }
    
    assert(queue_peek(&queue) != NULL);
    
    /* Dequeue all nodes from queue */
    while ((list_head(&queue) != NULL) && (queue_size(&queue) > 0)) {
       assert(queue_dequeue(&queue, (void **)&data) == 0);
    }
    
    assert(queue_peek(&queue) == NULL);
    
    queue_destroy(&queue);
    PRINT_SUCCESS();
    return;
}