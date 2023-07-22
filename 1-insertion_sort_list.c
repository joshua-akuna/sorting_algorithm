#include "sort.h"

/**
 * insertion_sort - 
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	head = *list;
	head = head->next;
	while (head != NULL)
	{
		node = head;
		while (node->prev && node->n < node->prev->n)
		{
			/* creating a chain between node->prev and node->next */
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;
			
			/* moving the node before the previous node */
			node->next = node->prev;
			node->prev = node->prev->prev;
			node->next->prev = node;

			if (node->prev)
				node->prev->next = node;
			else
				*list = node;
			print_list(*list);
		}
		head = head->next;
	}
}
