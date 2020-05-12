#include "monty.h"
/**
* pall_op - opcode function
* @stack: stack given to print
* @line_number: line number for error
*
* Description: opcode function to print all stack values beginning at top
* Return: 0 success
*/
void pall_op(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
/**
* pint_op - opcode function
* @stack: stack given to print
* @line_number: line number for error
*
* Description: opcode function to print stack value on top
* Return: 0 success
*/
void pint_op(stack_t **stack_head, __attribute__((unused))unsigned int line_number)
{
	printf("%d\n", (*stack)->n);
}
/**
* nop_op - opcode function
* @stack_head: stack given
* @line_number: line number for errors
*
* Description: opcode function to do nothing
* Return: 0 success
*/
void nop_op(__attribute__((unused))stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
}
/**
* add_op - opcode function
* @stack: stack given to add
* @line_number: line number for error
*
* Description: opcode function to add top two values
* Return: 0 success
*/
void add_op(stack_t **stack_head, __attribute__((unused))unsigned int line_number)
{
	printf("%d\n", (*stack)->n); /*this is a placeholder for this function*/
}
