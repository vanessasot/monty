#include "monty.h"

/**
 * opcode_mod - mod the top two elements of the stack
 * @top: top node in the stack
 * @line_num: line number
 *
 * Description: the result is stored in the second top element of the stack,
 * and the top element is removed
 * Return: nothing
 */

void opcode_mod(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;

	if (*top && (*top)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_num);
		free_stack(args.top);
		exit(EXIT_FAILURE);
	}

	if (*top && (*top)->prev)
	{
		(*top)->prev->n %= (*top)->n;
		*top = (*top)->prev;
		(*top)->next = NULL;
		args.top = *top;
		free(temp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n",
			line_num);
		free_stack(args.top);
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @top: last node in the stack
 * @line_num: line number
 *
 * Return: nothing
 */

void opcode_pchar(stack_t **top, unsigned int line_num)
{
	if (*top)
	{
		if ((*top)->n >= 0 && (*top)->n <= 127)
			dprintf(STDOUT_FILENO, "%c\n", (*top)->n);
		else
		{
			free_stack(args.top);
			dprintf(STDERR_FILENO, 
				"L%d: can't pchar, value out of range\n",
				line_num);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free_stack(args.top);
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n",
			line_num);
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @top: last node in the stack
 * @line_num: line number
 *
 * Return: nothing
 */

void opcode_pstr(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;
	(void) line_num;

	if (temp)
		while (temp && temp->n > 0 && temp->n <= 127)
		{
			dprintf(STDOUT_FILENO, "%c", temp->n);
			temp = temp->prev;
		}

	dprintf(STDOUT_FILENO, "\n");
}

/**
 * opcode_rotl - rotates the stack to the top
 * @top: last node in the stack
 * @line_num: line number
 *
 * Description: The top element of the stack becomes the last one, and the
 * second top element of the stack becomes the first one
 * Return: nothing
 */

void opcode_rotl(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;
	(void) line_num;

	if (*top && (*top)->prev)
	{
		while (temp->prev)
			temp = temp->prev;

		args.top = (*top)->prev;
		(*top)->prev->next = NULL;
		temp->prev = *top;
		(*top)->next = temp;
		(*top)->prev = NULL;
		*(top) = args.top;
	}
}

/**
 * opcode_rotr - rotates the stack to the bottom
 * @top: last node in the stack
 * @line_num: line number
 *
 * Description: The last element of the stack becomes the top element of the
 * stack
 * Return: nothing
 */

void opcode_rotr(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;
	(void) line_num;

	if (*top && (*top)->prev)
	{
		while (temp->prev)
			temp = temp->prev;

		args.top = temp;
		(*top)->next = temp;
		temp->prev = *top;
		temp->next->prev = NULL;
		temp->next = NULL;
		*(top) = args.top;
	}
}
