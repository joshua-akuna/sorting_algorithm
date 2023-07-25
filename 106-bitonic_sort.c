#include "sort.h"

void bitonic_sort_algo(int *array, int first, int last, int direction);
void bitonic_merge(int *array, int first, int size, int direction);

/**
 * bitonic_sort - sorts the array of integers in ascending order.
 * @array: the array of integers to sort.
 * @size: size of the array to sort.
 */
void bitonic_sort(int *array, size_t size)
{
	int dir = 1;

	if (array == NULL || size < 2)
		return;
	bitonic_sort_algo(array, 0, size, dir);
}

/**
 * bitonic_sort_algo - sorts the array of integers in ascending order
 *	recursively by splitting it into sub arrays.
 * @array: the array of integers to sort.
 * @first: the first index of the sub array.
 * @size: size of the array.
 * @direction: specify the sort order, UP (1) or DOWN (0);
 */
void bitonic_sort_algo(int *array, int first, int size, int direction)
{
	int mid;

	if (size > 1)
	{
		mid = size / 2;
		bitonic_sort_algo(array, first, mid, 1);
		bitonic_sort_algo(array, first + mid, mid, 0);
		bitonic_merge(array, first, size, direction);
	}
}

/**
 * bitonic_merge - merges the split subarrays in a sorted manner.
 * @array: the array of integers to sort.
 * @first: the first index of the sub array.
 * @size: size of the array.
 * @direction: specify the sort order, UP (1) or DOWN (0);
 */
void bitonic_merge(int *array, int first, int size, int direction)
{
	int mid = size / 2, i, temp;

	if (size > 1)
	{
		for (i = first; i < first + mid; i++)
		{
			if ((direction == 1 && array[i] > array[i + mid])
				|| (direction == 0 && array[i] < array[i + mid]))
			{
				temp = array[i];
				array[i] = array[i + mid];
				array[i + mid] = temp;
			}
		}
		bitonic_merge(array, first, mid, direction);
		bitonic_merge(array, first + mid, mid, direction);
	}
}
