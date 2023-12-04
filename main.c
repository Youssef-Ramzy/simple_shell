#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[], char *environ[])
{
	int i = 0;

	argv[argc - 1] = argv[argc - 1];
	while (environ[i])
	{
		printf(environ[i]);
		printf("\n");
		i++;
	}
	return (0);
}
