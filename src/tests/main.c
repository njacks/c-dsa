/*
    main.c
    Test application for data structures and algorithms
*/

#include <stdio.h>
#include "tests.h"

int main(int argc, char *argv[]) {
    test_list_implementation();
    test_queue_implementation();
    test_stack_implementation();
    test_isort_list_implementation();
    test_qsort_list_implementation();
    return 0;
}
