#include "monty.h"

/**
 *read_file - Read text from a file.
 *@filename: Name of the file.
 *
 *Return: Number of letters.
 */

ssize_t read_file(const char *filename)
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

char *separate_string()
{
}

/**
 * free_stack - frees the stack
 * @top: last node in the stack
 *
 * Return: nothing
 */

void free_stack(stack_t *top)
{
	stack_t *temp;

	while (top)
	{
		temp = top;
		top = (top)->prev;
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
	char *numbers = {'0', '1', '2', '3', '4',
			'5', '6', '7', '8', '9'};

	size_t i_num, i_str;
	int is_number;

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
