#include "sort.h"
/**
 * heap_sort - sorts an array using the heap sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */

void heap_sort(int *array, size_t size)
{
	int i, end, aux;

	if (array == NULL)
		return;
	else if (size <= 1)
		return;

	end = (int)size - 1;
	for (end = (int)size - 1; end > 0; end--)
	{
		for (i = end; i >= 0; i--)
		{
			heap_array(array, (int)size, i, end);
		}
		aux = array[0];
		array[0] = array[end];
		array[end] = aux;
		print_array((const int *)array, size);
	}
}

/**
 * heap_array - makes the array a max-heap
 * @array: the array is treated as a complete binary tree
 * @size: size of the array
 * @parent: index of the parent node
 * @end: end of the unsorted part of the array
 */
void heap_array(int *array, int size, int parent, int end)
{
	int l, r, aux;

	l = (parent * 2) + 1;
	r = (parent * 2) + 2;
	if (parent < 0)
		return;
	else if (parent >= size - 1)
		return;
	if (r <= end
			&& (array[r] >= array[l] && array[r] > array[parent]))
	{
		aux = array[parent];
		array[parent] = array[r];
		array[r] = aux;
		print_array((const int *)array, (size_t)size);
		heap_array(array, size, r, end);
	}
	if ((l <= end && (r > end || array[l] > array[r]))
			&& array[l] > array[parent])
	{
		aux = array[parent];
		array[parent] = array[l];
		array[l] = aux;
		print_array((const int *)array, (size_t)size);
		heap_array(array, size, l, end);
	}
}
