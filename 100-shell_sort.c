#include "sort.h"

int knuth_sequence(int n);

/**
 * shell_sort- sorts an array of integers using the shell sort algorithm.
 * @array: the array of integers to sort.
 * @size: size of the array.
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j, gap;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (gap = knuth_sequence(size); gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}

/**
 * knuth_sequence - an implementation of the knuth sequence for the shell
 *	sort algorithm.
 * @size: an int argument.
 * Return: the initial gap between array elements to swap.
 */
int knuth_sequence(int size)
{
	int gap = 1;

	while (gap < size)
		gap = 3 * gap + 1;
	return ((gap - 1) / 3);
}
