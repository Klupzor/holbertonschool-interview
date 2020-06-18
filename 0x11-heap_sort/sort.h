#ifndef HEAPSORT
#define HEAPSORT

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *arr, int n, int i, size_t size);
void swap(int *a, int *b);

#endif /* HEAPSORT */
