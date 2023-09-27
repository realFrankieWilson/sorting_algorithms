#include "sort.h"
int max_num(int *list, size_t size);

/**
 * counting_sort -> Sorts integer arrays in ascending order, using the
 *			counting sort algorithm.
 * @array: The array of integer to be sort.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort, i, max;

	if (size < 2 || array == NULL)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;

	max = max_num(array, size);

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sort[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];
	free(sort);
	free(count);
}


/**
 * max_num -> Returns the maximum number of a list
 * @size: size of the list
 * @list: the list of arrays
 *
 * Return: A maximum integer of a list
 */
int max_num(int *list, size_t size)
{
	int max;
	size_t i = 1;

	for (max = list[0]; i < size; i++)
	{
		if (list[i] > max)
			max = list[i];
	}
	return (max);
}
