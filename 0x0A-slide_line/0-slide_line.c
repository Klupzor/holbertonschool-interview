#include "slide_line.h"

/**
 * find_partner - merges array int
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
void find_partner(int *line, size_t size)
{
	size_t left, right;

	for (right = 1, left = 0; right < size; right++, left++)
	{
		if (line[left] == line[right])
		{
			line[left] = line[left] * 2;
			line[right] = 0;
		}
	}
}

/**
 * slide_left - slides and merges to left an array of integers
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * Return: SUCCESS 1 or FAILURE 0
 */

int slide_left(int *line, size_t size)
{
	size_t left, right;

	left = 0;
	while (line[left] != 0)
	{
		if (left >= size)
			return (1);
		left++;
	}

	for (right = left + 1; right < size; right++)
	{
		if (line[right] != 0)
		{
			line[left] = line[right];
			line[right] = 0;
			while (line[left] != 0)
			{
				if (left >= size)
					return (1);
				left++;
			}
			right = left;
		}
	}
	return (1);
}

/**
 * slide_right - slides and merges to right an array of integers
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * Return: SUCCESS 1 or FAILURE 0
 */

int slide_right(int *line, size_t size)
{
	size_t left, right;

	right = size - 1;
	while (line[right] != 0)
	{
		if (right == 0)
			return (1);
		right--;
	}
	for (left = right; left > 0; left--)
	{
		if (line[left - 1] != 0)
		{
			line[right] = line[left - 1];
			line[left - 1] = 0;
			while (line[right] != 0)
			{
				if (right == 0)
					return (1);
				right--;
			}
			left = right + 1;
		}
	}
	return (1);
}

/**
 * slide_line - slides and merges an array of integers
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * @direction: left(1) or right(2)
 * Return: SUCCESS 1 or FAILURE 0
 */

int slide_line(int *line, size_t size, int direction)
{

	if (direction == 1)
	{
		slide_left(line, size);
		find_partner(line, size);
		slide_left(line, size);
		return (1);
	}

	if (direction == 2)
	{
		slide_right(line, size);
		find_partner(line, size);
		slide_right(line, size);
		return (1);
	}

	return (0);
}
