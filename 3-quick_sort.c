#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order
 *	using the Quick sort algorithm.
 * @array: the array of integers to be sorted.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_array(array, size, 0, size - 1);
}

/**
 * quick_sort_array - a recursive function that sorts an array
 *	of integers using the Quick sort algorithm and the Lomuto
 *	partition scheme.
 * @arr: the array of integers to sort.
 * @size: size of the array.
 * @low: the starting index.
 * @high: the ending index.
 */
void quick_sort_array(int *arr, size_t size, int low, int high)
{
	int part_idx = 0;

	if (low < high)
	{
		part_idx = partition(arr, size, low, high);
		quick_sort_array(arr, size, low, part_idx - 1);
		quick_sort_array(arr, size, part_idx + 1, high);
	}
}

/**
 * partition - the Lomuto partition scheme.
 *
 * @arr: an array of lenght @size.
 * @size: size of the array.
 * @low: the starting index.
 * @high: the ending index.
 *
 * Return: partition Always.
 */
int partition(int *arr, size_t size, int low, int high)
{
	int pivot, idx, j;

	pivot = arr[high];
	idx = low - 1;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			idx++;
			if (idx != j)
			{
				swap(&arr[idx], &arr[j]);
				print_array(arr, size);
			}
		}
	}
	if (idx + 1 != high)
	{
		swap(&arr[idx + 1], &arr[high]);
		print_array(arr, size);
	}
	return (idx + 1);
}

/**
 * swap - swap 2 integer elements in an array.
 * @num1: first integer element.
 * @num2: second integer element.
 */
void swap(int *num1, int *num2)
{
	int temp = *num2;

	*num2 = *num1;
	*num1 = temp;
}
