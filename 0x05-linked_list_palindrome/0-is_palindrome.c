#include "lists.h"

/**
 * add_nodeint_head - adds a new node at the top of the list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_head(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = current;
		*head = new;
	}

	return (new);
}

/**
 * is_palindrome - compare if the list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if is palindrome 0 if it is not
 */

int is_palindrome(listint_t **head)
{
	listint_t *head_inv, *current, *current_inv;

	if (!*head)
		return (1);

	head_inv = NULL;
	current = *head;

	while (current)
	{
		add_nodeint_head(&head_inv, current->n);
		current = current->next;
	}

	current = *head;
	current_inv = head_inv;

	while (current && current_inv)
	{
		if (current->n != current_inv->n)
		{
			free_listint(head_inv);
			return (0);
		}
		current = current->next;
		current_inv = current_inv->next;

	}

	free_listint(head_inv);
	return (1);
}
