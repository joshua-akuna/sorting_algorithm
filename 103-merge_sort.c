#include "sort.h"
void merge(int *array, int *temp, size_t start, size_t mid, size_t end);
void merge_sorting(int *array, int *temp, size_t start, size_t end);

/**
 * merge_sort - sorts an array of integers using the merge sort
 *	algorithm.
 * @array: an array of integers.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array == NULL || size < 2)
		return;
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	merge_sorting(array, temp, 0, size);
	free(temp);
}

/**
 * merge_sorting - a recursive function that splits the array argument into
 *	sub arrays and merges them in a sorted order.
 * @array: an array of integers to sort.
 * @temp: a buffer to temporarily store the sorted integer values.
 * @start: start of the sub array to merge in a sorted order;
 * @end: end of the sub array to merge in a sorted order.
 */
void merge_sorting(int *array, int *temp, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = start + (end - start) / 2;
		merge_sorting(array, temp, start, mid);
		merge_sorting(array, temp, mid, end);
		merge(array, temp, start, mid, end);
	}
}

/**
 * merge - merges the subarrays from start to mid and mid + 1 to end in
 *	a sorted manner.
 * @array: an array of integers to sort.
 * @temp: a temporary buffer to store the sorted array of integers.
 * @start: the starting index of the first sub array.
 * @mid: the last index of the first sub array and mid + 1 is the starting
 *	index of the second sub array.
 * @end: the last index of the second sun array.
 */
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	while (i < mid && j < end)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];
	while (j < end)
		temp[k++] = array[j++];

	k = 0;
	for (i = start; i < end; i++)
		array[i] = temp[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
