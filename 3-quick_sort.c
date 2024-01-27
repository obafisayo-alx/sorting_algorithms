#include "sort.h"
#include <sys/types.h>

/**
 * swap - swaps the two values, "left" and "right"
 *
 * @left: the value on the left
 * @right: the value on the right
 * Return: void
*/
void swap(int *left, int *right)
{
	int temp;

	temp = *left;
	*left = *right;
	*right = temp;
}

/**
 * median_of_three - selects the median of three elements
 *
 * @array: array containing elements
 * @low: index of the low element
 * @mid: index of the middle element
 * @high: index of the high element
 * Return: index of the median element
 */
size_t median_of_three(int *array, ssize_t low, ssize_t mid, ssize_t high)
{
	if ((array[low] <= array[mid] && array[mid] <= array[high]) ||
		(array[high] <= array[mid] && array[mid] <= array[low]))
		return mid;
	else if ((array[mid] <= array[low] && array[low] <= array[high]) ||
			(array[high] <= array[low] && array[low] <= array[mid]))
		return low;
	else
		return high;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: array to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: index of the pivot element after partitioning
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	size_t pivot_index;
	int pivot;
	ssize_t i, j;

	pivot_index = median_of_three(array, low, (low + high) / 2, high);
	pivot = array[pivot_index];

	swap(&array[pivot_index], &array[high]);
	print_array(array, size);

	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 *
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 */
void quick_sort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending
 *              order using the Quick Sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
