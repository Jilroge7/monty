#include "monty.h"

/**
 *
 */

void pop(stack_t **new_stack, unsigned int line_number)
{
  if (*stack != NULL)
    {
      *stack = (*stack)->next;
      (*stack)->prev = NULL;
    }
}

void swap(stack_t **new_stack, unsigned int line_number)
{
  int temp = (*stack)->n;
  (*stack)->n = (*stack)->next->n;
  (*stack)->next->n = temp;

}
