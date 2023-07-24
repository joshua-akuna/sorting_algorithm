#include "sort.h"
void merge(int *array, size_t start, size_t mid, size_t end);
void merge_sorting(int *array, size_t start, size_t end);

void merge_sort(int *array, size_t size)
{
	merge_sorting(array, 0, size - 1);
}

void merge_sorting(int *array, size_t start, size_t end)
{
	size_t mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sorting(array, start, mid);
		merge_sorting(array, mid + 1, end);
		merge(array, start, mid, end);
	}
}

void merge(int *array, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid + 1, k = start;
	int *temp_array = NULL;

	temp_array = malloc(sizeof(int) * (end + 1));
	if (temp_array == NULL)
		exit(1);

	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
			temp_array[k++] = array[i++];
		else
			temp_array[k++] = array[j++];
	}

	while (i <= mid)
		temp_array[k++] = array[i++];
	while (j <= end)
		temp_array[k++] = array[j++];

	for (i = start; i <= end; i++)
		array[i] = temp_array[i];

	free(temp_array);
}
