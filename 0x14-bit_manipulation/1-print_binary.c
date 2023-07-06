#include "main.h"

/**
 * print_binary - prints binary of a decimal number
 * @n: number of binary
 */
void print_binary(unsigned long int n)
{
int m, cnt = 0;
unsigned long int current;

for (m = 63; m >= 0; m--)
{
current = n >> m;
if (current & 1)
{
_putchar('1');
cnt++;
}
else if (cnt)
_putchar('0');
}
if (!cnt)
_putchar('0');
}
