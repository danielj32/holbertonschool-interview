#include <stdio.h>
#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Insert number in sorted linked list
 * @head: Double pointer to node princi
 * @number: Integer to insert sorted list
 * Return: a listint_t with the address of the newnode node or NULL
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newnode, *prev, *next;

	if (head == NULL)
		return (NULL);
	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = number;
	if (*head == NULL)
	{
		newnode->next = NULL;
		*head = newnode;
		return (newnode);
	}
	prev = *head;
	next = prev->next;
	while (prev)
	{
		if (prev->n >= number)
		{
			newnode->next = prev;
			*head = newnode;
			return (newnode);
		}
		else if (!next && prev->n <= number)
		{
			prev->next = newnode;
			newnode->next = NULL;
			return (newnode);
		}
		else if (prev->n <= number && next->n >= number)
		{
			prev->next = newnode;
			newnode->next = next;
			return (newnode);
		}
		prev = next;
		next = prev->next;
	}
	return (NULL);
}
