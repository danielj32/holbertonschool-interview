#include "binary_trees.h"
/**
 * binary_tree_node - create a binary tree
 *@parent: pointer to first
 *@value: value of node
 *Return: a tree
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = value;
	newnode->left = NULL;
	newnode->right = NULL;

	if (parent == newnode)
	{
		newnode->parent = NULL;
		parent = newnode;
		return (parent);
	}
	else
	{
		newnode->parent = parent;
		return (newnode);
	}
}
