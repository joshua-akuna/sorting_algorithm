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
	unsigned int min, idx, jdy;
	int temp;

	if (array == NULL || size < 1)
		return;

	for (idx = 0; idx < size - 1; idx++)
	{
		min = idx;
		for (jdy = idx + 1; jdy < size; jdy++)
		{
			if (array[jdy] < array[min])
				min = jdy;
		}
		if (idx != min)
		{
			temp = array[min];
			array[min] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
