#include "monty.h"

/**
 * add_op - adds the value of the top two elements in the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		print_err(line_number, "can't add, stack too short", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	temp->next->n += temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	freestack(temp);
}

/**
 * sub_op - subtracts the top element of the stack from the second top
 *	element of the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void sub_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		print_err(line_number, "can't sub, stack too short", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	temp->next->n -= temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	freestack(temp);
}

/**
 * div_op - divides the second top element of the stack with the
 *	top element of the stack.
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		print_err(line_number, "can't div, stack too short", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		print_err(line_number, "can't div, stack too short", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	temp->next->n /= temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	freestack(temp);
}

/**
 * mul_op - multiplies the second top element of the stack with the
 *	top element of the stack.
 * @stack: points to a pointer to the stack
 *  * @line_number: hold the line number of the current opcode
 */

void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		print_err(line_number, "can't mul, stack too short", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	temp->next->n *= temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	freestack(temp);
}

/**
 * mod_op - computes the rest of the division of the second top element of
 *	the stack by the top element of the stack
 * @stack: points to a pointer to the stack
 * @line_number: hold the line number of the current opcode
 */

void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		print_err(line_number, "can't mod, stack too short", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		print_err(line_number, "division by zero", NULL);
		_free(av), _free(line), freestack(top);
		exit(EXIT_FAILURE);
	}

	temp->next->n %= temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;

	temp->next = NULL;
	freestack(temp);
}
