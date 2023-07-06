#include "main.h"

/**
 * binary_to_uint - binary to unit convertion
 * @b: string binary number
 *
 * Return: Number that was converted
 */
unsigned int binary_to_uint(const char *b)
{
int o;
unsigned int value = 0;

if (!b)
return (0);
for (o = 0; b[o]; o++)
{
if (b[o] < '0' || b[o] > '1')
return (0);
value = 2 * value + (b[o] - '0');
}
return (value);
}
