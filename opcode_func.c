#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new;
	
	temp = *stack;
	new = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		_free(av), freestack(top);
		print_err(0, "Error: malloc failed", NULL);
		exit(EXIT_FAILURE);
	}
	if (av[1] == NULL || !_isint(av[1]))
	{
		_free(av), freestack(top);
		print_err(line_number, "usage: push integer", NULL);
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
	temp = new;
}
