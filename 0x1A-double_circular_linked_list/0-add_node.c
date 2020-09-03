#include "list.h"

/**
 * node - creates new node
 * @list: list
 * @str: string
 * Return: New Node
 */
List *node(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->next = new;
	new->prev = new;
	*list = new;
	return (new);
}
/**
 * add_node_end - adds node at the end
 * @list: list
 * @str: string
 * Return: New Node
 */
List *add_node_end(List **list, char *str)
{
	List *new, *tmp, *aux;

	if (list == NULL)
		return (NULL);
	if (*list == NULL)
		return (node(list, str));

	aux = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->next = aux;
	new->prev = aux->prev;
	tmp = aux->prev;
	aux->prev = new;
	tmp->next = new;

	return (new);
}
/**
 * add_node_begin - adds node at the beginning
 * @list: list
 * @str: string
 * Return: New node
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *tmp, *aux;

	if (list == NULL)
		return (NULL);
	if (*list == NULL)
		return (node(list, str));

	aux = *list;
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->next = aux;
	new->prev = aux->prev;
	tmp = aux->prev;
	aux->prev = new;
	tmp->next = new;
	*list = new;

	return (new);

}