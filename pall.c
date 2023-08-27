#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pall - print all item in the stack
 * @stack: stack to print
 * @line_number: current line number
 * Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	UNUSED(line_number);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
