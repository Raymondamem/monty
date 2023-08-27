#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - push data to stack
 * @data: data to push to stack
 * @stack: stack to add to
 * Return: void
*/
void push(data_t *data, stack_t **stack)
{
	stack_t *new_stack = malloc(sizeof(stack_t));

	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(data->file);
		exit(EXIT_FAILURE);
	}
	if (!is_int(data->argument))
	{
		fprintf(stderr, "L%d:usage: push integer\n", data->line_number);
		free(new_stack);
		free_stack(*stack);
		fclose(data->file);
		exit(EXIT_FAILURE);
	}
	new_stack->n = atoi(data->argument);
	new_stack->next = *stack;
	new_stack->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new_stack;
	}
	*stack = new_stack;
}
