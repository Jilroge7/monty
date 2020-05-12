#include "monty.h"
/**
 * pop - pop out a stack
 * stack: the stack to pop out of
 * line_number: line number for error code
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
  if (*stack != NULL)
    {
      *stack = (*stack)->next;
      (*stack)->prev = NULL;
    }
}

/**
 * swap - swap top two elements of stack
 * stack: the stack to swap
 * line_number: line number for error code
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
  int temp = (*stack)->n;
  (*stack)->n = (*stack)->next->n;
  (*stack)->next->n = temp;

}


/**
* pall_op - opcode function
* @stack_head: stack given to print
*
* Description: opcode function to print all stack values beginning at top
* Return: 0 success
*/
void pall_op(stack_t **stack_head)
{

	while (stack_head != NULL)
	{
		printf("%d\n", stack_head->n);
		stack_head = stack_head->next;
	}
}
/**
* pint_op - opcode function
* @stack_head: stack given to print
*
* Description: opcode function to print stack value on top
* Return: 0 success
*/
void pint_op(stack_t *stack_head)
{
	printf("%d\n", stack_head->n);
}
