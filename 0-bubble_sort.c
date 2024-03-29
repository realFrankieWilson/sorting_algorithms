#include "sort.h"


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
 * bubble_sort -> Sorts an array of integers in ascending order using the
 * buble sort algorithm.
 * @array: the array to be sorted out.
 * @size: size of the array.
 *
 * Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t ind, lenght = size;

	int set_true = 0;

	if (size < 2 || array == NULL)
		return;

	while (set_true == 0)
	{
		set_true = 1;
		for (ind = 0; ind < lenght - 1; ind++)
		{
			if (array[ind] > array[ind + 1])
			{
				swap_value(array + ind, array + ind + 1);
				print_array(array, size);
				set_true = 0;
			}
		}

		lenght--;
	}

}
