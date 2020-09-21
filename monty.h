#ifndef MONTY_H
#define MONTY_H

/* Static libraries */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* Macros */

#define BUF_SIZE 2048

/* Definitions */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct args_s - singly linked list
 * @push: pointer that stores what the user writes
 * @top: pointer that begin of the list
 *
 * Description: Shareable arguments of the stack
 * for functions to use
 */
typedef struct args_s
{
	char *push;
	stack_t *top;
} args_t;

extern args_t args;
args_t args;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */

void opcode_push(stack_t **top, unsigned int line_num);
void opcode_pall(stack_t **top, unsigned int line_num);
void opcode_pint(stack_t **top, unsigned int line_num);
void opcode_pop(stack_t **top, unsigned int line_num);
void opcode_swap(stack_t **top, unsigned int line_num);
void opcode_add(stack_t **top, unsigned int line_num);
void opcode_nop(stack_t **top, unsigned int line_num);
void (*get_op(char *s, unsigned int l))(stack_t **top, unsigned int line_num);
FILE *read_file(char *file_name);
void free_stack(stack_t *head);
int is_int(char *str);
char *get_args(char *str);
void opcode_sub(stack_t **top, unsigned int line_num);

#endif /* MONTY_H */
