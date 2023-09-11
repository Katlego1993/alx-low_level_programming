#include "hash_tables.h"

/**
 * key_index - index key pair stored in array of hash table
 * @key: key to get index.
 * @size: Array size of hash table
 *
 * Return: The index of the key.
 * Description: Uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
