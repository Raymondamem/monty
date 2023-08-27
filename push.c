#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - push data to stack
 * @data: stack data
 * Return: void
*/
void push(data_t *data, stack_t **stack)
{
    stack_t *new_stack = malloc(sizeof(stack_t));

    if (new_stack == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_stack->n = data->operand;
    new_stack->next = *stack;
    new_stack->prev = NULL;
    if (*stack != NULL)
    {
        (*stack)->prev = new_stack;
    }
    *stack = new_stack;
}
