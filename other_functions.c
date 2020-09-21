#include "monty.h"

/**
 * opcode_sub - sub the top two elements of the stack
 * @top: top node in the stack
 * @line_num: line number
 *
 * Description: the result is stored in the second top element of the stack,
 * and the top element is removed
 * Return: nothing
 */

void opcode_sub(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;

	(void) *top;
	(void) line_num;

	if (*top && (*top)->prev)
	{
		(*top)->prev->n -= (*top)->n;
		*top = (*top)->prev;
		(*top)->next = NULL;
		args.top = *top;
		free(temp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n",
			line_num);
		free_stack(args.top);

		exit(EXIT_FAILURE);
	}
}
    /**
 * opcode_div - div the top two elements of the stack
 * @top: top node in the stack
 * @line_num: line number
 *
 * Description: the result is stored in the second top element of the stack,
 * and the top element is removed
 * Return: nothing
 */

void opcode_div(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;

	(void) *top;
	(void) line_num;

	if ((*top)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_num);
		free_stack(args.top);
	}
	if (*top && (*top)->prev)
	{
		(*top)->prev->n /= (*top)->n;
		*top = (*top)->prev;
		(*top)->next = NULL;
		args.top = *top;
		free(temp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n",
			line_num);
		free_stack(args.top);

		exit(EXIT_FAILURE);
	}
}
