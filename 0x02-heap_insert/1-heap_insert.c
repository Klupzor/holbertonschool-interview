#include "binary_trees.h"

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *current;
    list_t *list;

    current = *root;
    if (current == NULL)
    {
        *root = binary_tree_node(current, value);
        printf("Created!\n");
        return (*root);
    }
    list = add_node_end(NULL, current);

    while (len_list(list) > 0)
    {
        current = list->node;
        list = rmv_node_head(list);

        if (!current->left)
        {
            current->left = binary_tree_node(current, value);
            return (current->left);
        }
        else
        {
            list = add_node_end(list, current->left);
        }

        if (!current->right)
        {
            current->right = binary_tree_node(current, value);
            return (current->right);
        }
        else
        {
            list = add_node_end(list, current->right);
        }
        
    }
    
    printf("current: %d\n", current->n);
    while (current->left)
    {
        current = current->left;
    }

    current->left = binary_tree_node(current, value);
    
    return(current->left);
}


list_t *add_node_end(list_t *head, heap_t *node)
{
    list_t *new;


	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

    new->node = node;
    new->next = NULL;

    if (!head)
    {
        printf("Primer item: %d\n", new->node->n);
        return (head = new);
    }

    while (head->next)
    {
        head = head->next;
    }


    head->next = new;
    printf("Agregado: %d\n", new->node->n);
    return(new);
    
}

list_t *rmv_node_head(list_t *head)
{
    list_t *temp;


    if (!head)
        return(NULL);
    printf("Eliminado: %d\n", head->node->n);
    temp = head;
    head = head->next;
    free(temp);
    return (head);
}

int len_list(list_t *head)
{   int len = 0;

    if (!head)
    {
        printf("len es 0\n");
        return (0);
    }

    printf("list [");
    
    while (head)
    {
        printf("%d ,",head->node->n);
        len = len + 1;
        head = head->next;
    }
    printf("]\n");
    
    printf("len es %d\n", len);

    return(len);
}