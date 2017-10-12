/*
    sort.h
*/

#ifndef SORT_H
#define SORT_H

int isort_list(void *data, int (*compare)(const void *key1, const void *key2));
int qsort_list(void *data, int (*compare)(const void *key1, const void *key2));

#endif