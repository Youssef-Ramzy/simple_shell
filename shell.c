#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char cmd[MAX_CMD_LEN];
	char *args[MAX_ARGS];
	int status = 1;

	while (status)
	{
		printf("> ");
		fgets(cmd, MAX_CMD_LEN, stdin);
		parse_cmd(cmd, args);
		if (strcmp(args[0], "exit") == 0)
		{
			status = 0;
		}
		else if (strcmp(args[0], "env") == 0)
		{
			char **env = environ;

			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		else
		{
			status = execute_cmd(args);
		}
	}

	return (EXIT_SUCCESS);
}
