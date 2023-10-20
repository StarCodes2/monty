#include "monty.h"

/**
 * pchar_op - prints a char using the value at the top of the stack as ascii
 * @stack: points to a pointer to the stack
 *  * @line_number: hold the line number of the current opcode
 */

void pchar_op(stack_t **stack, unsigned int line_number)
{
	char n[3];
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		print_err(line_number, "can't pchar, stack empty", NULL);
		_free(av), _free(line);
		exit(EXIT_FAILURE);
	}

	if (temp->n < 0 || temp->n > 127)
	{
		print_err(line_number, "can't pchar, value out of range", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}
	n[0] = temp->n;
	n[1] = '\n';
	n[2] = '\0';
	_write(STDOUT_FILENO, n);
}

/**
 * pstr_op - prints a string using the values in the stack ascii values
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void pstr_op(stack_t **stack, unsigned int line_number)
{
	int index = 0;
	stack_t *temp = *stack;
	char buffer[MAX_BUFFER];
	(void) line_number;

	if (temp == NULL)
		buffer[index++] = '\n';

	while (temp)
	{
		if (temp->n == 0 || (temp->n < 0 || temp->n > 127))
			break;
		buffer[index++] = temp->n;
		temp = temp->next;

		if (index == MAX_BUFFER - 1)
			print_buffer(buffer, &index);
	}
	buffer[index++] = '\n';
	print_buffer(buffer, &index);
}

/**
 * rotl_op - moves the top element to the bottom of the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *rot, *temp = *stack;
	(void) line_number;

	if (temp == NULL || temp->next == NULL)
		return;

	rot = temp;
	temp = temp->next;
	temp->prev = NULL;
	*stack = temp;

	while (temp->next)
		temp = temp->next;

	temp->next = rot;
	rot->prev = temp;
	rot->next = NULL;
}

/**
 * rotr_op - moves the element at the bottom of the stack to the top
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void rotr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *rot, *temp = *stack;
	(void) line_number;

	if (temp == NULL || temp->next == NULL)
		return;

	while (temp->next)
		temp = temp->next;

	rot = temp;
	temp->prev->next = NULL;

	temp = *stack;

	rot->next = temp;
	temp->prev = rot;
	rot->prev = NULL;

	*stack = rot;
}
