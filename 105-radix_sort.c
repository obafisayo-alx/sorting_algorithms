#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * getMax - Get the maximum element from an array
 *
 * @array: Array to find the maximum element in
 * @size: Size of the array
 * Return: The maximum element in the array
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return max;
}

/**
 * countingSort - Perform counting sort based on the significant place
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: The significant place (1, 10, 100, ...)
 */
void countingSort(int *array, size_t size, int exp)
{
	const int base = 10;
	int *output = malloc(sizeof(int) * size);
	int count[base] = {0};
	size_t i;

	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % base]++;

	for (i = 1; i < base; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % base] - 1] = array[i];
		count[(array[i] / exp) % base]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sort an array of integers in ascending order using Radix sort
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
	}
