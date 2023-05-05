#include "main.h"

/**
 * binary_to_uint - conversion of binary to unsigned int
 * @b: Binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
int f;
unsigned int d_val = 0;

if (!b)
return (0);
for (f = 0; b[f]; f++)
{
if (b[f] < '0' || b[f] > '1')
return (0);
d_val = 2 * d_val + (b[f] - '0');
}
return (d_val);
}
