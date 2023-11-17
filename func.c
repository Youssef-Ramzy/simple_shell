#include "main.h"
/**
 * parse_cmd - Parse a command line into arguments
 * @cmd: Command line
 * @args: Arguments array
 * Return: Nothing
 */
void parse_cmd(char *cmd, char **args)
{
	int i = 0;

	args[i] = strtok(cmd, " \n");
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, " \n");
	}
}
/**
 * execute_cmd - Execute a command
 * @args: Arguments array
 * Return: 1 on success, 0 on failure
 */
int execute_cmd(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		return (1);
	}
}
