#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: pointer on the array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int biggest;
	int *count, *output;
	size_t idx;

	biggest = array[0];
	for (idx = 0; idx < size; idx++)
	{
		if (array[idx] > biggest)
			biggest = array[idx];
	}
	count = (int *)malloc((biggest + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (idx = 0; idx <= biggest; idx++)
		count[idx] = 0;
	for (idx = 0; idx < size; idx++)
		count[array[idx]]++;

	for (idx = 1; idx <= biggest; idx++)
	{
		count[idx] += count[idx - 1];
		print_array(count, biggest);
	}
	output = (int *)malloc(size * sizeof(int));
	if (output == NULL)
		return;
	for (idx = size - 1; idx; idx--)
	{
		output[count[array[idx]] - 1] = array[idx];
		count[array[idx]]--;
	}
	for (idx = 0; idx < size; idx++)
		array[idx] = output[idx];

	for (idx = 0; idx < biggest; idx++)
		free(count[idx]);
	free(count);
	for (idx = 0; idx < size; idx++)
		free(output[idx]);
	free(output);
}
