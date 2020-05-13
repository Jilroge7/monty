#include "monty.h"

/**
* add_op - opcode function
* @stack: stack given to add
* @line_number: line number for error
*
* Description: opcode function to add top two values
* Return: 0 success
*/

void add(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;

	val = temp->n;
	temp = temp->next;
	temp->n = temp->n + val;
	free(temp->prev);
	temp->prev = NULL;
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

void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
  int i;
  stack_t *push = malloc(sizeof(stack_t));
  
  if (push == NULL)
    return;
  i = atoi(num);
  push->n = i;
	push->prev = NULL;
	push->next = *stack;
	if (stack != NULL)
	  (*stack)->prev = push;
	*stack = push;
}
