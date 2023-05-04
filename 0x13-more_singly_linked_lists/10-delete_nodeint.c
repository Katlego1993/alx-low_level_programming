#include "lists.h"
#include <stdlib.h>
/**
 * delete_nodeint_at_index - delets the node at index
 * @head: head pointer double
 * @index: index of node
 *
 * Return: pointer to the index node
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
unsigned int n;
listint_t *t, *next;

if (head == NULL || *head == NULL)
return (-1);
if (index == 0)
{
next = (*head)->next;
free(*head);
*head = next;
return (1);
}
t = *head;
for (n = 0; n < index - 1; n++)
{
if (t->next == NULL)
return (-1);
t = t->next;
}
next = t->next;
t->next = next->next;
free(next);
return (1);
}
