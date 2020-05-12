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
