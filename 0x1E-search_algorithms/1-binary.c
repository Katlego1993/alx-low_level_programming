#include "search_algos.h"

/**
  * binary_search - Searches for a value in a sorted array
  *                 of integers using binary search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int binary_search(int *array, size_t size, int value)
{
	size_t k = 0;
	int *a = array;

	if (!array)
		return (-1);

	while (size)
	{
		for (k = 0, printf("Searching in array: "); k < size; k++)
			printf("%d%s", a[k], k + 1 == size ? "\n" : ", ");

		k = (size - 1) / 2;
		if (a[k] == value)
			return ((a - array) + k);
		else if (a[k] > value)
			size = k;
		else
		{
			a += (k + 1);
			size -= (k + 1);
		}
	}
	return (-1);
}
