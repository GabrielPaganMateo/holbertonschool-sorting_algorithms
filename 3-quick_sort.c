#include "sort.h"
/**
 *quick_sort-function too sort an array in ascending order
 *@array: pointer to array
 *@size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	if (array == NULL)
		return;

	quicksort_recursion(array, 0, size - 1, size);
}
/**
 *partition-function to separate array into sub arrays
 *@array: pointer to array
 *@low: lowest index
 *@high: highest index
 *@size: size of array
 *Return: index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; //last element as pivot
	int j;
	int i = low - 1; //index of smaller element and indicates
					 //the right position of pivot

	for (j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (array[j] < pivot)
		{
			i++; //increment index(temporary pivot) of smaller element
			swap(&array[i], &array[j]); //swap the current element with the element
										//at the temporary pivot
			if (i != j)
				print_array(array, size); //only prints as long there is a swap
		}
	}
	swap(&array[i + 1], &array[high]);
	if (array[high] != pivot)
		print_array(array, size); //only prints if the pivot is the last element
	return (i + 1); //return the pivot index
}
/**
 *swap-function to swap values
 *@x: first value
 *@y: second value
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
/**
 *quicksort_recursion-function to make recursive calls to loop over the array
 *@array: pointer to array
 *@low: lowest index
 *@high: highest index
 *@size: size of array
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		//pivot is partitioning index, array[pivot] is now at right place
		int pivot_index = partition(array, low, high, size);

		//separately sort elements before and after partitioning
		quicksort_recursion(array, low, pivot_index - 1, size); //left side of pivot
		quicksort_recursion(array, pivot_index + 1, high, size); //right side of pivot
	}
}
