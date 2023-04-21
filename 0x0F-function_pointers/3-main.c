#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"
/**
 * main - prints the result of simple operations
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to te arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
int (*oprt)(int, int);

if (argc != 4)
{
printf("Error\n");
exit(98);
}
oprt = get_op_func(argv[2]);

if (!oprt)
{
printf("Error\n");
exit(99);
}
printf("%d\n", oprt(atoi(argv[1]), atoi(argv[2])));
return (0);
}
