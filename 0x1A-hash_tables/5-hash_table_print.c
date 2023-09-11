#include "hash_tables.h"

/**
 * hash_table_print - Print a hash table.
 * @ht: Hash table pointer.
 *
 * Return: Void.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int k, flag = 0;
	hash_node_t *current;

	if (ht == NULL)
		return;
	putchar('{');
	for (k = 0; k < ht->size; k++)
	{
		current = ht->array[k];
		if (current != NULL)
		{
			while (current != NULL)
			{
				if (flag == 1)
				{
					printf(", ");
				}
				printf("'%s': '%s'", current->key, current->value);
				flag = 1;
				current = current->next;
			}
		}
	}
	putchar('}');
	putchar('\n');
}
