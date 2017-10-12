/*
    test_isort_list.c
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../data-structures/list.h"
#include "../algorithms/sort.h"
#include "common.h"


void test_isort_list_implementation() {
    List list;
    list_init(&list, free);
    int *data, i;
    
    srand( time(NULL) );
    
    for (i = 0; i < 20; i++) {
        assert((data = (int *)malloc(sizeof(int))) != NULL);
        *data = rand() % 1000;
        assert(list_ins_next(&list, list_tail(&list), data) == 0);
    }
    
   assert(isort_list(&list, greater_than) == 0);
   assert(isort_list(&list, less_than) == 0);

    list_destroy(&list);
    PRINT_SUCCESS();
    return;
}