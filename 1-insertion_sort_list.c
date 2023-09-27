#include "sort.h"

/**
 * insertion_sort_list -> Sorts a doubly linked list of integers in ascending
 * order using insertion
 * sort Algorithm
 * @list: The list to be sorted
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *loop, *sort, *tmp;

	if ((*list)->next == NULL || *list == NULL || list == NULL)
		return;

	for (loop = (*list)->next; loop != NULL; loop = tmp)
	{
		tmp = loop->next;
		sort = loop->prev;
		while (sort != NULL && loop->n < sort->n)
		{
			sort_function(list, &sort, loop);
			print_list((const listint_t *)*list);
		}
	}
}


/**
 * sort_function -> Sorts two nodes in the doubly linked list.
 * @head: A pointer to the haed of the doubly linked list
 * @first_node: The first node
 * @sec_node: The second node to swap
 *
 * Return: Swaped values of a node.
 */
void sort_function(listint_t **head, listint_t **first_node, listint_t
	*sec_node)
{
	(*first_node)->next = sec_node->next;
	if (sec_node->next != NULL)
		sec_node->next->prev = *first_node;

	sec_node->prev = (*first_node)->prev;
	sec_node->next = *first_node;

	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = sec_node;
	else
		*head = sec_node;
	(*first_node)->prev = sec_node;
	*first_node = sec_node->prev;
}
