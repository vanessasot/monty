#include "monty.h"

int main(int ac, char **av)
{
	stack_t *top;
	unsigned int line_num = 1;
	char *line = NULL, *arg = NULL;
	size_t len = 0;
	int i;
	FILE *fd;
	args.push = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = read_file(*av[1]);

	top = NULL;
	while (getline(&line, &len, fd) != EOF)
	{
		arg = get_args(line);
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(arg, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&top, line_num);
				break;
			}
		}
		if (opcodes[i].opcode == NULL && arg != NULL)
		{
			dprintf(STDERR_FILENO,
				"L%d: unknown instruction %s\n",
				line_num, arg);
			free(line);
			free(arg);
			line = NULL;
			arg = NULL;
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	free(arg);
	line = NULL;
	arg = NULL;
	fclose(fd);
	return (EXIT_SUCCESS);
}
