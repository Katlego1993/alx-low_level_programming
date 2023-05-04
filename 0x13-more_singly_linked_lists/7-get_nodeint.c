#include "lists.h"
/**
 * get_nodeint_at_index - returns the node of a linked inde
 * @head: first node in the linked list
 * @index: index of the node
 *
 * Return: pointer to the node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int k = 0;
listint_t *t = head;

while (t && k < index)
{
t = t->next;
k++;
}
return (t ? t : NULL);
}
