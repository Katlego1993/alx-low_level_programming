/**
 * hash_table_create - Creates a hash table
 * @size: array size
 *
 * Return: Null if error occurs otherwise pointer to new hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *htable;
	unsigned long int a;

	htable = malloc(sizeof(hash_table_t));
	if (htable == NULL)
		return (NULL);

	htable->size = size;
	htable->array = malloc(sizeof(hash__node_t *) * size);
	if (htable->array == NULL)
		return (NULL);
	for (a = 0; a < size; a++)
		htable->array[a] = NULL;

	return (htable);
}
