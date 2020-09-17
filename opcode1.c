#include "monty.h"

/**
 * opcode_push - Adds a new node at the end of a stack.
 * @top: Node of the list.
 * @line_num: Line number.
 * @n: New node valune.
 *
 * Return: Nothing.
 */

void opcode_push(stack_t **top, const int line_num, const int n)
{
	stack_t *new = NULL;
	char buf[2048];
	(void)line_num;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	new->n = n;

	if (!(*top))
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
 * opcode_pall - Prints all the elements of a stack.
 * @top: Node of the list.
 *
 * Return: Nothing.
 */

void opcode_pall(stack_t *top)
{
	char buf[2048];

	while (top)
	{
		sprintf(buf, "%d\n", top->n);
		write(STDOUT_FILENO, buf, strlen(buf));
		top = top->prev;
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

void opcode_pint (stack_t *top, const int line_num)
{
	char buf[2048];

	if (top)
	{
		sprintf(buf, "%d\n", top->n);
		write(STDOUT_FILENO, buf, strlen(buf));
	}
	else
	{
		sprintf(buf, "L%d: can't pint, stack empty\n", line_num);
		write(STDERR_FILENO, buf, strlen(buf));
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_pop - Delete the last element at the stack.
 * @top: Element of the stack.
 * @line_num: Line number.
 *
 * Return: Nothing.
 */

void opcode_pop(stack_t **top, const int line_num)
{
	stack_t *current = *top;
	char buf[2048];

	if (*top == NULL)
	{
		sprintf(buf, "L%d: can't pop an empty stack\n", line_num);
		write(STDERR_FILENO, buf, strlen(buf));
		exit(EXIT_FAILURE);
	}
	if ((*top)->prev != NULL)
	{
		*top = (*top)->prev;
		(*top)->next = NULL;
		free(current);
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
	char buf[2048];

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
		sprintf(buf, "L%d: can't swap, stack too short\n", line_num);
		write(STDERR_FILENO, buf, strlen(buf));
		exit(EXIT_FAILURE);
	}
}
