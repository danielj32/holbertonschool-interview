#include "binary_trees.h"
/**
 * heap_insert - creates a binary tree node
 * @root: double pointer
 * @value: value to store
 *
 * Return: The address of the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{

	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}
