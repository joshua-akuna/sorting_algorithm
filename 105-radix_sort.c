#include "sort.h"

void count_sort_algo(int *array, int size, int exp);

/**
 * radix_sort - sorts the array of integers in ascending order.
 * @array: the array of integers.
 * @size: size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, i;
	
	if (array == NULL && size < 2)
		return;

	max = array[0];
	for (i = 0; i < (int) size; i++)
		if (array[i] > max)
			max = array[i];
	
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort_algo(array, size, exp);
		print_array(array, size);
	}
}

/**
 * count_sort_algo - perform counting sort of the array according
 *	to the digit represented by the exponent exp.
 * @array: the array of integers to sort.
 * @size: of the the array.
 * @exp: exponent used to sort the array.
 */ 
void count_sort_algo(int *array, int size, int exp)
{
        int *output, *count;
        int i;

        output = malloc(size * sizeof(int));
        if (!output)
                exit(1);

        count = malloc(10 * sizeof(int));
        if (!count)
        {
                free(output);
                exit(1);
        }

        for (i = 0; i < 10; i++)
                count[i] = 0;

        for (i = 0; i < size; i++)
                count[(array[i] / exp) % 10]++;

        for (i = 0; i < 10; i++)
                count[i] += count[i - 1];

        for (i = size - 1; i >= 0; i--)
        {
                output[count[(array[i] / exp) % 10] - 1] = array[i];
                count[(array[i] / exp) % 10]--;
        }

        for (i = 0; i < size; i++)
                array[i] = output[i];
        free(output);
        free(count);
}
