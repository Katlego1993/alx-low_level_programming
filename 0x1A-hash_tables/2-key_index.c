/**
 * key_inex - index key stored in array of hash table
 * @key: key to get index
 * @size: size of hash table in array
 *
 * Return: index of key
 * Description: uses the djb2 algorithm
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
