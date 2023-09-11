#include "hash_tables.h"
/**
 * hash_table_print - prints a hash table
 * @ht: hast table pointer to print
 * Description: key/value pairs are printed in the order they appear in array of hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int a;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (a = 0; a < ht->size; a++)
	{
		if (ht->array[a] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			node = ht->array[a];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	print("}\n");
}
