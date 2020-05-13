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
  stack_t **stack = NULL;
  /*  if (stack == NULL)
    {
      printf("Error: malloc failed");
      exit(EXIT_FAILURE);
      }*/
  if (argc < 2 || argc > 2)
    {
      printf("USAGE: monty file");
      exit(EXIT_FAILURE);
    }
  rmonty = fopen(argv[1], "r");
  if (rmonty == NULL)
    {
      printf("Error: Can't open file %s", argv[1]);
      exit(EXIT_FAILURE);
    }
  while (1)
    {
      c = fgets(buff, 255, (FILE*)rmonty);
      printf("\nfgets: %s\n", c);
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
  printf("in parse\n");
  tokens = strtok(c, delim);
  num = strtok(NULL, delim);
  printf("\n tokens %s\n num %s\n", tokens, num);
  for (i = 0; i < 8; i++)
    {
      printf("in for\n");
      if (_strcmp(code[i].opcode[0], tokens) == 0)
	{
          printf("in the strcmp\n");
          code[i].f(stack, line_number);
	}
    }
  printf("L%d: unknown instruction %s", line_number, tokens);
  exit(EXIT_FAILURE);

}

/**
 * oppcodes - function
 * @token: token to check against oppcode
 * @stack: stack given to oppcodes
 * @line_number: line number for errors
 *
 * Description: function to check tokens against oppcodes
 * Return: 0 success
 */

/*void opcodes(char *tokens, stack_t **stack, unsigned int line_number)
{
  int i;
  instruction_t opcode[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {"NULL", NULL},
  };
  printf("in opcodes\n");
  for (i = 0; opcode[i].opcode != NULL; i++)
    {
      if (_strcmp(opcode[i].opcode[0], tokens) == 0)
	{
	  printf("in the strcmp\n");
	  opcode[i].f(stack, line_number);
	}
    }
  printf("L%d: unknown instruction %s", line_number, tokens);
  exit(EXIT_FAILURE);
  }*/

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
