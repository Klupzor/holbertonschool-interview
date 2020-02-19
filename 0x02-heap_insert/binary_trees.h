#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
typedef struct binary_tree_s heap_t;
heap_t *heap_insert(heap_t **root, int value);

typedef struct list_trees
{
	struct binary_tree_s *node;
	struct list_trees *next;
} list_t;

list_t *add_node_end(list_t *head, heap_t *node);
list_t *rmv_node_head(list_t *head);
int len_list(list_t *head);

#endif /* _BINARY_TREES_H_ */
