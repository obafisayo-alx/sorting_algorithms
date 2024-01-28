#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <sys/types.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *				the Counting Sort algorithm.
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, k, m;
	int max, j, l, *counting_array, *output_array;
	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;
	for (j = 0; j <= max; j++)
		counting_array[j] = 0;

	for (k = 0; k < size; k++)
		counting_array[array[k]]++;
	for (int l = 1; l <= max; l++)
		counting_array[l] += counting_array[l - 1];
	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = output_array[j];
	print_array(counting_array, max + 1);
	free(counting_array);
	free(output_array);
}
