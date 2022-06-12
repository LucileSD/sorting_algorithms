#include "sort.h"
/**
 * selection_sort - sort an array in ascending order
 * with selcetion sort algorithm
 * @array: the array
 * @size: the size of the array
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	size_t idx, elem;
	size_t tmp, min;


	if (!array || size < 2)
		return;

	for (idx = 0; idx < size; idx++)
	{
		min = idx;

		for (elem = idx + 1; elem < size; elem++)
		{
			if (array[elem] < array[min])
				min = elem;
		}

		if (min != idx)
		{
			tmp = array[min];
			array[min] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
