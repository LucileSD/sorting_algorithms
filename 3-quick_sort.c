#include "sort.h"
/**
 * @swap_array - swaps 2 elements
 * @a: first element 
 * @b: second element
 */
void swap_array(size_t a, size_t b)
{
	size_t tmp;

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
	int pivot;
	size_t idx, end, new_size;

	if (!array || size < 2)
		return;

	pivot = array[0];
	for (idx = 0; idx < size; idx++)
		;
	end = idx;

	for (idx = 0; idx < size; idx++)
	{
		while(end > idx)
			{
				while (array[idx] <= pivot)
					idx++;
				while (array[end] >= pivot)
					end--;
				if (idx < end)
					swap_array(array[idx], array[end]);
				if (idx > end)
					swap_array(array[end], pivot);
			}
		
		for (idx = 0; array[idx] < pivot; idx++)
		{
			new_size = pivot + 1;
			quick_sort(array, new_size);
		}
		for (idx = pivot + 1; array[end] > pivot; idx++)
		{
			new_size = end + 1;
			quick_sort(array, new_size);
		}
		print_array(array, size);
	}
}
