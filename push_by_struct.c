#include "monty.h"

/**
 * stack_push - add a new node to the top of the list
 * @top: points to the first element in the list
 * @new: points to the new element
 */

void stack_push(stack_t **top, stack_t *new)
{
	stack_t *temp = *top;

	new->prev = NULL;
	if (temp == NULL)
	{
		new->next = NULL;
		bottom = new;
	}
	else
	{
		temp->prev = new;
		new->next = temp;
	}

	*top = new;
}

/**
 * queue_push - adds a new element to the bottom of the list
 * @bottom: points to the bottom of the list
 * @new: points to the new element
 */

void queue_push(stack_t **bottom, stack_t *new)
{
	stack_t *temp = *bottom;

	new->next = NULL;
	if (temp == NULL)
	{
		new->prev = NULL;
		top = new;
	}
	else
	{
		temp->next = new;
		new->prev = temp;
	}
	*bottom = new;
}
