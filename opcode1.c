#include "monty.h"

/**
 * push - Adds a new node at the beginning of a linked list.
 * @stack: Node of the list.
 * @line_number: Element of the node.
 *
 * Return: Nothing.
 */

void opcode_push(stack_t **stack, unsigned int line_number, const int n)
{
	stack_t *new = NULL;
	(void)line_number;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free(new);
		/**free all*/
		exit (EXIT_FAILURE);
	}

	new->next = NULL;
	new->n = n;

	if (!(*stack))
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->prev = *stack;
		(*stack)->next = new;
		*stack = new;
	}
}

/**
 * pall - Prints all the elements of a linked list.
 * @stack: Node of the list.
 * @line_number: Line number of the file.
 *
 * Return: Nothing.
 */

void opcode_pall(stack_t **stack)
{
	int number;
	stack_t *aux = *stack;

	if (*stack == NULL)
		return;

	for (number = 0; aux != NULL; number++)
	{
		if (aux == NULL)
		{
			return;
		}
		else
		{
			printf("%d\n", aux->n);
		}
		aux = aux->prev;
	}
}

/**
 * opcode_pint - prints the value at the top of the stack,
 * followed by a new line
 * @top: last node in the stack
 * @line_num: line number
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
		exit (EXIT_FAILURE);
	}
}
