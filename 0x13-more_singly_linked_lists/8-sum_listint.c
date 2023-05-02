#include "lists.h"

/**
 * sum_listint - sum of all date of listint_t linked list
 * @head: pointer to the first node
 *
 * Return: sun of all dates
 */
int sum_listint(listint_t *head)
{
int sum = 0;

while (head != NULL)
{
sum += head->n;
head = head->next;
}
return (sum);
}

