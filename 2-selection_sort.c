#include "sort.h"
void swap_value(int *v1, int *v2);

/**
 * selection_sort -> Sorts array of integer using Selection sort in accending
 * order.
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int *ind;

	if (size < 2 || array == NULL)
		return;

	for (; i < size - 1; i++)
	{
		ind = array + i;
		for (j = i; j < size; j++)
			ind = (array[j] < *ind) ? (array + j) : ind;
		if ((array + i) != ind)
		{
			swap_value(array + i, ind);
			print_array(array, size);
		}
	}
}


/**
 * swap_value -> Swaps the position of values
 * @v1: The first value
 * @v2: the second value
 *
 * Return: Swaped values
 */
void swap_value(int *v1, int *v2)
{
	int tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}
