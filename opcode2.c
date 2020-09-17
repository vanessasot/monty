#include "monty.h"

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