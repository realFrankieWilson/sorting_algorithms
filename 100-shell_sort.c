#include "sort.h"
void swap_value(int *v1, int *v2);

/**
 * shell_sort -> A function that sorts integer in ascending order, using the
 *		Shell sort alogorithm(using the Knuth sequence)
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t dist, i, j;

	if (size < 2 || array == NULL)
		return;

	for (dist = 1; dist < (size / 3);)
		dist = dist * 3 + 1;

	for (; dist >= 1; dist /= 3)
	{
		for (i = dist; i < size; i++)
		{
			j = i;
			while (j >= dist && array[j - dist] > array[j])
			{
				swap_value(array + j, array + (j - dist));
				j = j - dist;
			}
		}
		print_array(array, size);
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
