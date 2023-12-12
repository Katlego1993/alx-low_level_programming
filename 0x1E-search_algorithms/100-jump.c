#include "search_algos.h"

/**
  * jump_search - Searches for a value in a sorted array
  *               of integers using jump search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  *
  * Description: Prints a value every time it is compared in the array.
  *              Uses the square root of the array size as the jump step.
  */
int jump_search(int *array, size_t size, int value)
{
	size_t k = 0, l = sqrt(size);

	if (!array)
		return (-1);

	while (k < size && array[k] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", k, array[k]);
		k += l;
	}

	l = k - l;
	printf("Value found between indexes [%lu] and [%lu]\n", l, k);
	k = k >= size ? size - 1 : k;
	while (l <= k)
	{
		printf("Value checked array[%lu] = [%d]\n", l, array[l]);
		if (array[l] == value)
			return (l);
		l++;
	}
	return (-1);
}
