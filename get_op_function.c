#include "monty.h"

/**
 * get_op - Select the function depending to the opcode.
 * @s: string to check.
 * @l: Line number.
 *
 * Return: If success pointer to function, else EXIT_FAILURE.
 */

void (*get_op(char *s, unsigned int l))(stack_t **top, unsigned int line_num)
{
	instruction_t opcodes[] = {
	    {"push", opcode_push},
	    {"pall", opcode_pall},
	    {"pint", opcode_pint},
	    {"pop", opcode_pop},
	    {"swap", opcode_swap},
	    {"add", opcode_add},
	    {"nop", opcode_nop},
	    {NULL, NULL}};

		size_t i_op;

	for (i_op = 0; opcodes[i_op].opcode; i_op++)
		if (strcmp(opcodes[i_op].opcode, s) == 0)
			return (opcodes[i_op].f);

	free_stack(args.top);
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", l, s);

	exit(EXIT_FAILURE);
}
