#include "sort.h"
/**
 * merging - merging begin and last arrays into original array
 * @array: pointer to array
 * @size: size of the array
 * @begin: pointer to begin array
 * @last: pointer to last array
 **/

void merging(int *array, int *begin, int *last, size_t size)
{
	int i = 0, j = 0, k = 0;
	int first_size, second_size;

	first_size = size / 2;
	second_size = size - first_size;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(begin, first_size);
	printf("[right]: ");
	print_array(last, second_size);

	while (i < first_size && j < second_size)
	{
		if (begin[i] < last[j])
			array[k++] = begin[i++];
		else
			array[k++] = last[j++];
	}

	while (i < first_size)
		array[k++] = begin[i++];

	while (j < second_size)
		array[k++] = last[j++];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t middle = 0, i;
	int left[1000];
	int right[1000];

	if (array == NULL || size < 2)
		return;

	middle = size / 2;

	for (i = 0; i < middle; i++)
		left[i] = array[i];

	for (i = middle; i < size; i++)
		right[i - middle] = array[i];

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merging(array, left, right, size);
}
