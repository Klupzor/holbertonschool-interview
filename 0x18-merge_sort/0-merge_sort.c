#include "sort.h"

/**
 * merge - merges array
 * @array: array
 * @s: size of the array
 * @l: left array
 * @r: right array
 **/
void merge(int *array, int *l, int *r, size_t s)
{
	int i = 0, j = 0, k = 0;
	int size_l, size_r;

	size_l = s / 2;
	size_r = s - size_l;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_l);
	printf("[right]: ");
	print_array(r, size_r);

	while (i < size_l && j < size_r)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}

	while (i < size_l)
		array[k++] = l[i++];

	while (j < size_r)
		array[k++] = r[j++];
	printf("[Done]: ");
	print_array(array, s);
}

/**
 * merge_sort - sorts int array
 * @array: array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t m = 0;
	size_t i;
	int l[size / 2];
	int r[size / 2];

	if (size <= 1 || !array)
		return;

	m = size / 2;

	for (i = 0; i < m; i++)
		l[i] = array[i];

	for (i = m; i < size; i++)
		r[i - m] = array[i];

	merge_sort(l, m);
	merge_sort(r, size - m);
	merge(array, l, r, size);
}
