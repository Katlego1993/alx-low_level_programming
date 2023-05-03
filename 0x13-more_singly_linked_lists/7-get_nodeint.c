#include "lists.h"

/**
 * *get_nodeint_at_index - the index linked list note
 * @head: pointer of the note
 * @index: index of the node
 *
 * Return : pointer of index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int o;

if (head == NULL)
return (NULL);
for (o = 0; o < index; o++)
{
head = head->next;
if (head == NULL)
return (NULL);
}
return (head);
}
