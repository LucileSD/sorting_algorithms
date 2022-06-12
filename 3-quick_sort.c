#include "sort.h"
/**
 * swap_array - swaps 2 elements
 * @a: first element
 * @b: second element
 */
void swap_array(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}

/**
 * partition - find the partition position
 * @array: the array
 * @low: the first inex
 * @high: the last index
 * @size: the size if the array
 * Return: i
 */
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low);
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_array(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[high] < array[i])
	{
		swap_array(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * first_quicksort - quicksort to begin the algorithm
 * @array: the array
 * @low: first element in the array
 * @high: last element of the array
 * @size: the size of the array
 * Return: None
 */
void first_quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		first_quicksort(array, low, pivot - 1, size);
		first_quicksort(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: the array
 * @size: the size of the array
 * Return: None
 */
void quick_sort(int *array, size_t size)
{
	int low = 0;
	int high = (size - 1);

	if (!array || size < 2)
		return;

	first_quicksort(array, low, high, size);
}
