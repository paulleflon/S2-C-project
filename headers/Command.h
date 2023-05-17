#ifndef COMMAND_H
#define COMMAND_H

typedef struct Command {
	char name[50];
	int int_size;
	int int_params[10];
	int str_size;
	char *str_params[10];
} Command;

Command *create_command();
void add_str_param(Command *cmd, char *p);
void add_int_param(Command *cmd, int p);
void free_cmd(Command *cmd);
int read_exec_command(Command *cmd);
void read_from_stdin(Command *cmd);



#endif