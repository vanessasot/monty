#include "monty.h"

/**
 * opcode_add - adds the top two elements of the stack
 * @top: top in the stack
 * @line_num: line number
 *
 * Description: The result is stored in the second top element of the stack,
 * and the top element is removed
 * Return: Nothing
 */

void opcode_add (stack_t **top, const int line_num)
{
	stack_t *temp = *top;
	char buf[2048];

	if (*top && (*top)->prev)
	{
		(*top)->prev->n += (*top)->n;
		*top = (*top)->prev;
		free(temp);
	}
	else
	{
		sprintf(buf, "L%d: can't add, stack too short\n", line_num);
		write(STDERR_FILENO, buf, strlen(buf));
		exit (EXIT_FAILURE);
	}
}

/**
 * opcode_nop - doesn’t do anything
 *
 * Return: nothing
 */

void opcode_nop (void)
{
	printf("NOP\n");
}
