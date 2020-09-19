#include "monty.h"

/**
 * get_op_function - Select the function depending to the opcode.
 * @line_n: Line number of file.
 *
 * Return: 0 (success).
 */

void (*get_op_function(char *str, unsigned int line_num))(stack_t **top, unsigned int line_num)
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
	int index_op = 0;

	while (opcodes[index_op].opcode)
	{
		if (strcmp(opcodes[index_op].opcode, str) == 0)
		{
			return (opcodes[index_op].f);
		}
		index_op++;
	}
	dprintf(STDERR_FILENO, "L%d: unknown instruction\n", line_num);
	free_stack();
	exit(EXIT_FAILURE);
}
