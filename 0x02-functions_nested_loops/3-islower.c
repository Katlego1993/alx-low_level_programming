#include "main.h"
/**
 * _islower - Shows 1 if the input is c
 * lowercase character. Another cases, shows
 * 0
 *
 * @: The character in ASCII code
 *
 * Return: 1 for lowercasse character. 0 for the rest.
 */
int _islower(int c);
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
