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
 * opcode_pop - Delete the node at index.
 * @stack: Node of the list.
 * @line_number: Position of the node to eliminate.
 *
 * Return: Nothing.
 */

void opcode_pop(stack_t **stack)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		printf("L: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current->prev = current;
		current = current->next;
	}
	if (current == *stack)
		*stack = NULL;
	else
		current->prev->next = NULL;
	
	/** *stack = current->next; */
	free(current);
	current = NULL;
}


