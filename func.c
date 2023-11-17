#include "main.h"

/**
 * parse_cmd - Parses a command string into an array of arguments
 * @cmd: The command string to parse
 * @args: An array of strings to store the parsed arguments
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
 * search_path - Searches for a command in the directories listed in PATH
 * @cmd: The command to search for
 *
 * Return: The full path to the command if found, otherwise NULL
 */
char *search_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char *cmd_path = malloc(strlen(dir) + strlen(cmd) + 2);

		strcpy(cmd_path, dir);
		strcat(cmd_path, "/");
		strcat(cmd_path, cmd);

		if (access(cmd_path, X_OK) == 0)
		{
			free(path_copy);
			return (cmd_path);
		}

		free(cmd_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * execute_cmd - Executes a command with arguments
 * @args: An array of strings containing the command and its arguments
 *
 * Return: 1 on success, otherwise an error code
 */
int execute_cmd(char **args)
{
	char *cmd_path = search_path(args[0]);

	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (1);
	}

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (pid == 0)
	{
		execve(cmd_path, args, environ);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		free(cmd_path);
		return (1);
	}
}
