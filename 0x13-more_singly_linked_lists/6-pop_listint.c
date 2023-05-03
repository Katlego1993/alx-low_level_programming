#include "lists.h"
#include <stdlib.h>
/**
 * pop_listint - delete the head node
 * @head: head pointer
 *
 * Return: empty
 */
int pop_listint(listint_t **head)
{
listint_t *s;
int i;

if (head == NULL || *head == NULL)
return (0);
s = *head;
*head = s->next;
i = s->i;
free(s);
return (i);
}
