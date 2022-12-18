#include "sort.h"
#include <stddef.h>
/**
 *selection_sort-function to sort an array in ascending order
 *@array: pointer to array of integers
 *@size: size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, temp, min_index;

	if (array == NULL)
		return;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		if (i != min_index)
			print_array(array, size);
	}
}
