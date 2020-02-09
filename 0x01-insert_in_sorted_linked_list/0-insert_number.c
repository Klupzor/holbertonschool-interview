#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - adds a new ordered node
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	if (*head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	while (current->next != NULL && current->next->n < number)
		current = current->next;

	if (current->next == NULL)
		new->next = NULL;
	else
		new->next = current->next;

	current->next = new;

	return (new);
}
