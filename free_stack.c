#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - free a stack
 * @head: the head of the list
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
