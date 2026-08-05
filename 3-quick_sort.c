#include "sort.h"
/**
 * lomuto_partition - partitions an array using the Lomuto scheme,
 * with the last element of the partition as the pivot
 * @array: array of integers
 * @size: size of the array
 * @low: start of partition
 * @high: end of partition
 * Return: index of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot, tmp;
	size_t i, j;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[high])
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - recursively sorts a partition of an array
 * using the quick sort algorithm (lomuto partition scheme)
 * @array: array of integer
 * @size: size of the array
 * @low: start of partition
 * @high: end of partition
 */
void quick_sort_recursive(int *array, size_t size, size_t low, size_t high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, size, low, high);
		if (pivot_index > 0)
			quick_sort_recursive(array, size, low, pivot_index - 1);
		quick_sort_recursive(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Write a function that sorts an array of
 * integers in ascending order using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, size, 0, size - 1);
}
