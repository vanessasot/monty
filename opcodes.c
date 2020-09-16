#include "monty.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


/**
 * opcode_pint - prints the value at the top of the stack,
 * followed by a new line
 * @top: last node in the stack
 * @line_num: line number
 * Return: nothing
 */
void opcode_pint (stack_t *top, const int line_num)
{
	char buf[2049];

	if (top)
	{
		sprintf(buf, "%d\n", top->n);
		write(STDOUT_FILENO, buf, strlen(buf));
	}
	else
	{
		sprintf(buf, "L%d: can't pint, stack empty\n", line_num);
		write(STDERR_FILENO, buf, strlen(buf));
		exit (EXIT_FAILURE);
	}	
}

/**
 * opcode_swap - swaps the top two elements of the stack
 * @top: last node in the stack
 * @line_num: line number
 * Return: nothing
 */
void opcode_swap (stack_t **top, const int line_num)
{
	stack_t *temp;
	char buf[100];

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
		exit (EXIT_FAILURE);
	}
}

/**
 * opcode_nop - swaps the top two elements of the stack
 * Return: nothing
 */
void opcode_swap (void)
{
}
