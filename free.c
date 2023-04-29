#include "main.h"
/**
*free_tokens - frees the memory allocated for an array of tokens
*@tokens: the array of tokens to free
*Return: void
*/
void free_tokens(char **tokens)
{
int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]); /* free memory allocated for each token */
		i++;
	}
	free(tokens); /* free memory allocated for the tokens array */
}

