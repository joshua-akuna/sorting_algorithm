#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 *	using the Selection sort algorithm.
 * @array: the array of integers to sort.
 * @size: the number of elements in the @array argument.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int min, i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
