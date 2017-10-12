/*
    common.h
*/

#ifndef TESTS_COMMON_H
#define TESTS_COMMON_H

#define PRINT_SUCCESS() fprintf(stdout, "%s ...SUCCESS\n", __PRETTY_FUNCTION__)

static int greater_than(const void *data1, const void *data2) {
    if (*(const int *)data1 > *(const int *)data2)
        return 0;
    else
        return -1;
}

static int less_than(const void *data1, const void *data2) {
    if (*(const int *)data1 < *(const int *)data2)
        return 0;
    else
        return -1;
}

#endif