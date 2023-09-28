#include "sort.h"
void merge_recursive(int *sub, int *temp, size_t head, size_t tail);
void merge_sub(int *sub, int *temp, size_t head, size_t middle, size_t tail);

/**
 * merge_sort -> Sort an array of integers in ascending order using the merge
 *			sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_recursive(array, temp, 0, size);

	free(temp);
}


/**
 * merge_recursive -> Implements the merge sort algorithm through recursion.
 * @sub: sub array of integer to sort
 * @temp: Temporary storage for the sorted result.
 * @head: front index for the sub array.
 * @tail: the tail index of the sub array.
 *
 * Return: Nothing.
 */
void merge_recursive(int *sub, int *temp, size_t head, size_t tail)
{
	size_t middle;

	if (tail - head > 1)
	{
		middle = head + (tail - head) / 2;
		merge_recursive(sub, temp, head, middle);
		merge_recursive(sub, temp, middle, tail);
		merge_sub(sub, temp, head, middle, tail);
	}
}


/**
 * merge_sub -> Sort a sub array.
 * @sub: A sub aray of integers to be sorted.
 * @temp: A temporal buffer to store the sorted array.
 * @head: The front index of an array.
 * @tail: The tail of an array.
 * @middle: The middle index.
 *
 * Return: Nothing.
 */
void merge_sub(int *sub, int *temp, size_t head, size_t middle, size_t tail)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + head, middle - head);
	printf("[right]: ");
	print_array(sub + middle, tail - middle);
	for (i = head, j = middle; i < middle && j < tail; k++)
		temp[k] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];

	for (; i < middle; i++)
		temp[k++] = sub[i];

	for (; j < tail; j++)
		temp[k++] = sub[j];

	for (i = head, k = 0; i < tail; i++)
		sub[i] = sub[k++];

	printf("[Done]: ");
	print_array(sub + head, tail - head);
}
