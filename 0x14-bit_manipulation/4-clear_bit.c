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
if (index > 63)
return (-1);
*n = (~(1UL << index) & *n);
return (1);
}
