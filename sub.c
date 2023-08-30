#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sub - prints the value at the top of the stack
 * @stack: stack to print
 * @line_number: current line number
 * Return: void
*/
void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = NULL;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
    }
    if ((*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
    }
    (*stack)->next->n = (*stack)->next->n - (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
