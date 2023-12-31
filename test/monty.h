#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void readfile(FILE *strm);
int _write(int fd, char *text);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void print_err(int line_num, char *msg, char *suffix);
char *intstr(int line_num);
void _free(void *mem);
void opcode_handler(unsigned int line_number);
char **line_av(char *s, char *deli);
int word_count(char *s, char *deli);
int compare_cs(char c, char *s);
int _isint(char *str);
void num_to_buffer(int num, int *index, char *buffer);
void print_buffer(char *buffer, int *index);

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void freestack(stack_t *stack);
void push_op(stack_t **stack, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
void pchar_op(stack_t **stack, unsigned int line_number);
void pstr_op(stack_t **stack, unsigned int line_number);
void rotl_op(stack_t **stack, unsigned int line_number);
void rotr_op(stack_t **stack, unsigned int line_number);
void stack_push(stack_t **top, stack_t *);
void queue_push(stack_t **bottom, stack_t *);

extern stack_t *top;
extern stack_t *bottom;
extern char **av;
extern char *line;
extern char data_struct;

#define MAX_BUFFER 1024

#endif /* MONTY_H */
