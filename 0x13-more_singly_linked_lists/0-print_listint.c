#include "lists.h"
#include <stdio.h>

/**
 * print_listint - pritnts all list of elements
 *
 * @h :Head of link list node
 *
 * Return: node number
*/
size_t print_listint(const listint_t *h)
{
size_t count = 0;

while (h)
{
count++;
printf("%d\n", h->n);
h = h->next;
}
return (count);
}
