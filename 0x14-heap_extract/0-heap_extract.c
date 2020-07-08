#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @root: pointer to root of the tree
 * @node: pointer to node in the tree
 * @h: height tree
 * @l: layer on the tree
 **/
void _preorder(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;
	if (h == l)
		*node = root;
	l++;
	if (root->left)
		_preorder(root->left, node, h, l);
	if (root->right)
		_preorder(root->right, node, h, l);
}

/**
 * _sorting - binary tree Heapsort
 * @temp: pointer to the heap root
 * Return: pointer to last node
 **/

heap_t *_sorting(heap_t *temp)
{
	int tempVal;

	while (temp->left || temp->right)
	{
		if (!temp->right || temp->left->n > temp->right->n)
		{
			tempVal = temp->n;
			temp->n = temp->left->n;
			temp->left->n = tempVal;
			temp = temp->left;
		}
		else if (!temp->left || temp->left->n < temp->right->n)
		{
			tempVal = temp->n;
			temp->n = temp->right->n;
			temp->right->n = tempVal;
			temp = temp->right;
		}

	}
	return (temp);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/

int heap_extract(heap_t **root)
{
	int value;
	heap_t *temp, *node;

	if (!root || !*root)
		return (0);
	temp = *root;
	value = temp->n;
	if (!temp->left && !temp->right)
	{
		*root = NULL;
		free(temp);
		return (value);
	}
	_preorder(temp, &node, _height(temp), 0);
	temp = _sorting(temp);
	temp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
