#include "lists.h"

/**
 * dlistint_len - returns the num of elements in linked list
 *
 * @h: head of list
 * Return: nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int num;
	num = 0;

	if (h == NULL)
		return (num);
	while (h != NULL)
	{
		num++;
		h = h->next;
	}
	return (num);
}
