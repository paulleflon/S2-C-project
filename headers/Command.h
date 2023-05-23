/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Command.c
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "Area.h"

/**
 * Represents a parsed user-inputted command
 */
typedef struct Command {
	/** Name of the command */
	char name[50];
	/** The number of inputted integer parameters */
	int int_size;
	/** The inputted integer parameters */
	int int_params[10];
	/** The number of inputted string parameters */
	int str_size;
	/** The inputted string parameters */
	char *str_params[10];
} Command;

/**
 * Dynamically allocates an empty command
 * @return A pointer to the allocated command
 */
Command* create_command();
/**
 * Appends a string parameter to the Command
 * @param cmd The command to which a parameter is appended
 * @param p The string parameter to append
 * @return There is nothing to return
 */
void add_str_param(Command *cmd, char *p);
/**
 * Appends an integer parameter to the Command
 * @param cmd The command to which a parameter is appended
 * @param p The integer parameter to append
 * @return There is nothing to return
 */
void add_int_param(Command *cmd, int p);
/**
 * Frees the memory allocated to the Command
 * @param cmd The Command to delete
 * @return There is nothing to return
 */
void free_cmd(Command *cmd);
/** Executes a given command, potentially accessing/modifying the Area */
/**
 * Executes a given Command
 * @param cmd The Command to execute
 * @param area The area the Command should access/modify
 * @returns 1 if the executed command requests to stop the program, 0 otherwise.
 */
int read_exec_command(Command *cmd, Area *area);
/**
 * Requests the user to input a command and parses this input.
 * @param cmd The Command structure to fill according to the user's input
 * @return There is nothing to return
 */
void read_from_stdin(Command *cmd);

#endif