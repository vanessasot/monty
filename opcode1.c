#include "monty.h"

/**
 * opcode_push - adds a new node at the end of a stack
 * @top: last node in the stack
 * @line_num: line number
 *
 * Return: nothing
 */

void opcode_push(stack_t **top, unsigned int line_num)
{
	stack_t *new;
	int n;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_stack(*top);
		*top = NULL;
		exit(EXIT_FAILURE);
	}

	new->next = NULL;

	if (is_int(args.push))
	{
		n = atoi(args.push);
		new->n = n;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n",
			line_num);
		free_stack(*top);
		*top = NULL;
		exit(EXIT_FAILURE);
	}

	if (!*top)
	{
		new->prev = NULL;
		*top = new;
	}
	else
	{
		new->prev = *top;
		(*top)->next = new;
		*top = new;
	}
}

/**
 * opcode_pall - prints all the elements of a stack
 * @top: last node in the list
 * @line_num: line number
 *
 * Return: Nothing.
 */

void opcode_pall(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;
	(void)line_num;

	while (temp)
	{
		dprintf(STDOUT_FILENO, "%d\n", temp->n);
		temp = temp->prev;
	}
}

/**
 * opcode_pint - prints the value at the top of the stack,
 * followed by a new line
 * @top: last node in the stack
 * @line_num: line number
 *
 * Return: nothing
 */

void opcode_pint(stack_t **top, unsigned int line_num)
{
	if (*top)
	{
		dprintf(STDOUT_FILENO, "%d\n", (*top)->n);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n",
			line_num);
		free_stack(*top);
		*top = NULL;
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_pop - delete the last element at the stack
 * @top: last node in the stack.
 * @line_num: line number
 *
 * Return: nothing
 */

void opcode_pop(stack_t **top, unsigned int line_num)
{
	stack_t *temp = *top;

	if (!*top)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n",
			line_num);
		free_stack(*top);
		*top = NULL;
		exit(EXIT_FAILURE);
	}
	if ((*top)->prev)
	{
		*top = (*top)->prev;
		(*top)->next = NULL;
		free(temp);
		temp = NULL;
	}
	else
	{
		free(*top);
		*top = NULL;
	}
}

/**
 * opcode_swap - swaps the top two elements of the stack
 * @top: last node in the stack
 * @line_num: line number
 *
 * Return: nothing
 */

void opcode_swap(stack_t **top, unsigned int line_num)
{
	stack_t *temp;

	if (*top && (*top)->prev)
	{
		temp = (*top)->prev;
		(*top)->next = temp;
		(*top)->prev = temp->prev;
		temp->prev->next = *top;
		temp->prev = *top;
		temp->next = NULL;
		*top = temp;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
			line_num);
		free_stack(*top);
		*top = NULL;
		exit(EXIT_FAILURE);
	}
}
