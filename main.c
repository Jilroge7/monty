#include "monty.h"

/**
 * main - main function of monty interpreter
 * argv: list of arguments
 * argc: argument count
 *
 * Return: nothing
 */

int main(int argc, char *argv[])
{
  FILE *rmonty;
  char c;
  char *buff[1024]
  stack_t **new_stack = malloc(sizeof(stack_t stack));
  if (new_stack = NULL)
    {
      print("Error: malloc failed");
      exit(EXIT_FAILURE);
    }
  if (argc < 2 || argc > 2)
    {
      print("USAGE: monty file");
      exit(EXIT_FAILURE);
    }
  rmonty = fopen(argv[1], r);
  if (rmonty = NULL)
    {
      print("Error: Can't open file %s", argv[1]);
      exit(EXIT_FAILURE);
    }
  while(true)
    {
      c = fgets(buff, 255, (FILE*)rmonty);
      if (c = EOF)
	break;
      else:
	
    }
  flcose(rmonty);
  return(0);
}

void push(stack_t new_stack, int n)
{
  stack_t *push = malloc(sizeof(stack_t stack));
  push->n = n;
  push->prev = NULL;
  push->next = *new_stack;
  *new_stack->prev = push;
}

void pall(stack_t new_stack)
{

}
