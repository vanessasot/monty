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
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
    }
	return (fd);
}

char *separate_string()
{
    
}