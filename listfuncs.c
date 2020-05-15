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

int whitespace_check(char *str)
{
  int c, d;
  for (c = 0; str[c]; c++)
    {
      if (isspace(str[c]) == 0)
	{
	  d = -1;
	  return (d);
	}
    }
  d = 0;
  return (d);
}
