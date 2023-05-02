#include "lists.h"

/**
 * listint_len - Print the number of linked list elements
 *
 * @h: head of listint_t
 *
 * Return: The number of elements
 *
 */
size_t listint_len(const listint_t *h)
{
size_t i = 0;

while (h != NULL)
{
h = h->next;
i++;
}
return (i);
}
