#include <limits.h>
#include <stddef.h>
#include "binary_trees.h"

/**
 * check_recursion - the recursive test for AVL treeness
 * @t: tree to check
 * @min: minimum allowed
 * @max: maximum allowed
 * Return: height of tree, or -1 for early exit if non-AVLness confirmed
 */
long int check_recursion(const binary_tree_t *t, const int min, const int max)
{
	long int left, right;

	if (!t)
		return  (1);
	if (t->n < min || t->n > max)
		return (-1);
	left = check_recursion(t->left, min, t->n);
	if (left == -1)
		return (-1);
	right = check_recursion(t->right, t->n, max);
	if (right == -1)
		return (-1);
	if (left > right + 1 || right > left + 1)
		return (-1);
	return (left > right ? left + 1 : right + 1);
}

/**
 * binary_tree_is_avl - check if a binary tree is an avl tree
 *
 * @tree: check if AVL
 *
 * Return: 1 if AVL, 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	long int result;

	if (!tree)
		return (0);
	result = check_recursion(tree, INT_MIN, INT_MAX);
	if (result == -1)
		return (0);
	return (1);
}
