#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
void exit_shell(void);
extern char **environ;

#endif /* MAIN_H */
