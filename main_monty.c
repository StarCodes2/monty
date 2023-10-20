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
	FILE *strm;

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

	readfile(strm);
	fclose(strm);

	return (0);
}

/**
 * readfile - reads a file from file stream line by line to get opcodes
 * @strm: points to the file stream
 */

void readfile(FILE *strm)
{
	unsigned int line_number = 0;
	size_t size;

	while (getline(&line, &size, strm) != -1)
	{
		line_number++;
		av = line_av(line, " \n");
		if (av != NULL)
		{
			if (av[0][0] != '#' && _strcmp(av[0], "nop"))
				opcode_handler(line_number);
		}
		_free(av);
		av = NULL;
	}
	_free(av), _free(line), freestack(top);
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
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"rotl", rotl_op},
		{"rotr", rotr_op},
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
