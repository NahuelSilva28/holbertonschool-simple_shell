/* main.c */
#include "main.h"

/**
* main - Entry point of the program
*
* Runs in a loop, printing the prompt, reading a line of input,
* parsing the line into arguments,
* and executing the command with the arguments.
*
* Return: Always returns 0.
*/
int main(void)
{
char *line;
char **args;
int status;

	do

	{
		printf(" :) shell > ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);/* Free the memory allocated for the input line */
		free(args);/* Free the memory allocated for the argument array */

	} while (status);

return (EXIT_SUCCESS);/* Loop until the user enters "exit" */
}
