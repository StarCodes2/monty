#include "monty.h"

/**
 * freestack - frees the memory allocated to a stack(doubly linked list)
 * @stack: points to the stack
 */

void freestack(stack_t *stack)
{
	void *temp;

	if (stack)
	{
		while (stack->prev)
			stack = stack->prev;

		while (stack->next)
		{
			temp = stack->next;
			free(stack);
			stack = temp;
		}
		free(stack);
	}
}

/**
 * _free - frees a dynamically memory space
 * @mem: points to a memory allocation
 */

void _free(void *mem)
{
	if (mem != NULL)
		free(mem);
}
