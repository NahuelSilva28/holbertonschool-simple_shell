/* functions.c */
#include "main.h"

/**
* read_line - Reads a line of input from stdin.
*
* Return: A pointer to a buffer containing the line of input.
*/
char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;


	if (getline(&line, &bufsize, stdin) == -1)
	{/* Use getline() to read input from stdin */
		perror("getline");
		exit(EXIT_FAILURE);
	}

return (line);
}

/**
* split_line - split a line into tokens
* @line: the line to split
* @bufsize: a pointer to the size of the buffer
* Return: an array of tokens
*/
char **split_line(char *line)
{
int bufsize = BUFFER_SIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
/* Allocate memory for tokens */
char *token, *saveptr;

	if (!tokens)
	{/* Check if memory allocation failed */
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok_r(line, TOKEN_DELIMITERS, &saveptr);
	/* the first token */
	while (token != NULL)
	{
		tokens[position] = strdup(token);/* Duplicate the token and store it */
		if (!tokens[position])
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}
	position++;

	if (position >= bufsize)
	{/* If too much in the buffer size, reallocate more memory */
		bufsize += BUFFER_SIZE;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		/* Reallocate memory for the tokens array*/
		if (!tokens)
		{
			fprintf(stderr, "Allocation error\n");
			exit(EXIT_FAILURE);
		}
	}

		token = strtok_r(NULL, TOKEN_DELIMITERS, &saveptr);
		/* next token */
	}
		tokens[position] = NULL;
		/* Set the last element of the array to NULL to mark the end of the array */
return (tokens);
}

/**
* exit_shell - Exits the shell.
*
* Return: Nothing.
*/
void exit_shell(void)
{
	printf("Exiting shell...\n");
	exit(EXIT_SUCCESS);
}

/**
* execute - Executes a command with arguments.
* @args: The array of arguments, including the command.
*
* Return: The status code of the executed command.
*/
int execute(char **args)
{
pid_t pid;
int status;

	if (args[0] == NULL)
	{/* Check if no command was entered */
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
	{/* Check for built-in "exit" command */
		exit_shell();
	}

	if (strcmp(args[0], "env") == 0)
	{/* Check for built-in "env" command */
		char **envp = environ;

		while (*envp)
		{
			printf("%s\n", *envp++);
		}
	return (1);
	}

	pid = fork();
	if (pid == 0)
	{
	/* Child process */
		char *env_path = getenv("PATH");
		/* Get the PATH environment variable and split it into tokens */
		char *path_copy = strdup(env_path);
		char *token, *saveptr;

	if (!path_copy)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}

		token = strtok_r(path_copy, ":", &saveptr);
/* Iterate over the tokens and try to execute the command from each directory */
		while (token != NULL)
	{
		char *command_path = malloc(strlen(token) + strlen(args[0]) + 2);
		/* Construct the full path to the command */
		if (!command_path)
		{
			fprintf(stderr, "Allocation error\n");
			exit(EXIT_FAILURE);
		}
		sprintf(command_path, "%s/%s", token, args[0]);
		execve(command_path, args, environ);
		/* Construct the full path to the command */
		free(command_path);
		/* Free the memory used to store the command path */
		token = strtok_r(NULL, ":", &saveptr);
		/* Move on to the next directory in the PATH */
	}

/* not found */
perror("execute");
free(path_copy);
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Error forking */
perror("execute");
}
else
{
/* Parent process */
waitpid(pid, &status, WUNTRACED);
/* Wait for the child process to finish */
}

return (1);
}


/**
* env_shell - Prints the current environment variables.
*/
void env_shell(void)
{
char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
