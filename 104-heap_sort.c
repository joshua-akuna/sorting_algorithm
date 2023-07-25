#include "sort.h"

void heapify(int *array, int size);
void sift_down(int *array, int size, int start, int end);

void heap_sort(int *array, size_t size)
{
	int end, temp;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}

void heapify(int *array, int size)
{
	int i = size / 2 - 1;

	while (i >= 0)
	{
		sift_down(array, size, i, size - 1);
		i--;
	}
}

void sift_down(int *array, int size, int start, int end)
{
	int root = start, num, swap, temp;

	while (root * 2 + 1 <= end)
	{
		num = root * 2 + 1;
		swap = root;

		if (array[swap] < array[num])
			swap = num;
		if (num + 1 <= end && array[swap] < array[num + 1])
			swap = num + 1;
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}
