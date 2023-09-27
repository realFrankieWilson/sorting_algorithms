#include "sort.h"

void swap_head_node(listint_t **, listint_t **, listint_t **);
void swap_buttm_node(listint_t **, listint_t**, listint_t **);

/**
 * cocktail_sort_list -> sorts doubly linked list of integers in ascending
 *			order Using the cocktail shaker sort algorithm
 * @list: the list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	int set_value = 1;
	listint_t *buttm, *shaker;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	for (buttm = *list; buttm->next != NULL;)
		buttm = buttm->next;

	while (set_value == 1)
	{
		set_value = 0;
		for (shaker = *list; shaker != buttm; shaker = shaker->next)
			if (shaker->n > shaker->next->n)
			{
				swap_head_node(list, &buttm, &shaker);
				print_list((const listint_t *)*list);
				set_value = 1;
			}
		for (shaker = shaker->prev; shaker != *list; shaker
				= shaker->prev)
			if (shaker->n < shaker->prev->n)
			{
				swap_buttm_node(list, &buttm, &shaker);
				print_list((const listint_t *)*list);
				set_value = 1;
			}
	}
}


/**
 * swap_buttm_node -> Swaps a node in a doubly linked list of integers with
 *			with the node behind.
 * @head: Pointer to the head of a doubly linked list of integers.
 * @buttm: A pointer to the tail node.
 * @current: A pointer to the current swaping node of the cocktail shaker.
 *
 * Return: Nothing
 */
void swap_buttm_node(listint_t **head, listint_t **buttm, listint_t **current)
{
	listint_t *temp;

	temp = (*current)->prev;

	if ((*current)->next == NULL)
		*buttm = temp;
	else
		(*current)->next->prev = temp;

	temp->next = (*current)->next;
	(*current)->prev = temp->prev;
	if (temp->prev == NULL)
		*head = *current;
	else
		temp->prev->next = *current;

	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}


/**
 * swap_head_node -> Swaps the head node of a doubly linked list of integers
 * @head: A ptr head of the node.
 * @buttm: A ptr to the tail node
 * @current: A ptr to the current swapping node.
 *
 * Return: Nothing.
 */
void swap_head_node(listint_t **head, listint_t **buttm, listint_t **current)
{
	listint_t *temp;

	temp = (*current)->next;

	if ((*current)->prev == NULL)
		*head = temp;
	else
		(*current)->prev->next = temp;

	temp->prev = (*current)->prev;
	(*current)->next = temp->next;

	if (temp->next == NULL)
		*buttm = *current;
	else
		temp->next->prev = *current;

	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}
