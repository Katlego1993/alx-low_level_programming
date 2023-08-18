#include "lists.h"

/**
 * sum_dlistint - returns sum of data
 *
 * @head: head of list
 * Return: sum of data
 */
int sum_dlistint(dlistint_t *head)
{
	int a = 0;

	while (head)
	{
		a += head->n;
		head = head->next;
	}
	return (a);
}
