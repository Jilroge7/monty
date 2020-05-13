#include "monty.h"
/**
* add_op - opcode function
* @stack: stack given to add
* @line_number: line number for error
*
* Description: opcode function to add top two values
* Return: 0 success
*/
void add_op(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return (NULL);

	while (temp != NULL)
		temp = temp->next;
	val = temp->n;
	temp = temp->prev;
	temp = temp->n + val;
	temp->next = NULL;
	free(temp);
}
/**
* push - opcode function
* @stack: stack given to add to
* @line_number: line number for error
* @n: data for new node
*
* Description: function to add node to top of stack
* Return: 0 success
*/
void push(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *push = malloc(sizeof(stack_t));

	if (push == NULL)
		return (NULL);
	push->n = n;
	push->prev = NULL;
	push->next = *new_stack;
	if (new_stack != NULL)
		*new_stack->prev = push;
	new_stack = push;
}
