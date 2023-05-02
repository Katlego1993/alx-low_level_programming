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
listint_t *ptr;

if (head == NULL)
return (NULL);
ptr = malloc(sizeof(listint_t));
if (ptr == NULL)
return (NULL);
ptr->n = n;
ptr->next = *head;
*head = ptr;
return (ptr);
}
