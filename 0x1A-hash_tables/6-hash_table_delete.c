#include "hash_tables.h"

/**
 * hash_table_delete - Delete the hash table.
 * @ht: Hash table pointer.
 *
 * Return: Void.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int k;
	hash_node_t *current;

	for (k = 0; k < ht->size; k++)
	{
		if (ht->array[k] != NULL)
		{
			while (ht->array[k] != NULL)
			{
				current = ht->array[k]->next;
				free(ht->array[k]->key);
				free(ht->array[k]->value);
				free(ht->array[k]);
				ht->array[k] = current;
			}
		}
	}
	free(ht->array);
	free(ht);
}
