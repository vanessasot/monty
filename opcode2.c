#include "monty.h"

/**
 * opcode_add - adds the top two elements of the stack
 * @top: top node in the stack
 * @line_num: line number
 *
 * Description: the result is stored in the second top element of the stack,
 * and the top element is removed
 * Return: nothing
 */

void opcode_add(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;
	char buf[BUF_SIZE];

	if (*top && (*top)->prev)
	{
		(*top)->prev->n += (*top)->n;
		*top = (*top)->prev;
		(*top)->next = NULL;
		free(temp);
	}
	else
	{
		sprintf(buf, "L%d: can't add, stack too short\n", line_num);
		write(STDERR_FILENO, buf, strlen(buf));
		/* free_stack(*top);  Implementar free_stack 
		*top = NULL; */
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_nop - doesn’t do anything
 *
 * Return: nothing
 */

void opcode_nop(stack_t **top, unsigned int line_num)
{
	(void)*top;
	(void)line_num;
	printf("NOP\n");
}
