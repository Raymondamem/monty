#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * check_file - check argument count
 * and file extension
 * @argc: argument count
 * Return: void
*/
void check_file(int argc)
{
	/* int filename_len; */

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument list
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	char line[100];
	data_t data = { 0, "\0", "\0", NULL };
	stack_t *main_stack = NULL;

	check_file(argc);
	data.file = fopen(argv[1], "r");
	if (!data.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), data.file))
	{
		data.line_number++;
		if (line[0] == '\n')
			continue;
		if (sscanf(line, "%s %s", data.opcode, data.argument) >= 1)
			run_instruction(&data, &main_stack);
		strcpy(data.opcode, "\0");
		strcpy(data.argument, "\0");
	}
	free_stack(main_stack);
	fclose(data.file);
	return (0);
}
