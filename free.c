#include "main.h"
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

