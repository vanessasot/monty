#include "monty.h"

/**
 *read_file - open file.
 *@filename: file name.
 *
 *Return: on success file descriptor, else EXIT_FAILURE.
 */

FILE *read_file(char *file_name)
{
	FILE *fd;

	fd = fopen(file_name, "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
			file_name);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * free_stack - frees the stack
 * @top: first node in the stack
 *
 * Return: nothing
 */

void free_stack(stack_t *top)
{
	stack_t *temp;

	while (top)
	{
		temp = top;
		top = top->prev;
		free(temp);
	}
	args.top = NULL;
}

/**
 * is_int - check if the string is integer
 * @str: string to check
 *
 * Return: 1 if true, 0 if false
 */

int is_int(char *str)
{
	char *numbers = {"0123456789"};

	size_t i_num, i_str;
	int is_number;

	if (str == NULL)
		return (0);

	for (i_str = 0; i_str < strlen(str); i_str++)
	{
		is_number = 0;
		for (i_num = 0; i_num < 10; i_num++)
		{
			if (str[i_str] == numbers[i_num] ||
			    (i_str == 0 && str[i_str] == '-'))
			{
				is_number = 1;
				break;
			}
		}
		if (is_number == 0)
			return (0);
	}
	return (1);
}

/**
 * get_args - get tokens from read line
 * @str: string to get tokens from
 *
 * Return: token
 */
char *get_args(char *str)
{
	char *op;

	op = strtok(str, " \t\n");
	if (op)
		if (strcmp(op, "push") == 0)
			args.push = strtok(NULL, " \t\n");
	return (op);
}
