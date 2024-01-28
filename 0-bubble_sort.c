#include "sort.h"
#include "stdbool.h"

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
 * bubble_sort - swaps two contiguous element that satifies the comparison
 *
 * @array: array to be sorted
 * @size: number of elements in the array
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	bool swapped;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
}
