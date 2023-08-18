#include "lists.h"

/**
 * dlistint_len - returns the num of elements in linked list
 *
 * @h: head of list
 * Return: nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}
