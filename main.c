#include "monty.h"

char *num = NULL;
unsigned int line_number = 0;
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
  char *c;
  char buff[1024];
  stack_t **stack = malloc(sizeof(stack_t));
  if (stack == NULL)
    {
      fprintf(stderr, "Error: malloc failed");
      exit(EXIT_FAILURE);
    }
  if (argc < 2 || argc > 2)
    {
      fprintf(stderr, "USAGE: monty file");
      exit(EXIT_FAILURE);
    }
  rmonty = fopen(argv[1], "r");
  if (rmonty == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s", argv[1]);
      exit(EXIT_FAILURE);
    }
  while (1)
    {
      c = fgets(buff, 255, (FILE*)rmonty);
      if (c == NULL)
	break;
      line_number++;
      parse(c, stack, line_number);
    }
  fclose(rmonty);
  return (0);
}

/**
 * parse - function
 * @c: char to check in string 
 * @stack: stack given to parse
 * @line_number: line number for errors
 *
 * Description: function to tokenize string
 * Return: 0 success 
 */

void parse(char *c, stack_t **stack, unsigned int line_number)
{
  int i;
  char *delim = " ";
  char *tokens;
  instruction_t code[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {"NULL", NULL},
  };
  tokens = strtok(c, delim);
  num = strtok(NULL, delim);
  for (i = 0; i < 8; i++)
    {
      if (_strcmp(code[i].opcode, tokens) == 0)
	{
	  code[i].f(stack, line_number);
	  return;
	}
    }
  fprintf(stderr, "L%d: unknown instruction %s", line_number, tokens);
  exit(EXIT_FAILURE);

}

int _strcmp(char *s1, char *s2)
{
  int c, r = 0;

  for (c = 0; s1[c] != '\0' && s2[c] != '\0'; c++)
    {
      if (s1[c] != s2[c])
	{
	  r = (s1[c] - s2[c]);
	  return (r);
	}
    }
  return (r);
}
