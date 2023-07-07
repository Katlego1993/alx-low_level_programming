#include "main.h"
/**
 * clear_bit - sets value to 0
 * @n: number of pointer to change
 * @index: index of a bit
 *
 * Return: 1 for success and -1 for fail
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned int i;
if (index > 63)
return (-1);
i = 1 << index;
if (*n & i)
*n ^= i;
return (1);
}
