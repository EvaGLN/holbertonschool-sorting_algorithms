#include "sort.h"
/**
 * insertion_sort_list - Write a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *next, *prev, *before, *after;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node != NULL)
	{
		next = node->next;
		while (node->prev != NULL && node->prev->n > node->n)
		{
			prev = node->prev;
			before = prev->prev;
			after = node->next;
			if (before != NULL)
				before->next = node;
			else
				*list = node;
			node->prev = before;
			node->next = prev;
			prev->prev = node;
			prev->next = after;
			if (after != NULL)
				after->prev = prev;
			print_list(*list);
		}
		node = next;
	}
}
