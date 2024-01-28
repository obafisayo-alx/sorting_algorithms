#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

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
 * heapify - Heapify a subtree rooted with node i
 *
 * @array: Array to be sorted
 * @size: Size of the array
 * @i: Index of the root node
 * @n: Size of the heap
 *
 */
void heapify(int *array, size_t size, int i, int n)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, n);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *			using the Heap sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 *
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
