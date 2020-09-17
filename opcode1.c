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
	char buf[BUF_SIZE];
	int n;

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		sprintf(buf, "Error: malloc failed\n");
		write(STDERR_FILENO, buf, strlen(buf));
		/* free_stack(*top);  Implementar free_stack 
		*top = NULL; */
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	sprintf(buf, "%s", get_argument(line_num));
	if (is_int(buf))
	{
		n = atoi(buf);
		new->n = n;
	}
	else
	{
		sprintf(buf, "L%d: usage: push integer\n", line_num);
		write(STDERR_FILENO, buf, strlen(buf));
		/* free_stack(*top);  Implementar free_stack 
		*top = NULL; */
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
	char buf[BUF_SIZE];
	stack_t *temp = *top;

	while (temp)
	{
		sprintf(buf, "%d\n", temp->n);
		write(STDOUT_FILENO, buf, strlen(buf));
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

void opcode_pint (stack_t **top, unsigned int line_num)
{
	char buf[BUF_SIZE];

	if (*top)
	{
		sprintf(buf, "%d\n", (*top)->n);
		write(STDOUT_FILENO, buf, strlen(buf));
	}
	else
	{
		sprintf(buf, "L%d: can't pint, stack empty\n", line_num);
		write(STDERR_FILENO, buf, strlen(buf));
		/* free_stack(*top);  Implementar free_stack 
		*top = NULL; */
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
	char buf[BUF_SIZE];

	if (!*top)
	{
		sprintf(buf, "L%d: can't pop an empty stack\n", line_num);
		write(STDERR_FILENO, buf, strlen(buf));
		/* free_stack(*top);  Implementar free_stack 
		*top = NULL; */
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
	char buf[BUF_SIZE];

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
		/* free_stack(*top);  Implementar free_stack 
		*top = NULL; */
		exit(EXIT_FAILURE);
	}
}
