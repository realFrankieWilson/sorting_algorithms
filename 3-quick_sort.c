#include "sort.h"
void swap_value(int *v1, int *v2);

/**
 * quick_sort -> Sorts an array of integer in ascending order using the quick
 * sort.
 * @array: List/array to be sorted.
 * @size: size of list or array.
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	lomuto = (array, size, 0, size - 1);
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


/**
 * lomuto -> A qucksort algorithm, using recursion.
 * @array: array of integer
 * @size: Size of the array
 * @l: left starting index from the left
 * @r: right stating index from the right
 *
 * Return: Nothing
 */
void lomuto(int *array, size_t size, int l, int r)
{
	int middle;

	if (r - l > 0)
	{
		middle = lumoto_partition(array, size, l, r);
		lumoto(array, size, l, middle -1);
		lumoto(array, size, middle + 1, r);
	}
}


/**
 * lumoto_partition -> Order a subset ot an array of integers, according to
 * 						the lumoto partition(last element as pivot).
 * @array: The array of integers.
 * @size: Size of the array
 * @start: the starting index of the subset to order.
 * @end: the ending index of the subset to order.
 *
 * Return: The partion inex(final element)
 */
int lumoto_partition(int *array, size_t size, int start, int end)
{
	int *high = array + start, middle, down;

	for (middle = down = start; down < end; down++)
		if (array[down] < *high)
		{
			if (middle < down)
			{
				swap_value(array + down, array + middle);
				print_array(array, size);
			}
			middle++;
		}

	if (array[middle] > *high)
	{
		swap_value(array + middle, high);
		print_array(array, size);
	}
	return (middle);
}
