#include "monty.h"

/**
 * _isint - checks if a string holds integers as charaters
 * @str: points to the string
 *
 * Return: 1 if all the characters are number and 0 if not
 */

int _isint(char *str)
{
	int i = 0, len = _strlen(str);

	if (str[i] == '-')
		i++;

	for (i = i; i < len; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);

	return (1);
}
