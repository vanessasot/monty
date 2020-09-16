#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

stack_t *add_dnodeint_end(stack_t **top, const int n);
void print_dlistint(const stack_t *t);

int main(void)
{
	stack_t *top;
	int line = 1;

	top = NULL;
	add_dnodeint_end(&top, 0);
	opcode_print(top, line++);
	add_dnodeint_end(&top, 1);
	opcode_print(top, line++);
	add_dnodeint_end(&top, 2);
	opcode_print(top, line++);
	add_dnodeint_end(&top, 3);
	opcode_print(top, line++);
	add_dnodeint_end(&top, 4);
	opcode_print(top, line++);
	add_dnodeint_end(&top, 98);
	opcode_print(top, line++);
	add_dnodeint_end(&top, 402);
	opcode_print(top, line++);
	add_dnodeint_end(&top, 1024);
	opcode_print(top, line++);
	print_dlistint(top);
	printf("-----------------\n");
	opcode_swap(&top, line);
	print_dlistint(top);
	printf("-----------------\n");
	opcode_swap(&top, line);
	print_dlistint(top);

	return (EXIT_SUCCESS);
}

stack_t *add_dnodeint_end(stack_t **top, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*top == NULL)
	{
		new_node->prev = NULL;
		*top = new_node;
		return (*top);
	}

	new_node->prev = *top;
	(*top)->next = new_node;
	*top = new_node;
	return (*top);
}

void print_dlistint(const stack_t *t)
{
	while (t)
	{
		printf("%d\n", t->n);
		t = t->prev;
	}
}
