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
 * shell_sort -  sorts an array of integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: the array
 * @size: the size of the array
 * Return: None
 */
void shell_sort(int *array, size_t size)
{
	size_t first, second;
	size_t interval = 1;

	while (interval * 3 + 1 < size)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (first = 0; first < size; first++)
		{
			for (second = first + interval; second < size; second++)
			{
				while (array[second - interval] > array[second])
					swap_array(&array[second - interval], &array[second]);
			}
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
