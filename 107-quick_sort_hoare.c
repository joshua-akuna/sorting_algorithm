#include "sort.h"

void quick_sorting_hoare(int *arr, size_t size, int low, int high);
int partition_hoare(int *arr, size_t size, int low, int high);
void swap_hoare(int *num1, int *num2);

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 *	using the Quick sort algorithm.
 * @array: the array of integers to be sorted.
 * @size: size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sorting_hoare(array, size, 0, size - 1);
}

/**
 * quick_sorting_hoare - a recursive function that sorts an array
 *	of integers using the Quick sort algorithm and the Lomuto
 *	partition scheme.
 * @arr: the array of integers to sort.
 * @size: size of the array.
 * @low: the starting index.
 * @high: the ending index.
 */
void quick_sorting_hoare(int *arr, size_t size, int low, int high)
{
	int part_idx = 0;

	if (low < high)
	{
		part_idx = partition_hoare(arr, size, low, high);
		quick_sorting_hoare(arr, size, low, part_idx - 1);
		quick_sorting_hoare(arr, size, part_idx, high);
	}
}

/**
 * partition_hoare - implementation of the Hoare partition scheme.
 *
 * @arr: an array of lenght @size.
 * @size: size of the array.
 * @low: the starting index.
 * @high: the ending index.
 *
 * Return: partition Always.
 */
int partition_hoare(int *arr, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = arr[high];
	i = low - 1;
	j = high + 1;

	while (i < j)
	{
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);

		if (i < j)
		{
			swap_hoare(&arr[i], &arr[j]);
			print_array(arr, size);
		}
	}
	return (i);
}

/**
 * swap_hoare - swap 2 integer elements in an array.
 * @num1: first integer element.
 * @num2: second integer element.
 */
void swap_hoare(int *num1, int *num2)
{
	int temp = *num2;

	*num2 = *num1;
	*num1 = temp;
}
