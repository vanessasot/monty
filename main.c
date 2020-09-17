#include "monty.h"

int main(void)
{
	stack_t *top;
	int line = 1;

	top = NULL;
	opcode_push(&top, line++,0);
	opcode_pint(top, line++);
	opcode_push(&top, line++,1);
	opcode_pint(top, line++);
	opcode_push(&top, line++,2);
	opcode_pint(top, line++);
	opcode_push(&top, line++,3);
	opcode_pint(top, line++);
	opcode_push(&top, line++,4);
	opcode_pint(top, line++);
	opcode_push(&top, line++,98);
	opcode_pint(top, line++);
	opcode_push(&top, line++,402);
	opcode_pint(top, line++);
	opcode_push(&top, line++,1024);
	opcode_pint(top, line++);
	printf("-----------------\n");
	opcode_pall(top);
	printf("-----------------\n");
	opcode_swap(&top, line++);
	opcode_pall(top);
	printf("-----------------\n");
	opcode_swap(&top, line++);
	opcode_nop();
	printf("-----------------\n");
	opcode_pall(top);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(top);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(top);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(top);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(top);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(top);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(top);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(top);
	printf("-----------------\n");
	opcode_add(&top, line++);
	opcode_pall(top);

	return (EXIT_SUCCESS);
}
