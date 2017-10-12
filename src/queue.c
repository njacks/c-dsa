/*
    queue.c
    Implementations of a FIFO queue data structure.
*/

#include <stdlib.h>

#include "./data-structures/list.h"
#include "./data-structures/queue.h"

/*
    queue_enqueue
    
    Adds a node to the end of the queue. 
*/
int queue_enqueue(Queue *queue, const void *data) {
    return list_ins_next(queue, list_tail(queue), data);
}

/*
    queue_dequeue
    
    Removes a node from the front of the queue. 
*/
int queue_dequeue(Queue *queue, void **data) {
    return list_rem_next(queue, NULL, data);
}