/**
 * hash_djb2 - implementing the djb2 algorithm with hash function
 * @str: hash string
 *
 * Return: calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int a;

	hash = 5381;
	while ((a = *str++))
		hash = ((hash << 5) + hash) + a; /* hash * 33 + a */

	return (hash);
}
