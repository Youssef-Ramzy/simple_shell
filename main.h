#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 16
extern char **environ;

void parse_cmd(char *cmd, char **args);
int execute_cmd(char **args);

#endif
