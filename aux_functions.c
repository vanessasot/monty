#include "monty.h"

/**
 *read_file - Read text from a file.
 *@filename: Name of the file.
 *
 *Return: Number of letters.
 */

FILE *read_file(const char *filename)
{
	FILE *fd;

	fd = fopen(filename, "r+");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
			filename);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * free_stack - frees the stack
 * @top: last node in the stack
 *
 * Return: nothing
 */

void free_stack(void)
{
	stack_t *temp;

	while (args.head)
	{
		temp = args.head;
		args.head = args.head->next;
		free(temp);
	}
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
	if (strcmp(op, "push") == 0)
		args.push = strtok(NULL, " \t\n");
	return (op);
}
