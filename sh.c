#include "main.h"
/**
 * parse_cmd - Entry point
 * @cmd: command
 * @args: arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void parse_cmd(char *cmd, char **args)
{
	args[0] = strtok(cmd, " \n");
	args[1] = NULL;
}

/**
 * execute_cmd - Execute a command
 * @args: The command and its arguments
 * @program_name: The name of the program
 * Return: 1 on success, 0 on failure
 */
int execute_cmd(char **args, char *program_name)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
		return (1);
	}
}
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(int argc, char **argv)
{
	char cmd[MAX_CMD_LEN];
	char *args[MAX_ARGS];
	int status = 1;

	while (status)
	{
		printf("$ ");
		if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		parse_cmd(cmd, args);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				status = 0;
			}
			else
			{
				status = execute_cmd(args, argv[0]);
			}
		}
	}

	return (EXIT_SUCCESS);
}
