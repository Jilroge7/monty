#include "monty.h"

/**
 * freelist - free a doubly linked list
 * @stack: head of stack
 *
 * Return: void
 */

void freelist(stack_t **stack)
{
  stack_t *tmp;
  while (*stack != NULL)
    {
      tmp = (*stack)->next;
      free(*stack);
      *stack = tmp;
    }
  free(*stack);
}

