#include "sort.h"
void max(int *array, size_t size, size_t index, size_t r_node);
void swap_value(int *v1, int *v2);

/**
 * heap_sort -> Sorts an array of integers in ascending order
 *				using the heap sort
 *				algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2 || array == NULL)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_value(array, array + i);
		print_array(array, size);
		max(array, size, i, 0);
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


/**
 * max -> Turns a binary tree into a complete a heap.
 * @array: an arry of integers, representing binary tree
 * @size: The size of the array/tree.
 * @index: The index of row of the tree
 * @r_node: The root node of the binary tree.
 *
 * Return: Nothing.
 */
void max(int *array, size_t size, size_t index, size_t r_node)
{
	size_t l = 2 * r_node + 1, r = 2 * r_node + 2, lg = r_node;

	if (l < index && array[l] > array[lg])
		lg = l;

	if (r < index && array[r] > array[lg])
		lg = r;

	if (lg != r_node)
	{
		swap_value(array + r_node, array + lg);
		print_array(array, size);
		max(array, size, index, lg);
	}
}
