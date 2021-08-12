#include "list.h"
/**
 * add_node_end - new node to the end of a double circular linked list
 * @list: address of the begin node
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *newnode;

	if (list == NULL)
		return (NULL);
		else if (str == NULL)
			return (NULL);

	newnode = malloc(sizeof(List));
	if (!newnode)
		return (NULL);
	newnode->str = strdup((const char *)str);
	if (!(newnode->str))
	{
		free(newnode);
		return (NULL);
	}
	if (!*list)
	{
		*list = newnode;
		newnode->prev = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->prev = (*list)->prev;
		newnode->next = *list;
		newnode->prev->next = newnode;
		newnode->next->prev = newnode;
	}
	return (newnode);
}
/**
 * add_node_begin - new node to the beginning of the circular linked list
 * @list: address of the list starting node
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *newnode;

	if (list == NULL)
		return (NULL);
		else if (str == NULL)
			return (NULL);
	newnode = malloc(sizeof(List));
	if (!newnode)
		return (NULL);
	newnode->str = strdup((const char *)str);
	if (!newnode->str)
	{
		free(newnode);
		return (NULL);
	}
	if (!*list)
	{
		*list = newnode;
		newnode->prev = newnode;
		newnode->next = newnode;
	}
	else
	{
		newnode->prev = (*list)->prev;
		newnode->next = *list;
		newnode->prev->next = newnode;
		newnode->next->prev = newnode;
		*list = newnode;
	}
	return (newnode);
}
