#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - Add node to the listint_t
 *
 * @head: Head of a pointer
 * @n: int add the list
 * Return: NULL if failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *cnt;

if (head == NULL)
return (NULL);
cnt = malloc(sizeof(listint_t));
if (cnt == NULL)
return (NULL);
cnt->n = n;
cnt->next = *head;
*head = cnt;
return (cnt);
}
