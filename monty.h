#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>

#define UNUSED(x) (void)(x)

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - hold data passed to functions
 * @line_number: current line number
 * @opcode: the opcode
 * @argument: the argument
 * @file: File object
 *
 * Description: data passed to functions
*/
typedef struct data_s
{
	int line_number;
	char opcode[10];
	char argument[10];
	FILE *file;
} data_t;

int is_int(char *str);
void (*select_instruction(char *opcode))(stack_t**, unsigned int);
void free_stack(stack_t *);
void run_instruction(data_t*, stack_t**);
void push(data_t*, stack_t**);
void pall(stack_t**, unsigned int);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

#endif /* __MONTY_H__ */
