#include "search_algos.h"

/**
 * print_array - Print array in specific range
 * @array: array to print
 * @l: beggin array
 * @r: end array
 */
void print_array(int *array, int l, int r)
{
	int i;

	printf("Searching in array: ");
	for (i = l; i <= r; i++)
	{
		if (i != l)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * binary_search - Find index of value
 * @a: array to search value
 * @l: beggin array (left)
 * @r: end array (rigth)
 * @v: value to search
 * Return: index of value or -1
 */
int binary_search(int *a, int l, int r, int v)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		print_array(a, l, r);
		if (a[mid] == v)
		{
			if (a[mid - 1] == v)
				return (binary_search(a, l, mid, v));

			return (mid);
		}
		if (a[mid] > v)
			return (binary_search(a, l, mid - 1, v));
		return (binary_search(a, mid + 1, r, v));
	}
	return (-1);
}

/**
 * advanced_binary - Call binary search function
 * @array: array to search value
 * @size: array size
 * @value: value to search
 * Return: index of value or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (binary_search(array, 0, size - 1, value));
}
