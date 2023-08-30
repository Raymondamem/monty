#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pint - prints the value at the top of the stack
 * @stack: stack to print
 * @line_number: current line number
 * Return: void
*/
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
    }
    if ((*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
    }
    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
