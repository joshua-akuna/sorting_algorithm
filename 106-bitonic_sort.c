#include "sort.h"

void bitonic_sort_algo(int *array, int first, int last, int direction);
void bitonic_merge(int *array, int first, int size, int direction);

void bitonic_sort(int *array, size_t size)
{
        int dir = 1;

        if (array == NULL || size < 2)
                return;

        bitonic_sort_algo(array, 0, size, dir);
}

void bitonic_sort_algo(int *array, int first, int size, int direction)
{
        int mid;

        if (size > 1)
        {
                mid = size / 2;
                bitonic_sort_algo(array, first, mid, 1);
                bitonic_sort_algo(array, first + mid, mid, 0);
                bitonic_merge(array, first, size, direction);
        }
}

void bitonic_merge(int *array, int first, int size, int direction)
{
        int mid = size / 2, i, temp;

        if (size > 1)
        {
                for (i = first; i < first + mid; i++)
                {
                        if ((direction == 1 && array[i] > array[i + mid])
                                || (direction == 0 && array[i] < array[i + mid]))
                        {
                                temp = array[i];
                                array[i] = array[i + mid];
                                array[i + mid] = temp;
                        }
                }
                bitonic_merge(array, first, mid, direction);
                bitonic_merge(array, first + mid, mid, direction);
        }
}
