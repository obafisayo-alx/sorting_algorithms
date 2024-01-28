#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays into a single sorted array
 *
 * @arr: Original array
 * @tp: Temporary array for merging
 * @lt: lt sub-array
 * @ls: Size of the left sub-array
 * @right: Right sub-array
 * @rs: Size of the right sub-array
 */
void merge(int *arr, int *tp, int *lt, size_t ls, int *right, size_t rs)
{
	size_t i = 0, j = 0, k = 0;

	printf("[Merging...]\n[lt]: ");
	print_array(lt, ls);
	printf("[right]: ");
	print_array(right, rs);

	while (i < ls && j < rs)
	{
		if (lt[i] <= right[j])
		{
			tp[k++] = lt[i++];
		}
		else
		{
			tp[k++] = right[j++];
		}
	}

	while (i < ls)
		tp[k++] = lt[i++];

	while (j < rs)
		tp[k++] = right[j++];

	printf("[Done]: ");
	print_array(tp, ls + rs);

	for (i = 0; i < ls + rs; i++)
		arr[i] = tp[i];
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
	int *left, *right;
	size_t left_size, right_size;
	size_t mid;

	if (size < 2)
		return;
	mid = size / 2;
	left = array;
	right = array + mid;
	left_size = mid;
	right_size = size - mid;

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
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, size);

	free(temp);
}
