#include "sort.h"

/**
 * bubble_sort - the function that sorts an array of integers in
 *	ascending order using the Bubble sort.
 *
 * @array: an array of integers.
 *
 * @size: size of the array.
 *
 * Returns: Nothing.
 *
 * Description: prints the array after each time yu swap 2 elements.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, temp, swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
