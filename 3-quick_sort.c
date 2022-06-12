#include "sort.h"
/**
 * @swap_array - swaps 2 elements
 * @a: first element 
 * @b: second element
 */
void swap_array(int *a, int *b)
{
	int *tmp;

	tmp = a;
	a = b;
	b = tmp;

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
	size_t pivot;
	size_t idx = 0, end = size - 1, new_idx, right_size = 0, left_size = 0;

	if (!array || size < 2)
		return;

	if (idx < end)
		pivot = idx;
	while (idx < end)
	{
		while (array[idx] <= array[end])
			idx++;
		while (array[end] > array[pivot])
			end--;
		if (idx < end)
			swap_array(&array[idx], &array[end]);
	}
	swap_array(&array[pivot], &array[end]);

	for (new_idx = idx; new_idx < pivot; new_idx++)
		right_size++;
	quick_sort(array, right_size);

	for (new_idx = pivot + 1; new_idx < end; new_idx++)
		left_size++;
	quick_sort(array, left_size);
}
