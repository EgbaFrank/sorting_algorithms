#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using Insertion sort
 * @list: Pointer to the head of the list
 *
 * Return: Void
 *
*/


void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	head = (*list)->next;

	while (head != NULL)
	{
		current = head;
		while (current->prev != NULL && current->n < current->prev->n)
			swap_node(list, current->prev, current);
		head = head->next;
	}
}

/**
* swap_node - swaps two nodes in a doubly linked list
* @list: Pointer to pointer to the head of the list
* @node1: First node to be swapped
* @node2: Second node to be swapped
*
* Return: Void
*
*/

void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL || node1 == node2)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	print_list(*list);
}
