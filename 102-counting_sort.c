#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending
 *	order using the Counting sort algoritm.
 * @array: the array of integers to sort.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	size_t idx;
	int *counter_arr = NULL, *temp_arr = NULL;

	if (array == NULL || size < 2)
		return;
	/* find the max element in array to determine the size of counter_arr */
	max = array[0];
	for (idx = 0; idx < size; idx++)
		if (array[idx] > max)
			max = array[idx];
	counter_arr = malloc(sizeof(int) * (max + 1));
	if (counter_arr == NULL)
		return;
	/* initialize the elements of counter_arr to 0 */
	for (i = 0; i <= max; i++)
		counter_arr[i] = 0;
	/* count the number of of occurence of each element in array */
	for (idx = 0; idx < size; idx++)
		counter_arr[array[idx]]++;
	/* calculate and print the accumulation of the counter_arr */
	for (i = 0; i <= max; i++)
		counter_arr[i] += counter_arr[i - 1];
	print_array(counter_arr, max + 1);
	temp_arr = malloc(sizeof(int) * size);
	if (temp_arr == NULL)
	{
		free(counter_arr);
		return;
	}
	for (idx = 0; idx < size; idx++)
	{
		temp_arr[counter_arr[array[idx]] - 1] = array[idx];
		counter_arr[array[idx]] -= 1;
	}
	/* rearrange the original array based on counter_arr */
	for (idx = 0; idx < size; idx++)
		array[idx] = temp_arr[idx];
	free(temp_arr);
	free(counter_arr);
}
