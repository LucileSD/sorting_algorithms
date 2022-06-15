#include "sort.h"
/**
 * swap - swaps in a doubly linked list
 * @previous: prev node of current
 * @current: the current node
 * @list: the head of the list
 * Return: None
 */
void swap(listint_t *current, listint_t *previous, listint_t **list)
{
	listint_t *tmp;

	tmp = previous->prev;
	if (tmp)
		tmp->next = current;
	else
		*list = current;

	current->prev = tmp;

	previous->prev = current;
	previous->next = current->next;
	current->next = previous;
	if (previous->next)
		previous->next->prev = previous;
	else
		previous->next = NULL;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *move = NULL;
	int issorted = 1;

	if (!list || !*list || !(*list)->next)
		return;

	move = *list;
	while (issorted)
	{
		issorted = 0;

		while (move->next && move)
		{
			if (move->n > move->next->n)
			{
				swap(move->next, move, list);
				print_list(*list);
				issorted = 1;
				move = move->prev;
			}
			move = move->next;
		}
		move = move->prev;

		while (move->prev && move)
		{
			if (move->n < move->prev->n)
			{
				swap(move, move->prev, list);
				print_list(*list);
				issorted = 1;
				move = move->next;
			}
			move = move->prev;
		}
		move = move->next;
	}
}
