#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - add a new node at the end of listint_t list
 *
 * @head: head of a pointer
 * @n: int add the list
 * Return: NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *ni;
listint_t *t;

if (head == NULL)
return (NULL);
ni = malloc(sizeof(listint_t));
if (ni == NULL)
return (NULL);
ni->n = n;
ni->next = NULL;
if (*head == NULL)
{
*head = ni;
return (ni);
}
t = *head;
while (t->next != NULL)
{
t = t->next;
}
t->next = ni;
return (ni);
}
