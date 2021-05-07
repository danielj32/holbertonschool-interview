#include "binary_trees.h"
/**
 * sorted_array_to_avl - Builds an AVL tree
 * @array: converted
 * @size: Size of the array
 * Return: a new pointer to root node of the created AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int i = 1;

	if (array == NULL)
		return (NULL);
	if (size < 1)
		return (NULL);
	while (i < (int)size)
	{
		if (array[i] < array[i - 1])
			return (NULL);
		i++;
	}
	return (newAVL(array, 0, (int)size - 1, NULL));
}

/**
 * newAVL - Builds an AVL tree from an array
 * @array: converted
 * @begin: begin index
 * @goal: last index
 * @parent: parent of the currently node
 * Return: pointer to root node of the created AVL tree
 */
avl_t *newAVL(int *array, int begin, int goal, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (begin > goal)
		return (NULL);

	mid = (begin + goal) / 2;

	root = malloc(sizeof(avl_t));
	if (root == NULL)
		return (NULL);
	root->n = array[mid];
	root->parent = parent;
	root->left = newAVL(array, begin, mid - 1, root);
	root->right = newAVL(array, mid + 1, goal, root);
	return (root);
}
