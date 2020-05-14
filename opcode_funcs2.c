#include "monty.h"

/**
* add - opcode function
* @stack: stack given to add
* @line_number: line number for error
*
* Description: opcode function to add top two values
* Return: 0 success
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
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
*
* Description: function to add node to top of stack
* Return: 0 success
*/

void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int i;
	stack_t *push = malloc(sizeof(stack_t));

	if (push == NULL)
		exit(EXIT_FAILURE);
	i = atoi(num);
	push->n = i;
	if (*stack == NULL)
	{
		(*stack) = push;
		(*stack)->next = NULL;
		return;
	}
	else
	{
		(*stack)->prev = push;
		push->next = (*stack);
		(*stack) = push;
	}
}

