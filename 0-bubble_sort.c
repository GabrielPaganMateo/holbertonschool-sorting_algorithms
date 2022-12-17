#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int tmp1, tmp2;

	if (array == NULL || size < 2)
		return;

	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp1 = array[j];
				tmp2 = array[j + 1];
				array[j] = tmp2;
				array[j + 1] = tmp1;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
