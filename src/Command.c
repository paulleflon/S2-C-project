#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../headers/Command.h"

Command* create_command() {
	Command *cmd = (Command*)malloc(sizeof(Command));
	cmd->int_size = 0;
	cmd->str_size = 0;
	return cmd;
}

void add_str_param(Command *cmd, char *p) {
	if (cmd->str_size < 10) {
		cmd->str_params[cmd->str_size] = p;
		cmd->str_size++;
	}
}

void add_int_param(Command *cmd, int p) {
	if (cmd->int_size < 10) {
		cmd->int_params[cmd->int_size] = p;
		cmd->int_size++;
	}
}

void free_cmd(Command *cmd) {
	free(cmd->name);
	for (int i = 0; i < cmd->str_size; i++) {
		free(cmd->str_params[i]);
	}
	free(cmd->str_params);
	free(cmd->int_params);
	free(cmd);
}

int read_exec_command(Command *cmd) {
	printf("to be implemented\n");
}

void read_from_stdin(Command *cmd) {
	printf(">>>");
	char *buffer = (char*)malloc(100 * sizeof(char));
	fgets(buffer, 100, stdin);
	// Getting command name
	char *token = strtok(buffer, " ");
	strcpy(cmd->name, token);
	// We first parse string parameters, then int parameters. They're not mixed.
	int parsing_str = 1;
	while (token != NULL) {
		token = strtok(NULL, " ");
		// As string parameters are not supposed to contain any digit,
		// If we find any digit in this parameter, it means we switched to int params
		if (parsing_str && isdigit(token[0]))
			parsing_str = 0;

		if (parsing_str)
			add_str_param(cmd, token);
		else
			// Whatever happens with user's input, atoi will return an integer.
			// So even if the output is not correct, we don't have to worry about
			// an incorrect input generating any crash.
			add_int_param(cmd, atoi(token));
	}
}