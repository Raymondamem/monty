#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * run_instruction - run instruction
 * @data: data containing program information
 * @main_stack: program execution stack
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
	if (strcmp(data->opcode, "nop") == 0)
		return;
	instruction = select_instruction(data->opcode);
	if (instruction == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
		data->line_number, data->opcode);
		free_stack(*main_stack);
		fclose(data->file);
		exit(EXIT_FAILURE);
	}
	instruction(main_stack, data->line_number);
}
