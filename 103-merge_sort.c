#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays into a single sorted array
 *
 * @array: Original array
 * @temp: Temporary array for merging
 * @left: Left sub-array
 * @left_size: Size of the left sub-array
 * @right: Right sub-array
 * @right_size: Size of the right sub-array
 */
void merge(int *array, int *temp, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("[Merging...]\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			temp[k++] = left[i++];
		}
		else
		{
			temp[k++] = right[j++];
		}
	}

	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	printf("[Done]: ");
	print_array(temp, left_size + right_size);

	for (i = 0; i < left_size + right_size; i++)
		array[i] = temp[i];
}

/**
 * merge_sort_recursive - Recursive function for the Merge Sort algorithm
 *
 * @array: Array to be sorted
 * @temp: Temporary array for merging
 * @size: Size of the array
 */
void merge_sort_recursive(int *array, int *temp, size_t size)
{
	if (size < 2)
		return;

	size_t mid = size / 2;

	int *left = array;
	int *right = array + mid;
	size_t left_size = mid;
	size_t right_size = size - mid;

	merge_sort_recursive(left, temp, left_size);
	merge_sort_recursive(right, temp, right_size);

	merge(array, temp, left, left_size, right, right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *			the Merge Sort algorithm.
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int *temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, size);

	free(temp);
}
