#include "sort.h"
/**
 * insertion_sort_list - sort doubly linked list
 * @list: pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *Node = NULL, *tmp = NULL, *head = NULL;
	int listlen = 0;

	if (list == NULL || (*list) == NULL)
		return;

	head = *list;
	Node = (*list);
	while (head != NULL)
	{
		head = head->next;
		listlen++;
	}
	if (listlen < 2)
		return;

	while (Node)
	{
		while (Node->next && Node->n > Node->next->n)
		{
			tmp = Node->next;
			Node->next = tmp->next;
			tmp->prev = Node->prev;

			if (Node->prev != NULL)
				Node->prev->next = tmp;
			if (tmp->next != NULL)
				tmp->next->prev = Node;

			Node->prev = tmp;
			tmp->next = Node;

			if (tmp->prev != NULL)
				Node = tmp->prev;
			else
				*list = tmp;

			print_list(*list);
		}
		Node = Node->next;
	}
}
