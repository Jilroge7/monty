#include "monty.h"
/**
* pall_op - opcode function
* @new_stack - stack given to print
*
* Description: opcode function to print all stack values beginning at top
* Return: 0 success
*/
void pall_op(stack_t *stack_head)
{

	while (stack_head != NULL)
	{
		printf("%d\n", stack_head->n);
		stack_head = stack_head->next;
	}
}
