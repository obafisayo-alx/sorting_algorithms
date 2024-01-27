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
	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	int max = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array and initialize it with zeros */
	int *counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (int i = 0; i <= max; i++)
		counting_array[i] = 0;

	/* Count the occurrences of each element in the input array */
	for (size_t i = 0; i < size; i++)
		counting_array[array[i]]++;

	/* Update the counting array to store the cumulative count */
	for (int i = 1; i <= max; i++)
		counting_array[i] += counting_array[i - 1];

	/* Create a temporary array to store the sorted result */
	int *output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}

	/* Build the sorted array using the counting array */
	for (ssize_t i = size - 1; i >= 0; i--)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}

	/* Copy the sorted array back to the original array */
	for (size_t i = 0; i < size; i++)
		array[i] = output_array[i];

	/* Print the counting array */
	print_array(counting_array, max + 1);

	/* Free the allocated memory */
	free(counting_array);
	free(output_array);
}
