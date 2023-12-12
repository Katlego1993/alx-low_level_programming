#include "search_algos.h"

/**
 * linear_search - search for a value in an array of integers
 * @array: the integer array
 * @size: the number of elememts in the array
 * @value: value to search for
 *
 * Return: the index found or -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t k = 0;

	if (!array)
		return (-1);
	while (k < size)
	{
		printf("Value checked array[%lu] = [%d]\n", k, array[k]);
		if (array[k] == value)
			return (k);
		k++;
	}
	return (-1);
}
