#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _div - divides the second top element of the stack by the top element of the stack
 * @stack: stack to operate on
 * @line_number: current line number
 * Return: void
 */
void div(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = NULL;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n = (*stack)->next->n / (*stack)->n;
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
