#include "sort.h"
/**
 * bubble_sort - sorts an array in ascending order with bubble sort algorithm
 * @array: the array wich need to be sorted
 * @size: the sise of the array
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
	int tmp = 0;
	size_t pass;
	size_t elem;

	for (pass = 1; pass < size; pass++)
	{
		for (elem = 0; elem < size - 1; elem++)
		{
			if (array[elem] > array[elem + 1])
			{
				tmp = array[elem];
				array[elem] = array[elem + 1];
				array[elem + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
