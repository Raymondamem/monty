#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * run_instruction - run instruction
 * @opcode: opcode to find and run
 * @operand: operand to excute
 * @line_number: current line number
 * Return: void
*/
void run_instruction(data_t *data, stack_t **main_stack)
{
	void (*instruction)(stack_t **, unsigned int);

	if (strcmp(data->opcode, "push") == 0)
	{
		push(data, main_stack);
		return;
	}
	instruction = select_instruction(data->opcode);
	if (instruction == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s", data->line_number, data->opcode);
		exit(EXIT_FAILURE);
	}
	instruction(main_stack, data->line_number);
}
