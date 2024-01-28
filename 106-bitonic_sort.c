#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merge a bitonic sequence in the specified direction
 *
 * @array: Array to be sorted
 * @low: Starting index of the sequence
 * @count: Size of the sequence
 * @dir: Direction of the sequence (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				int temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
				print_array(array, count);
			}
		}

		/* Recursively sort the two halves */
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Perform recursive bitonic sort
 *
 * @array: Array to be sorted
 * @low: Starting index of the sequence
 * @count: Size of the sequence
 * @dir: Direction of the sequence (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order using Bitonic
 *
 * @array: Array to be sorted
 * @size: Size of the array (assumed to be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}
