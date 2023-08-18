#include "lists.h"

/**
 * sum_dlistint - returns sum of data
 *
 * @head: head of list
 * Return: sum of data
 */
int sum_dlistint(dlistint_t *head)
{
	int a;
	sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head!= NULL)
		{
			a += head->n;
			head = head->next;
		}
	}
	return (a);
}
