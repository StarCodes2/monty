#include "monty.h"

char **av = NULL;
char *line = NULL;
stack_t *top = NULL;

/**
 * main - open and read the monty file line by line
 * @argc: contain the number of arguments passed to the program
 * @argv: an array of pointers to all the arguments passed to the program
 *
 * Return: 0 if the last opcode execute without errors
 */

int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	FILE *strm;
	size_t size;

	if (argc != 2)
	{
		print_err(0, "USAGE: monty file", NULL);
		exit(EXIT_FAILURE);
	}

	strm = fopen(argv[1], "r");
	if (strm == NULL)
	{
		print_err(0, "Error: Can't open file ", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &size, strm) != -1)
	{
		line_number++;
		if (line[0] == '#')
			continue;

		av = line_av(line, " \n");
		if (av != NULL)
			opcode_handler(line_number);
		_free(av);
		av = NULL;
	}
	_free(av), _free(line), freestack(top);
	fclose(strm);

	return (0);
}

/**
 * opcode_handler - handles which function to call depending on the opcode
 * @line_number: holds the line number where the current opcode is in the file
 */

void opcode_handler(unsigned int line_number)
{
	int i, check = 0;

	instruction_t instr[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"#", NULL},
		{"nop", NULL},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{NULL, NULL}
	};

	for (i = 0; instr[i].opcode; i++)
	{
		if (_strcmp(instr[i].opcode, av[0]) == 0)
		{
			if (instr[i].f)
				instr[i].f(&top, line_number);
			check = 1;
		}
	}

	if (!check)
	{
		print_err(line_number, "unknown instruction ", av[0]);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}
}

/**
 * _write - write text to standard output or error
 * @fd: contains the file descriptor
 * @text: points to the text to be printed
 *
 * Return: the number of characters printed
 */

int _write(int fd, char *text)
{
	int len = _strlen(text);

	if (len < 1)
		return (0);

	return (write(fd, text, len));
}
