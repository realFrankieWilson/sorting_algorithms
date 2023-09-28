#include "sort.h"
void counting(int *array, size_t size, int s, int *temp);
int max_num(int *list, size_t size);

/**
 * radix_sort -> Sorts array in ascending order, using the Radix sort Algorithm
 * @array: The array to be sorted.
 * @size: Size ot the array.
 *
 * Return: Nothing.
 */
void radix_sort(int *array, size_t size)
{
	int m, s, *temp;

	if (size < 2 || array == NULL)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	m = max_num(array, size);
	for (s = 1; m / s > 0; s *= 10)
	{
		counting(array, size, s, temp);
		print_array(array, size);
	}
	free(temp);
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


/**
 * counting -> Sorts integer arrays in ascending order, using the
 *			counting sort algorithm.
 * @array: The array of integer to be sort.
 * @size: Size of the array.
 * @s: The significant digit to sort.
 * @temp: A temp buffer to store the sorted array.
 *
 * Return: Nothing.
 */
void counting(int *array, size_t size, int s, int *temp)
{
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / s) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		temp[count[(array[i] / s) % 10] - 1] = array[i];
		count[(array[i] / s) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];
}
