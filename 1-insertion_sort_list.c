#include "sort.h"
#include <stddef.h>
/**
 *insertion_sort_list-function to sort a doubly linked list
 *@list: pointer to doubly linked list struct
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;

	if (list == NULL || (*list) == NULL)
		return;
	if (dlistint_len(*list) < 2)
		return;

	current = (*list);//pointer to first element

	while (current)//loop that iterates through the list from the first element
	{
		while (current->next && current->n > current->next->n)
		{
			//On each iteration it checks if the current element is larger than the next
			//element in the list. If it is, the function swaps the positions of the two elements.
			//The function tge updates the prev pointer of current and the next pointer to temp to point
			//to each other.
			temp = current->next;
			current->next = temp->next;
			temp->prev = current->prev;

			if (current->prev != NULL)
				current->prev->next = temp;

			if (temp->next != NULL)
				temp->next->prev = current;

			current->prev = temp;
			temp->next = current;

			//if the prev pointer is NULL, this means that temp has moved to the front of the list,
			//so the function updates the list pointer to point to temp.
			//The function then moves current to the next element in the list, and the loop continues.
			if (temp->prev != NULL)
				current = temp->prev;
			else
			{
				*list = temp;
			}
			print_list(*list);
		}
		current = current->next;
	}
}
/**
 *dlistint_len-function to get the length of doubly linked list
 *@head: first node
 *Return: length of list
 */
int dlistint_len(listint_t *head)
{
	int len_count = 0;

	while (head != NULL)
	{
		head = head->next;
		len_count++;
	}
	return (len_count);
}
