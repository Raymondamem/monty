#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * select_instruction - selects instruction function to run
 * @opcode: opcode to find and run
 * Return: function pointer
*/
void (*select_instruction(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};

	while (1)
	{
		if (instructions[i].opcode == NULL)
			return (NULL);
		if (strcmp(instructions[i].opcode, opcode) != 0)
		{
			i++;
			continue;
		}
		return (instructions[i].f);
	}
	return (NULL);
}
