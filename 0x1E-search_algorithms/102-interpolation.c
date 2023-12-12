#include "search_algos.h"

/**
 * interpolation_search -Searches for a value in a sorted array of integer
 * @array: A pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: value to search for
 *
 * Return: the index found or -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t k = 0, l = 0, h = size - 1;

	if (!array || !size)
		return (-1);

	while (1)
	{
		k = l + (((double)(h - l) /
			  (array[h] - array[l])) * (value - array[l]));
		if (k >= size)
		{
			printf("Value checked array[%lu] is out of range\n", k);
			break;
		}
		printf("Value checked array[%lu] = [%d]\n", k, array[k]);
		if (array[k] == value)
			return (k);
		else if (array[k] > value)
			h = k - 1;
		else
			l = k + 1;
	}
	return (-1);
}
