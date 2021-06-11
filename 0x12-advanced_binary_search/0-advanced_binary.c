#include "search_algos.h"
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: the array
 * @size: size of the array
 * @value: the value to search for
 * Return: the index where value is located or -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	if (size < 1)
		return (-1);
	return (binary_search(array, 0, (int)(size - 1), value));
}

/**
 * binary_search - search recursively for value
 * @array: the array
 * @one: one index of the subarray
 * @before: before index of the subarray
 * @value: the value to search for
 * Return: the index where value is located or -1
 */
int binary_search(int *array, int one, int before, int value)
{
	int between, i;

	if (one > before)
		return (-1);
	between = (one + before) / 2;
	if (array[between] == value && one == before)
		return (between);
	printf("Searching in array: ");
	for (i = one; i <= before; i++)
	{
		if (i != one)
		{
			printf(", ");
		}
		printf("%d", array[i]);
		if (i == before)
			printf("\n");
	}
	if (array[between] >= value)
		return (binary_search(array, one, between, value));
	return (binary_search(array, between + 1, before, value));
}
