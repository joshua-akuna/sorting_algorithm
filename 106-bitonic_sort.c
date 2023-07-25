#include "sort.h"

void bitonic_sorting(int *array, int first, int new_size,
		int direction, int size);
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
	bitonic_sorting(array, 0, size, dir, size);
}

/**
 * bitonic_sort_algo - sorts the array of integers in ascending order
 *	recursively by splitting it into sub arrays.
 * @array: the array of integers to sort.
 * @first: the first index of the sub array.
 * @new_size: size of the sub array.
 * @direction: specify the sort order, UP (1) or DOWN (0);
 * @size: size of the array.
 */
void bitonic_sorting(int *array, int first,
		int new_size, int direction, int size)
{
	int mid;
	char *dir = direction == 1 ? "UP" : "DOWN";

	if (new_size > 1)
	{
		printf("Merging [%i/%i] (%s):\n", new_size, size, dir);
		print_array(array + first, new_size);

		mid = new_size / 2;
		bitonic_sorting(array, first, mid, 1, size);
		bitonic_sorting(array, first + mid, mid, 0, size);
		bitonic_merge(array, first, new_size, direction);

		printf("Merging [%i/%i] (%s):\n", new_size, size, dir);
		print_array(array + first, new_size);
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
