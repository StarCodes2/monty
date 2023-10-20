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

	if (str == NULL)
		return (0);
	if (str[i] == '-')
		i++;

	for (i = i; i < len; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);

	return (1);
}

/**
 * num_to_buffer - converts a number to string and stores it in a buffer
 * @num: contains the num
 * @index: points to a variable that holds the buffer's current index
 * @buffer: points to the buffer
 */

void num_to_buffer(int num, int *index, char *buffer)
{
	if (buffer != NULL)
	{
		if (*index == MAX_BUFFER)
			print_buffer(buffer, index);
		if (num < 0)
		{
			num *= -1;
			buffer[*index] = '-';
			*index += 1;
		}

		if (num > 9)
			num_to_buffer(num / 10, index, buffer);
		buffer[*index] = (num % 10) + '0';
		*index += 1;

		if (*index == MAX_BUFFER)
			print_buffer(buffer, index);
	}
}

/**
 * print_buffer - prints the content of a buffer
 * @buffer: points to a buffer
 * @index: points to the buffer's index
 */

void print_buffer(char *buffer, int *index)
{
	if (*index > 0)
		write(STDOUT_FILENO, buffer, *index);
	*index = 0;
}
