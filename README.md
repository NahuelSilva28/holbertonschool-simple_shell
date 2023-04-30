<h1 align="center">Holberton simple shell</h1>

The simple shell is a simplified version of the Unix shell, can be used to run commands in a Unix-like environment. The shell runs in a loop, printing a prompt, reading a line of input, parsing the line into arguments, and executing the command with the arguments.
- [Holberton simple shell](https://github.com/NahuelSilva28/holbertonschool-simple_shell)
<h1 align="center">Requirements</h1> 

- ``` A Unix-like operating system (e.g. Linux, macOS, FreeBSD) ```
- ``` GCC (GNU Compiler Collection) or another C compiler ```

<h1 align="center">Compilation</h1> 

``` gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh ```



<h1 align="center">Usage</h1> 

``` ./hsh ```


<h1 align="center">Main.c</h1> 

```Reads input from the user in a loop, prints a prompt, reads a line of input, parses the line into arguments, and executes the command with the arguments. The loop continues until the user enters the "exit" command. The function returns 0 to indicate successful execution.```

<h1 align="center">Functions.c</h1> 

- read_line
```The read_line function reads a line of input from the standard input stream using getline and returns a pointer to the buffer containing the line of input. If getline encounters an error or reaches the end of the input stream, the function will print an error message and exit with a failure status.```

- split_line 
```This function splits a given string (line) into tokens based on delimiters specified in TOKEN_DELIMITERS macro. It uses the strtok_r() function to split the line into tokens and stores each token in an array of strings (tokens). If the array is not large enough to hold all tokens, it reallocates more memory. Finally, it sets the last element of the array to NULL to mark the end of the array and returns the array of tokens.```


- exit_shell
```terminate the program with a successful status.```

- execute
```The execute function executes a command with arguments. It first checks if the command is a built-in command such as exit or env, and executes it if it is. If the command is not built-in, it forks a child process and executes the command in the child process using execve(). It searches for the command in the directories listed in the PATH environment variable. If the command is not found, it prints an error message and returns an error code.```


- env_shell
```prints the current environment variables by iterating over the environ global variable and printing each element.```

- free_tokens
```frees the memory allocated for an array of tokens```

<h1 align="center">Authors</h1> 

- [NahuelSilva28](https://github.com/NahuelSilva28)
