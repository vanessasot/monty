#include "monty.h"

int main(void)
{
	stack_t *top;
	int line = 1;

	top = NULL;
	opcode_push(&top, line++);
	opcode_pint(top, line++);
	opcode_push(&top, line++);
	opcode_pint(top, line++);
	opcode_push(&top, line++);
	opcode_pint(top, line++);
	opcode_push(&top, line++);
	opcode_pint(top, line++);
	opcode_push(&top, line++);
	opcode_pint(top, line++);
	opcode_push(&top, line++);
	opcode_pint(top, line++);
	opcode_push(&top, line++);
	opcode_pint(top, line++);
	opcode_push(&top, line++);
	opcode_pint(top, line++);
	printf("-----------------\n");
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_swap(&top, line++);
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_swap(&top, line++);
	opcode_nop(&top, line++);
	printf("-----------------\n");
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(&top, line++);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(&top, line++);

	return (EXIT_SUCCESS);
}
