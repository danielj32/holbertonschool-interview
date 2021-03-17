#include "lists.h"
/**
 * check_cycle - check if a singly linked list has a loop
 * @list: pointer to head of list
 * Return: 1 if is a cycle 0 if not
 */

int check_cycle(listint_t *list)
{
	listint_t *turtle = list, *rabbit = list;

	while (turtle && rabbit && rabbit->next)
	{
		turtle = turtle->next;
		rabbit = rabbit->next->next;
		if (turtle == rabbit)
			return (1);
			}
			return (0);
}
