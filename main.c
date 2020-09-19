#include "monty.h"

args_t args;

/**
 * main - initializes monty bytecode interpreter
 * @ac: number of arguments given to interpreter
 * @av: arguments given to interpreter
 *
 * Return: on success EXIT_SUCCESS
 */

int main(int ac, char **av)
{
	FILE *fd;
	stack_t *top = NULL;
	char *line = NULL, *arg = NULL;
	void (*op_func)(stack_t **top, unsigned int line_num);
	size_t len = 0;
	unsigned int line_num = 1;

	args.push = NULL;
	args.top = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = read_file(av[1]);

	while (getline(&line, &len, fd) != EOF)
	{
		arg = get_args(line);
		if (arg)
		{
			op_func = get_op(arg, line_num);
			op_func(&top, line_num);
		}
		line_num++;
	}
	free(line);
	if (args.top)
		free_stack(args.top);
	line = NULL;
	arg = NULL;
	fclose(fd);
	return (EXIT_SUCCESS);
}
