#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * @direction: left(1) or right(2)
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t left, right;

	if (direction == 1)
	{
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
					{
						return (1);
					}

					right++;
				}
				left++;
				line[left] = line[right];
				line[right] = 0;
			}
			else if (line[right] != 0)
			{
				left++;
			}
		}
		return (1);
	}

	if (direction == 2)
	{
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
			{
				right--;
			}
		}
		return (1);
	}

	return (0);
}
