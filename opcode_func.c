#include "monty.h"

/**
 * push - add a new value to the top of the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void push(stack_t **stack, unsigned int line_number)
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
 * pall - prints all the values in the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void pall(stack_t **stack, unsigned int line_number)
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
