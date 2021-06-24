#include "binary_trees.h"
/**
 * heap_extract - extracts the root root from a Max-heap
 * @root: Address of the root pointer
 * Return: return the root value or 0 on failure
 */

int heap_extract(heap_t **root)
{
	int i, n, size;
	heap_t **array;

	if (root == NULL || *root == NULL)
		return (0);
	n = (*root)->n;
	size = count_heap(*root);
	array = malloc(1024 * sizeof(heap_t *));
	if (array == NULL)
		return (0);
	for (i = 0; i < size; i++)
		array[i] = NULL;
	arrange_heap(array, *root, 0);
	if (array[size - 1] == (*root))
	{
		free(array);
		free(*root);
		*root = NULL;
		return (n);
	}
	(*root)->n = array[size - 1]->n;
	if (array[size - 1]->parent->left == array[size - 1])
		array[size - 1]->parent->left = NULL;
	else
		array[size - 1]->parent->right = NULL;
	free(array[size - 1]);
	free(array);
	rebuild_eva(*root);
	return (n);
}

/**
 * count_heap - counts the size of a heap
 * @root: first root
 * Return: returns the size
 */
int count_heap(heap_t *root)
{
	return (root ? 1 + count_heap(root->left) + count_heap(root->right) : 0);
}

/**
 * arrange_heap - arranges a heap in an array
 * @array: the array
 * @root: first root
 * @first: first of the array to fill
 */
void arrange_heap(heap_t **array, heap_t *root, int first)
{
	array[first] = root;
	if (root)
	{
		arrange_heap(array, root->left, (first * 2) + 1);
		arrange_heap(array, root->right, (first * 2) + 2);
	}
}

/**
 * rebuild_eva - rebuilds a heap
 * @root: root of the heap
 */
void rebuild_eva(heap_t *root)
{
	int aux;

	if (!root->left)
	{
		return;
	}
	else if (!root->right || root->left->n >= root->right->n)
	{
		if (root->n < root->left->n)
		{
			aux = root->n;
			root->n = root->left->n;
			root->left->n = aux;
		}
		rebuild_eva(root->left);
	}
	else if (root->left->n < root->right->n)
	{
		if (root->n < root->right->n)
		{
			aux = root->n;
			root->n = root->right->n;
			root->right->n = aux;
		}
		rebuild_eva(root->right);
	}
}
