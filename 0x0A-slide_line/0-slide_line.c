#include "slide_line.h"

/**
 * slide_left - slides and merges to left an array of integers
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * Return: SUCCESS 1 or FAILURE 0
 */

int slide_left(int *line, size_t size)
{
	size_t left, right, temp;

	if ((line[0] == 0))
	{
		temp = 0;
		while (line[temp] == 0)
		{
			if (temp >= size)
				return (1);
			temp++;
		}
		line[0] = line[temp];
		line[temp] = 0;
	}
	left = 0;
	for (right = 1; right < size; right++)
	{
		if (line[left] == line[right])
		{
			line[left] = line[left] * 2;
			line[right] = 0;
			right++;
			while (line[right] == 0)
			{
				if (right >= size)
					return (1);

				right++;
			}
			left++;
			line[left] = line[right];
			line[right] = 0;
		}
		else if (line[right] != 0)
			left++;
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
	size_t left, right, temp;

	if (line[size - 1] == 0)
	{
		temp = size - 1;
		while (line[temp - 1] == 0)
		{
			if (temp <= 1)
				return (1);
			temp--;
		}
		line[size - 1] = line[temp - 1];
		line[temp - 1] = 0;
	}
	right = size - 1;
	for (left = size - 1; left >= 1; left--)
	{
		if (line[left - 1] == line[right])
		{
			line[right] = line[right] * 2;
			line[left - 1] = 0;
			left--;
			while (line[left - 1] == 0)
			{
				if (left <= 1)
				{
					return (1);
				}

				left--;
			}
			right--;
			line[right] = line[left - 1];
			line[left - 1] = 0;
		}
		else if (line[left - 1] != 0)
			right--;
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
		return (1);
	}

	if (direction == 2)
	{
		slide_right(line, size);
		return (1);
	}

	return (0);
}
