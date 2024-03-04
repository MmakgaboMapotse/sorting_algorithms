#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @node1: A pointer to the first node to swap.
 * @node2: The second node to swap.
 *
 * Return: void
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1 == node2)  /* No need to swap if the nodes are the same */
		return;

	/* Adjust next pointers */
	if (node1->next == node2)
	{
		node1->next = node2->next;
		if (node2->next != NULL)
			node2->next->prev = node1;
		node2->prev = node1->prev;
		node2->next = node1;
		node1->prev = node2;
		if (node2->prev != NULL)
			node2->prev->next = node2;
		else
			*head = node2;
	}
	else
	{
		node1->prev->next = node2;
		if (node2->next != NULL)
			node2->next->prev = node1;
		else
			*head = node1;
		node2->prev->next = node1;
		node1->next->prev = node2;

		/* Swap prev pointers */
		listint_t *temp = node1->prev;

		node1->prev = node2->prev;
		node2->prev = temp;

		/* Swap next pointers */
		temp = node1->next;
		node1->next = node2->next;
		node2->next = temp;
	}
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *insertion_point;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		insertion_point = current;
		while (i != *list && i->n < i->prev->n)
		{
			swap_nodes(list, insertion_point, insertion_point->prev);
			print_list(*list);
			insertion_point = insertion_point->prev;
		}
	}
}
