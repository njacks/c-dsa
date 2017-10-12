/*
    test_list.c
*/

#include <assert.h>
#include <stdlib.h>

#include "../data-structures/list.h"
#include "common.h"

void test_list_implementation() {
    List list;
    list_init(&list, free);
    int *data, i;
    
    assert(list_size(&list) == 0);
    assert(list_head(&list) == NULL);
    assert(list_tail(&list) == NULL);
    
    /* Append 3 nodes to list */
    for (i = 0; i < 3; i++) {
        assert((data = (int *)malloc(sizeof(int))) != NULL);
        *data = i;
        assert(list_ins_next(&list, list_tail(&list), data) == 0);
    }
    
    /* Prepend 3 nodes to list */
    for (i = 7; i < 10; i++) {
        assert((data = (int *)malloc(sizeof(int))) != NULL);
        *data = i;
        assert(list_ins_next(&list, NULL, data) == 0);
    }
    
    assert(list_reverse(&list) == 0);
    
    /* Remove all nodes from head of list */
    while ((list_head(&list) != NULL) && (list_size(&list) > 0)) {
        assert(list_rem_next(&list, NULL, (void **)&data) == 0);
    }
    
    list_destroy(&list);
    PRINT_SUCCESS();
    return;
}