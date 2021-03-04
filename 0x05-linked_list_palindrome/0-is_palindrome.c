#include "lists.h"

/**
 *listint_len - print num elements list
 *@head: list of nodes
 *Return: count of nodes
 */

int listint_len(listint_t **head)
{
	 int ct = 0;
	 listint_t *newnode = *head;

	while (newnode)
	{
		newnode = newnode->next;
		ct++;
	}
	return (ct);
}

/**
 * reverse_listint - reverse a linked list.
 *@head: first node
 * Return: head.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *before = NULL;
	listint_t *actual = NULL;

	while (*head)
	{
		before = *head;
		*head = (*head)->next;
		before->next = actual;
		actual = before;
	}

	*head = actual;
	return (*head);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: head of linked list
 * Return: 1 if is palindrome or 0 if not
 */

int is_palindrome(listint_t **head)
{
	int length = listint_len(head);
	int i, if_palindrome = 1;
	listint_t *rever_head;
	listint_t *newnode = *head;
	listint_t *c_reversed;

	rever_head = *head;
	for (i = 0; i < (length / 2); i++)
		rever_head = rever_head->next;
	if (length % 2 != 0)
		rever_head = rever_head->next;
	rever_head = reverse_listint(&rever_head);
	c_reversed = rever_head;
	newnode = *head;
	while (c_reversed)
	{
		if (c_reversed->n != newnode->n)
			if_palindrome = 0;
		c_reversed = c_reversed->next;
		newnode = newnode->next;
	}
	return (if_palindrome);
}
