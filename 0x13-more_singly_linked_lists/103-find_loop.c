#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the beginning of the list
 *
 * Return: address of the node where the loop starts or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *tortoise_t, *hare_h;
tortoise_t = hare_h = head;
while (tortoise_t && hare_h && hare_h->next)
{
tortoise_t = tortoise_t->next;
hare_h = hare_h->next->next;
if (tortoise_t == hare_h)
{
tortoise_t = head;
break;
}
}
if (!tortoise_t || !hare_h || !hare_h->next)
return (NULL);
while (tortoise_t != hare_h)
{
tortoise_t = tortoise_t->next;
hare_h = hare_h->next;
}
return (hare_h);
}
