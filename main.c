#include "monty.h"

extern unsigned int line_number; /* line number of monty file */

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
  char *buff[1024]
  stack_t **new_stack = malloc(sizeof(stack_t stack));
  if (new_stack == NULL)
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
  if (rmonty == NULL)
    {
      print("Error: Can't open file %s", argv[1]);
      exit(EXIT_FAILURE);
    }
  while(true)
    {
      c = fgets(buff, 255, (FILE*)rmonty);
      if (c == EOF)
	break;
      else:
	parse(c);
    }
  flcose(rmonty);
  return(0);
}
/**
* parse - function
* @char: char to check in string
* @stack: stack given to parse
* @line_number: line number for errors
*
* Description: function to tokenize string
* Return: 0 success
*/
}
void parse(char *c, stack_t **stack, unsigned int line_number)
{
	char delim = ' ';
	stack_t tokens = strtok(c, delim);
	
	while (tokens != null);
	{
		oppcodes(tokens);
		tokens = strtok(null, delim);
	}

}
void oppcodes(char tokens, stack_t new_stack, unsigned int line_number)
{
  int i;
  instruction_t oppcode[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint}.
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop}
    {"NULL", NULL},
  };
  for (i = 0; oppcode[i].opcode != NULL; i++)
    {
      if (oppcode[i].opcode[0] == tokens)
	{
	  oppcode[i].f(new_stack, line_number);
	}
    }
}
