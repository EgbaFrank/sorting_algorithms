#include "sort.h"

/**
 * quick_sort - sorts an integer array via quick sort algorithm
 * @array: array to be sorted
 * @size: size of array to be sorted
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	static_print(array, &size);
	q_sort(array, size);
}

/**
 * q_sort - actually implementation of the quick_sort algorithm
 * @array: array to be sorted
 * @size: size of array to be sorted
 *
 * Return: void
 */

void q_sort(int *array, size_t size)
{
	int pivot;

	if (size < 2)
		return;

	pivot = partition(array, size);

	q_sort(array, pivot);
	q_sort(&array[pivot + 1], size - pivot - 1);
}

/**
 * partition - partition an array around a pivot,
 * the last element is used as the pivot
 * @array: array to be partitioned
 * @size: size of array
 *
 * Return: int index of pivot
 */

int partition(int *array, int size)
{
	int i, idx, pivot;

	pivot = array[size - 1];

	idx = -1;

	for (i = 0; i < size - 1; ++i)
	{
		if (array[i] < pivot)
		{
			++idx;
			swap(&array[i], &array[idx]);
		}
	}
	swap(&array[idx + 1], &array[size - 1]);

	return (idx + 1);
}

/**
 * swap - swaps two elements
 * @i: first element
 * @j: second element
 *
 * Return: void
 */
void swap(int *i, int *j)
{
	int temp;

	if (i == j)
		return;

	temp = *i;
	*i = *j;
	*j = temp;
	static_print(NULL, NULL);
}

/**
 * static_print - prints a static array
 * @arr: array to be printed
 * @n: size of array
 *
 * subsequent calls with NULL and both arguments
 * prints same array
 *
 * Return: void
 */
void static_print(int *arr, size_t *n)
{
	static int *a;
	static size_t *size;

	if (arr != NULL && n != NULL)
	{
		a = arr;
		size = n;
	}

	else if (a != NULL && size != NULL)
		print_array(a, *size);
}
