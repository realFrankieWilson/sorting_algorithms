#include "sort.h"
void merge(int *sub, int *temp_ptr, size_t head, size_t tail);
void sort_sub_array(int *sub, int *temp_ptr, size_t head, size_t mid, size_t
		tail);

/**
 * merge_sort -> Sorts an array of integers in ascending order using the Merge
 *		sort algorithm
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *sort;

	if (size < 2 || array == NULL)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;

	merge(array, sort, 0, size);

	free(sort);
}


/**
 * sort_sub_array -> Sorts a sub array of integers.
 * @sub: A sub array.
 * @temp_ptr: A pointer to the sorted sub array.
 * @head: The head index of the array.
 * @mid: The middle segment of the array.
 * @tail: The last index of the array.
 * 
 * Return: Nothing.
 */
void sort_sub_array(int *sub, int *temp_ptr, size_t head, size_t mid, size_t
		tail)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + head, mid - head);

	printf("[right]: ");
	print_array(sub + mid, tail - mid);

	for (i = head, j = mid; i < mid && j < tail; k++)
		temp_ptr[k] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];

	for (; i < mid; i++)
		temp_ptr[k++] = sub[i];

	for (; j < tail; j++)
		temp_ptr[k++] = sub[j];

	for (i = head, k = 0; i < tail; i++)
		sub[i] = temp_ptr[k++];

	printf("[Done]: ");
	print_array(sub + head, tail - head);
}


/**
 * merge -> Implements the merge sort algorithm through recursion
 * @sub: A sub array.
 * @temp_ptr: A ptr to the sorted array.
 * @head: The front index
 * @tail: the rear index of the sub array.
 *
 * Return: Nothing
 */
void merge(int *sub, int *temp_ptr, size_t head, size_t tail)
{
	size_t tmp;

	if (tail - head > 1)
	{
		tmp = head + (tail - head) / 2;
		merge(sub, temp_ptr, head, tmp);
		merge(sub, temp_ptr, tmp, tail);
		merge(sub, temp_ptr, tmp, tail);
	}
}
