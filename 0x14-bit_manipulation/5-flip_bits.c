#include "main.h"

/**
 * flip_bits - numbers of bits to change form one number to another
 * @n: 1st number
 * @m: 2nd number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int k, l = 0;
unsigned long int c;
unsigned long int exclusive = n ^ m;

for (k = 63; k >= 0; k--)
{
c = exclusive >> k;
if (c & 1)
l++;
} return (l);
}
