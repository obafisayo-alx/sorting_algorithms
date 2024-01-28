#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *				the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i, idx;
	int max, *count;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	print_array(count, max + 1);
	idx = 0;
	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0) {
			array[idx++] = i;
			count[i]--;
		}
	}
	free(count);
}
