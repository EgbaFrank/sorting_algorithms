#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort algorithm
 * @array: array to be sorted
 * @size: number of elements in array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, idx;

	if (size < 2)
		return;

	for (i = 0; i < (size - 1); ++i)
	{
		idx = min(array, i, size);

		if (idx != i)
		{
			int tmp = array[i];

			array[i] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}

/**
 * min - find the index of the smallest element in an array
 * @arr: array to search
 * @start: element to begin from
 * @n: size of array
 *
 * Return: index of smallest element
 */

int min(int arr[], int start, int n)
{
	int i, idx, low;

	low = arr[start];
	idx = start;

	for (i = start + 1; i < n; ++i)
	{
		if (arr[i] < low)
		{
			low = arr[i];
			idx = i;
		}
	}

	return (idx);
}
