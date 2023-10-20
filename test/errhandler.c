#include "monty.h"

/**
 * print_err - handles the error message output
 * @line_num: contains the line number where an error occur
 * @msg: points to the error message
 * @suffix: points to the text to be printed after msg
 */

void print_err(int line_num, char *msg, char *suffix)
{
	int len = 0;
	char *numstr = NULL, *errmsg = NULL;

	if (line_num < 1 && msg == NULL && suffix == NULL)
		return;

	if (line_num > 0)
	{
		numstr = intstr(line_num);
		len += _strlen(numstr);
	}
	if (suffix != NULL)
		len += _strlen(suffix);
	len += _strlen(msg);
	len += 2;

	errmsg = malloc(sizeof(char) * len);
	if (errmsg == NULL)
	{
		_write(STDERR_FILENO, "Error: malloc failed");
		_free(av), _free(line), _free(numstr), freestack(top);
		exit(EXIT_FAILURE);
	}

	if (numstr != NULL)
	{
		errmsg = _strcpy(errmsg, numstr);
		errmsg = _strcat(errmsg, msg);
		if (suffix != NULL)
			errmsg = _strcat(errmsg, suffix);
		_free(numstr);
	}
	else
	{
		errmsg = _strcpy(errmsg, msg);
		if (suffix != NULL)
			errmsg = _strcat(errmsg, suffix);
	}
	errmsg = _strcat(errmsg, "\n");
	_write(2, errmsg), _free(errmsg);
}
