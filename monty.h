#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int _write(int fd, char *text);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void print_err(int line_num, char *msg, char *suffix);
char *intstr(int line_num);
void _free(void *mem);
void opcode_handler(char **av, unsigned int line_number);
char **line_av(char *s, char *deli);
int word_count(char *s, char *deli);
int compare_cs(char c, char *s);
int _isint(char *str);

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
void push(stack_t **stack, unsigned int line_number);

extern stack_t *top;
extern char **av;
extern char *line;

#endif /* MONTY_H */
