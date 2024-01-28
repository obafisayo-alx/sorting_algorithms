#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two elements in an array
 *
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * hoare_partition - Hoare partition scheme for Quick Sort
 *
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
ssize_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[low];
	ssize_t i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}


/**
 * quick_sort_hoare_recur - Perform recursive Quick Sort
 *
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_hoare_recur(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		ssize_t pivot = hoare_partition(array, low, high, size);

		quick_sort_hoare_recur(array, low, pivot, size);
		quick_sort_hoare_recur(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 *
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recur(array, 0, size - 1, size);
}
