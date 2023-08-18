#include "lists.h"

/**
 * insert_dnodeint_at_index - insert new node
 *
 * @h: head of list
 * @idx: index of new node
 * @n: value of node
 * @Return: address of node or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *head;
	unsigned int a;

	new = NULL;
	if (idx == 0)
		new = add_dnodeint(h, n);
	else
	{
		head = *h;
		a = 1;
		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;
		while (head != NULL)
		{
			if (a == idx)
			{
				if (head ->next == NULL)
					new = add_dnodeint_end(h, n);
				else
				{
					new = malloc(sizeof(dlistint_t))
						if (new != NULL)
						{
							new->n = n;
							new->next = head->next;
							new->prev = head;
							head->next->prev = new;
							head->next->prev = new;
							head->next = new;
						}
				}
				break;
			}
			head = head->next;
			a++;
		}
	}
	return (new);
}
