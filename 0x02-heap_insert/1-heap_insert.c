#include "binary_trees.h"
/**
* heap_insert - insert node in heap max
* @root: pointer double to root heap
* @value: value n node to insert
* Return: pointer to node insert or NULL if err
*/
heap_t *heap_insert(heap_t **root, int value)
{
	size_t newNode;
	heap_t *firstNode;

	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));
	newNode = get_sizeOf(*root) + 1;
	firstNode = wthIndex(*root, value, 1, newNode);

	while (firstNode && firstNode->parent && firstNode->n > firstNode->parent->n)
	{
		firstNode->n = firstNode->parent->n;
		firstNode->parent->n = value;
		firstNode = firstNode->parent;
	}
	return (firstNode);
}
/**
 * wthIndex - Inserts node level ordered
 * @root: Type binary_tree pointer of the parent node
 * @value: Type int value of value inserted into node
 * @idx: Type int index of the node
 * @newNode: number the nodes + 1
 * Return: Node inserted
 */
heap_t *wthIndex(binary_tree_t *root, int value, size_t idx, size_t newNode)
{
	heap_t *nodel, *noder;
	size_t parent = newNode / 2;

	if (root == NULL)
		return (NULL);
	if (idx == parent)
	{
		if (newNode % 2)
			return (root->right = binary_tree_node(root, value));
		else
			return (root->left = binary_tree_node(root, value));
	}
	nodel = wthIndex(root->left, value, 2 * idx, newNode);
	noder = wthIndex(root->right, value, 2 * idx + 1, newNode);
	if (nodel)
		return (nodel);
	else
		return (noder);
}
/**
 * get_sizeOf - gets number of nodes in heap
 * @root: pointer to root node
 * Return: number of nodes
 */
size_t get_sizeOf(heap_t *root)
{
	int left = 0, right = 0;

	if (root == NULL)
		return (0);
	left = get_sizeOf(root->left);
	right = get_sizeOf(root->right);
	return (1 + left + right);
}
