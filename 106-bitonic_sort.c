#include "sort.h"
void swap_value(int *v1, int *v2);
void b_merge(int *array, size_t size, size_t head, size_t block, char dir);
void b_sequence(int *array, size_t size, size_t head, size_t block, char dir);

/**
 * bitonic_sort -> Sorts the integers in ascending order using the Bitonic
 *				Sort Algorithm
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	b_sequence(array, size, 0, size, 1);
}


/**
 * b_sequence -> Converts an array of integers into a bitonic sequence
 * @array: An array of integers.
 * @size: size of the array.
 * @head: Starting index of the building bitonic seq
 * @block: Size of the block of the building seq.
 * @dir: The direction to sort the bitonic seq in block.
 *
 * Return: Nothing.
 */
void b_sequence(int *array, size_t size, size_t head, size_t block, char dir)
{
	size_t bit = block / 2;
	char *buff = (dir == 0) ? "UP" : "DOWN";

	if (block > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", block, size, buff);
		print_array(array + head, block);

		b_sequence(array, size, head, bit, 0);
		b_sequence(array, size, head + bit, bit, 1);
		b_merge(array, size, head, block, dir);

		printf("Result [%lu/%lu] (%s):\n", block, size, buff);
		print_array(array + head, block);
	}
}


/**
 * b_merge -> Converts an array of integers into a bitonic sequence
 * @array: An array of integers.
 * @size: size of the array.
 * @head: Starting index of the building bitonic seq
 * @block: Size of the block of the building seq.
 * @dir: The direction to sort the bitonic seq in block.
 *
 * Return: Nothing.
 */
void b_merge(int *array, size_t size, size_t head, size_t block, char dir)
{
	size_t i, j;

	j = block / 2;

	if (block > 1)
	{
		for (i = head; i < head + j; i++)
			if ((array[i] > array[i + j] && dir == 0) || (array[i]
				< array[i + j] && dir == 1))
				swap_value(array + i, array + i + j);

		b_merge(array, size, head, j, dir);
		b_merge(array, size, head + j, j, dir);
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
