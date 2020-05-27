#include "search.h"

/**
 * linear_skip - Looking for a specific value in a singly linked list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer value or NULL
**/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skipList, *prevSkip;

	if (!list)
		return (NULL);

	skipList = list->express;
	prevSkip = list;

	while (skipList)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   skipList->index, skipList->n);
		if (!skipList->express || skipList->n >= value)
		{
			if (!skipList->express && skipList->n < value)
			{
				prevSkip = skipList;
				while (skipList->next)
					skipList = skipList->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
				   prevSkip->index, skipList->index);
			while (prevSkip)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					   prevSkip->index, prevSkip->n);
				if (prevSkip->n == value)
					return (prevSkip);
				if (prevSkip->n > value)
					return (NULL);
				prevSkip = prevSkip->next;
			}
			break;
		}
		prevSkip = skipList;
		skipList = skipList->express;
	}
	return (NULL);
}
