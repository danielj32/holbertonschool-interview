#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: head of the linked list
 * Return: address of the node where the loop starts, or NULL if there is
 * no loop
 **/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *aux, *aux2;

	aux = aux2 = head;
	while (aux != NULL && aux2 != NULL)
	{
		aux = aux->next;
		aux2 = aux2->next->next;
		if (aux == aux2)
		{
			aux2 = head;
			while (aux != aux2)
			{
				aux = aux->next;
				aux2 = aux2->next;
			}
			return (aux2);
		}
	}
	return (NULL);
}
