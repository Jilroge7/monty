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
		(*stack)->prev = NULL;
		return;
	}
	else
	{
		(*stack)->prev = push;
		push->next = (*stack);
		(*stack) = push;
	}
}
/**
* sub - opcode function
* @stack: stack given to subtract
* @line_number: line number for error
*
* Description: opcode function to subtract top two values together
* Return: 0 success
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	temp = temp->next;
	temp->n = temp->n - val;
	free(temp->prev);
	temp->prev = NULL;
}
/**
* _div - opcode function
* @stack: stack given to divide
* @line_number: line number for error
*
* Description: opcode function to divide top two values
* Return: 0 success
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	if (val == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	temp->n = val / temp->n;
	free(temp->prev);
	temp->prev = NULL;
}
/**
* mul - function
* @stack: stack given
* @line_number: line_number for error
*
* Description: func to get product of top two from stack
* Return: 0 success
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	temp = temp->next;
	temp->n = val * temp->n;
	free(temp->prev);
	temp->prev = NULL;
}
