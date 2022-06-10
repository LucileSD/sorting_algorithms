#include "sort.h"
/**
 * swap - swaps in a doubly linked list
 * @previous: prev nod of current
 * @current: the current node
 * @list: the head of the list 
 * Return: None
 */
void swap(listint_t *previous, listint_t *current, listint_t *list)
{
	listint_t *tmp = previous->prev;

	if (!tmp)
		list = current;
	
	else
	{
		(void)list;
		tmp->next = current;
		current->prev = tmp;
		previous->prev = current;
		previous->next = current->next;
		current->next = previous;
		
		if (previous->next)
			previous->next->prev = previous;
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order using
 * the insertion sort algorithm
 * @list: the head of the list
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *browse = (*list);

	if (*list)
	{
		while (browse->next)
		{
			if (browse->prev->n > browse->n)
			{
				swap(browse->prev, browse, *list);
				print_list(list);
			}
		}
	}
}
