#include "monty.h"

/**
 * push_op - add a new value to the top of the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new;

	temp = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		print_err(0, "Error: malloc failed", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	if (av[1] == NULL || !_isint(av[1]))
	{
		print_err(line_number, "usage: push integer", NULL);
		_free(av), _free(line), freestack(new), freestack(top);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(av[1]);
	new->prev = NULL;
	if (temp == NULL)
	{
		new->next = NULL;
	}
	else
	{
		temp->prev = new;
		new->next = temp;
	}
	*stack = new;
}

/**
 * pall_op - prints all the values in the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void pall_op(stack_t **stack, unsigned int line_number)
{
	int index = 0;
	stack_t *temp = *stack;
	char buffer[MAX_BUFFER];

	if (temp != NULL && line_number > 0)
	{
		while (temp->prev)
			temp = temp->prev;
		while (temp)
		{
			num_to_buffer(temp->n, &index, buffer);
			buffer[index++] = '\n';
			temp = temp->next;
		}
		print_buffer(buffer, &index);
	}
}

/**
 * pint_op - prints the value at the top position in the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void pint_op(stack_t **stack, unsigned int line_number)
{
	int index = 0;
	char buffer[MAX_BUFFER];
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		print_err(line_number, "can't pint, stack empty", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	while (temp->prev)
		temp = temp->prev;

	num_to_buffer(temp->n, &index, buffer);
	buffer[index++] = '\n';
	print_buffer(buffer, &index);
}

/**
 * pop_op - removes the top element of the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		print_err(line_number, "can't pop an empty stack", NULL);
		_free(av), _free(line);
		exit(EXIT_FAILURE);
	}

	while (temp->prev)
		temp = temp->prev;

	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	temp->next = NULL;
	freestack(temp);
}

/**
 * swap_op - swaps the value of the top two elements in the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void swap_op(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		print_err(line_number, "can't swap, stack too short", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	tmp = temp->n;
	temp->n = temp->next->n;
	temp->next->n = tmp;
}
