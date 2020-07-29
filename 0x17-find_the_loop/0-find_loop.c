#include "lists.h"

/**
 * find_listint_loop - finds loops inside list
 * @head: head of list
 * Return: node loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_p = head, *fast_p = head;

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			return (1);
		}
	}
	return (0);
}
