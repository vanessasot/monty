#include "monty.h"

int main(int ac, char **av)
{
	stack_t *top = NULL;
	unsigned int line_num = 1;
	char *line = NULL, *arg = NULL;
	size_t len = 0;
	int i;
	void (*op_func)(stack_t **top, unsigned int line_num);
	FILE *fd;
	args.push = NULL;
	args.head = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = read_file(*av[1]);
	
	while (getline(&line, &len, fd) != EOF)
	{
		arg = get_args(line);
		op_func = get_op_function(arg, line_num);
	}
	free(line);
	free(arg);
	line = NULL;
	arg = NULL;
	fclose(fd);
	return (EXIT_SUCCESS);
}
