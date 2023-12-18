#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head linked list
 * @counter: line-count
 * @file: pointer to monty files
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rot1", f_rot1},
		{"rotr", f_rotr},
		{"queue", f_queue}
		{"stack", f_stack},
		{NULL, NULL}
	};
	unsigned int x = 0;
	char *op;

	op = strtok(content, "\n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, "\n\t");
	while (opst[x].opcode && op)
	{
		if (strcmp(op, opst[x].opcode) == 0)
		{        opst[x].f(stack, counter);
			return (0);
		}
		x++;
	}
	if (op && opst[x] == NULL)
	{fprintf(stderr, "L%d: unknown instructions %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
