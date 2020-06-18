#include "sort.h"

/**
 * swap - swaps integers
 * @x: first int
 * @y: second int
 */
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * heapify - convert array into heap
 * @a: array
 * @n: size of heap
 * @root: root index
 * @size: size of array
 */
void heapify(int *a, int n, int root, size_t size)
{
	int max = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < n && a[left] > a[max])
		max = left;

	if (right < n && a[right] > a[max])
		max = right;

	if (max != root)
	{
		swap(&a[root], &a[max]);
		print_array(a, size);
		heapify(a, n, max, size);
	}
}

/**
 * heap_sort - Heap sort algorithm
 * @array: array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0, size);
	}
}
