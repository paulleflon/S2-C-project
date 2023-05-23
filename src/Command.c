///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This source file contains Command related function implementations

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
	if (cmd->str_size < 10) { // The physical size of this array is 10
		cmd->str_params[cmd->str_size] = p;
		cmd->str_size++;
	}
}

void add_int_param(Command *cmd, int p) {
	if (cmd->int_size < 10) { // The physical size of this array is 10
		cmd->int_params[cmd->int_size] = p;
		cmd->int_size++;
	}
}

void free_cmd(Command *cmd) {
	// As the properties of the structure are not dynamically allocated,
	// we don't have to free them.
	free(cmd);
}

int read_exec_command(Command *cmd, Area *area) {
	// We can't use switch with strings in C so we'll use a basic if-else if
	if (strcmp(cmd->name, "help") == 0) { // Simply prints a list of commands
		printf("usage: <command name> <string parameters, ...> <int parameters, ...>\n");
		printf("VectorEditor commands:\n\n");
		printf("clear - clear the screen\n");
		printf("circle <x> <y> <radius> - add a circle\n");
		printf("delete <id> - delete the shape of the given id\n");
		printf("erase - delete all shapes\n");
		printf("exit - exit VectorEdit\n");
		printf("help - displays this\n");
		printf("line <x1> <y1> <x2> <y2> - add a line connecting the points (x1, y1) and (x2, y2)\n");
		printf("list - display a list of all the shapes and their details\n");
		printf("plot - plots all the shapes on the screen\n");
		printf("point <x> <y> - add a point\n");
		// Open polygon is a deliberate feature
		printf("polygon <x1> <y1> <x2> <y2> < ... > - add a polygon with the list of given points (can be an open polygon)\n");
		printf("rectangle <x> <y> <width> <height> - add a rectangle whose upper left corner is (x,y)\n");
		printf("square <x> <y> <length> - add a square whose upper left corner is (x,y)\n");
		printf("\n");
	}
	else if (strcmp(cmd->name, "list") == 0) { // Prints the list of shapes in the area
		for (int i = 0; i < area->nb_shape; i++) {
			print_shape(area->shapes[i]);
		}
		if (area->nb_shape == 0)
			printf("The area is empty.\n");
	}
	else if (strcmp(cmd->name, "delete") == 0) { // Deletes a shape
		if (cmd->int_size < 1)
			printf("Missing parameter id.\n");
		else {
			int id = cmd->int_params[0];
			int deleted = 0; // The given id might not correspond to any stored shape
			for (int i = 0; i < area->nb_shape; i++) { // Hence, we loop through the shapes to find a match
				if (area->shapes[i]->id == id) { // If a match is found, we delete it and remove it from the array
					delete_shape(area->shapes[i]);
					// Shifts all the following array elements to the left
					for (int j = i; j < area->nb_shape - 1; j++) {
						area->shapes[j] = area->shapes[j + 1];
					}
					deleted = 1;
					area->nb_shape--;
				}
			}
			if (deleted)
				printf("Successfully deleted the shape #%d\n", id);
			else
				printf("Couldn't find any shape with id #%d. Use list to see current shapes.\n", id);
		}
	}
	else if (strcmp(cmd->name, "point") == 0) { // Adds a point
		if (cmd->int_size < 2)
			printf("Expected 2 parameters: x y\n");
		else {
			Shape *shape = create_point_shape(cmd->int_params[0], cmd->int_params[1]);
			add_shape_to_area(area, shape);
			printf("Added new Point #%d\n", shape->id);
		}
	}
	else if (strcmp(cmd->name, "line") == 0) { // Adds a line
		if (cmd->int_size < 4)
			printf("Expected 4 parameters: x1 y1 x2 y2\n");
		else {
			Shape *shape = create_line_shape(cmd->int_params[0],
											 cmd->int_params[1],
											 cmd->int_params[2],
											 cmd->int_params[3]);
			add_shape_to_area(area, shape);
			printf("Added new Line #%d\n", shape->id);
		}
	}
	else if (strcmp(cmd->name, "circle") == 0) { // Adds a circle
		if (cmd->int_size < 3)
			printf("Expected 3 parameters: x y radius\n");
		else {
			Shape *shape = create_circle_shape(cmd->int_params[0],
											   cmd->int_params[1],
											   cmd->int_params[2]);
			add_shape_to_area(area, shape);
			printf("Added new Circle #%d\n", shape->id);
		}
	}
	else if (strcmp(cmd->name, "square") == 0) { // Adds a square
		if (cmd->int_size < 3)
			printf("Expected 3 parameters: x y length\n");
		else {
			Shape *shape = create_square_shape(cmd->int_params[0],
											   cmd->int_params[1],
											   cmd->int_params[2]);
			add_shape_to_area(area, shape);
			printf("Added new Square #%d\n", shape->id);
		}
	}
	else if (strcmp(cmd->name, "rectangle") == 0) { // Adds a rectangle
		if (cmd->int_size < 4)
			printf("Expected 4 parameters: x y width height\n");
		else {
			Shape *shape = create_rectangle_shape(cmd->int_params[0],
												  cmd->int_params[1],
												  cmd->int_params[2],
												  cmd->int_params[3]);
			add_shape_to_area(area, shape);
			printf("Added new Rectangle #%d\n", shape->id);
		}
	}
	else if (strcmp(cmd->name, "polygon") == 0) { // Adds a polygon
		if (cmd->int_size < 4)
			printf("Expected at least 4 parameters: x1 y1 x2 y2\n");
		else if (cmd->int_size%2 == 1)
			printf("Expected an even number of parameters: x1 y1 x2 y2 ... xN yN\n");
		else {
			// There is no check about whether the last point is the same as the first point.
			// We deliberately allow open polygons as we think it's a useful feature.
			Shape *shape = create_polygon_shape(cmd->int_params, cmd->int_size);
			add_shape_to_area(area, shape);
			printf("Added new Polygon #%d\n", shape->id);
		}
	}
	else if (strcmp(cmd->name, "plot") == 0) { // Displays the shapes on the screen
		clear_area(area);
		draw_area(area);
		print_area(area);
	}
	else if (strcmp(cmd->name, "clear") == 0) { // Clears the screen
		 // Windows and Unix based systems use a different command for clearing the terminal,
		 // which we use for this feature. Control characters are too inconsistent.
		#ifdef _WIN32
			system("cls"); // Windows
		#else
			system("clear"); // macOS/Linux
		#endif
	}
	else if (strcmp(cmd->name, "erase") == 0) // Deletes all the shapes
		erase_area(area);
	else if (strcmp(cmd->name, "exit") == 0) // Exits the program
		return 1;
	// If an unknown command is inputted, we notify the user about it.
	else if (strcmp(cmd->name, "") != 0)
		printf("Unknown command: '%s' - Type help to see available commands.\n", cmd->name);
	// But if no command was inputted (so the user just pressed Enter), we just silently ignore it and
	// listen for the next input, as most of CLIs do
	return 0;
}

void read_from_stdin(Command *cmd) {
	printf(">>>");
	char *buffer = (char*)malloc(100 * sizeof(char));
	// Similar to scanf for our usage but prevents memory issues
	fgets(buffer, 100, stdin);
	// We swap the \n with and end of string character (\0) for easier string manipulations
	char *ptr = strchr(buffer, '\n');
	if (ptr != NULL)
		*ptr = '\0';
	if (buffer[0] == '\0') {
		strcpy(cmd->name, "");
		return;
	}
	// We first parse the command name using strtok, similar to python's split function
	char *token = strtok(buffer, " ");
	strcpy(cmd->name, token);
	// As string parameters appear before integer parameters,
	// we track what type of parameter we're currently parsing
	int parsing_str = 1;
	//We used strtok once already with the input string, so to get the next split word, we use it with a NULL string
	token = strtok(NULL, " \n");
	while (token != NULL) {
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
		token = strtok(NULL, " \n");
	}
}