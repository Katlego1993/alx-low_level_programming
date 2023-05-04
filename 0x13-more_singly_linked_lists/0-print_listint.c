#include "lists.h"
#include <stdio.h>

/**
 * print_listint - print all elements of linked list
 * @h: linked list to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
size_t i = 0;

while (h)
{
printf("%d\n", h->n);
i++;
h = h->next;
}
return (i);
}

