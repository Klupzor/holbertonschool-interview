#include "binary_trees.h"

/**
 * binary_tree_node - Create new node
 *
 * @parent: Pointer to the father node
 * @value: Node Value
 *
 * Return: new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
