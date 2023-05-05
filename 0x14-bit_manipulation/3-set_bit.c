#include "main.h"

/**
 * set_bit - set bit of index 1
 * @n: number of change pointer
 * @index: index of bit 1
 *
 * Return: 1 if success, -1 if fail
 */
int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);
*n = ((1UL << index) | *n);
return (1);
}
