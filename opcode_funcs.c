#include "monty.h"
#define UNUSED __attribute__((unused))
/**
* pop - pop out a stack
* @stack: the stack to pop out of
* @line_number: line number for error code
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
  if (*stack != NULL && (*stack)->next != NULL)
    {
      (*stack) = (*stack)->next;
      (*stack)->prev = NULL;
    }
  else if (*stack != NULL && (*stack)->next == NULL)
    {
      free(*stack);
      return;
    }
  fprintf(stderr, "L%d: can't pop an empty stack/n", line_number);
  exit(EXIT_FAILURE);
}

/**
* swap - swap top two elements of stack
* @stack: the stack to swap
* @line_number: line number for error code
*
* Return: void
*/
void swap(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
* pall - opcode function
* @stack: stack given to print
* @line_number: line number for error
*
* Description: opcode function to print all stack values beginning at top
* Return: 0 success
*/
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		if ((*stack)->next == NULL)
			return;
		(*stack) = (*stack)->next;
	}
}
/**
* pint - opcode function
* @stack: stack given to print
* @line_number: line number for error
*
* Description: opcode function to print stack value on top
* Return: 0 success
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		while ((*stack)->prev != NULL)
			(*stack) = (*stack)->prev;
		printf("%d\n", (*stack)->n);
	}
}
/**
* nop - opcode function
* @stack: stack given
* @line_number: line number for errors
*
* Description: opcode function to do nothing
* Return: 0 success
*/
void nop(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
}
