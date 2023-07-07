#include "main.h"

/**
 * set_bit - set bit of index 1
 * @n: number of change pointer
 * @index: index of bit
 *
 * Return: 1 if success, -1 if fail
 */
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned int i;
if (index > 63)
return (-1);
i = 1 << index;
*n = (*n | i);
return (1);
}
