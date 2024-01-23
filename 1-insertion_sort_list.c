#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * 					order using the Insertion Sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		key = current;
		temp = current->prev;

		while (temp != NULL && temp->n > key->n)
		{
			temp->next = key->next;
			if (temp->next != NULL)
				temp->next->prev = temp;

			key->prev = temp->prev;
			key->next = temp;
			temp->prev = key;

			if (key->prev != NULL)
				key->prev->next = key;
			else
				*list = key;

			print_list(*list);

			temp = key->prev;
		}

		current = current->next;
	}
}
