#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - removes element from list
 * @stack: stack to remove element
 * @line_number: current line number
 * Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
