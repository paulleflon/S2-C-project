///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This source file is the entry point of the program.

#include <stdio.h>
#include <stdlib.h>
#include "../headers/Shapes/Shape.h"
#include "../headers/List.h"
#include "../headers/Command.h"
#include "../headers/Pixel.h"
#include "../headers/Area.h"

#define string char*

List shapes;

///region Deprecated functions only used in Part 1.

/**
 * Displays a menu and handles related user input
 * @param options The options this menu should display
 * @param options_size The number of options passed
 * @returns The index of the option selected by the user
 */
int menu(string options[], int options_size) {
	for (int i = 0; i < options_size; i++) {
		printf("%c - %s\n", 65 + i, options[i]);
	}
	char choice;
	do {
		scanf("%c", &choice);
	} while (
		!(choice >= 65 && choice < 65 + options_size) && // Upper cased
		!(choice >= 97 && choice < 97 + options_size) // Lower cased
);
	return choice >= 97 ? choice - 97 : choice - 65;
}

/**
 * Displays instructions to input Point data and handles user input
 * @return A pointer to the generate Point Shape
 */
Shape* input_point() {
	printf("Enter the informations of the point:\n");
	printf("Enter the coordinates x y: ");
	int x, y;
	scanf("%d %d", &x, &y);
	return create_point_shape(x, y);
}
/**
 * Displays instructions to input Line data and handles user input
 * @return A pointer to the generate Line Shape
 */
Shape* input_line() {
	int x1, y1, x2, y2;
	printf("Enter the informations of the line:\n");
	printf("Enter the first point x1 y1: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the second point x2 y2: ");
	scanf("%d %d", &x2, &y2);
	return create_line_shape(x1, y1, x2 ,y2);
}
/**
 * Displays instructions to input Circle data and handles user input
 * @return A pointer to the generate Circle Shape
 */
Shape* input_circle() {
	int x, y, r;
	printf("Enter the informations of the circle:\n");
	printf("Enter the center point x y: ");
	scanf("%d %d", &x, &y);
	printf("Enter the radius of the circle: ");
	scanf("%d", &r);
	return create_circle_shape(x, y, r);
}
/**
 * Displays instructions to input Square data and handles user input
 * @return A pointer to the generate Square Shape
 */
Shape* input_square() {
	int x, y, l;
	printf("Enter the informations of the square:\n");
	printf("Enter the origin point x y: ");
	scanf("%d %d", &x, &y);
	printf("Enter the length of the square: ");
	scanf("%d", &l);
	return create_square_shape(x, y, l);

}
/**
 * Displays instructions to input Rectangle data and handles user input
 * @return A pointer to the generate Rectangle Shape
 */
Shape* input_rectangle() {
	int x, y, w, h;
	printf("Enter the informations of the rectangle:\n");
	printf("Enter the origin point x y: ");
	scanf("%d %d", &x, &y);
	printf("Enter the width and height: ");
	scanf("%d %d", &w, &h);
	return create_rectangle_shape(x, y, w, h);
}
/**
 * Displays instructions to input Polygon data and handles user input
 * @return A pointer to the generate Polygon Shape
 */
Shape* input_polygon() {
	int n;
	int *coords;
	printf("Enter the informations of the polygon:\n");
	do {
		printf("Enter the number of vertices (min. 3): ");
		scanf("%d", &n);
	} while (n < 3);
	n*=2; // There are n vertices, hence 2xn coordinates
	coords = (int*)malloc(n * sizeof(int));
	int index = 0;
	for (int i = 0; i < n; i+=2) {
		printf("Enter the coordinates x y of the vertex #%d: ", index++);
		scanf("%d %d", &coords[i], &coords[i+1]);
	}
	return create_polygon_shape(coords, n);
}

/**
 * Handles a whole shape adding process:
 *  - Makes the user select a shape
 *  - Makes the user input the required data for the given shape
 *  - Appends the shape to the global shape list
 */
void add_shape() {
	printf("Select a shape:\n");
	string options[] = {"Point", "Line", "Circle", "Square", "Rectangle", "Polygon", "Back"};
	int type = menu(options, 7);
	Shape *shape;
	switch (type) {
		case 6:
			return;

		case 0:
			  shape = input_point();
			  break;
		case 1:
			  shape = input_line();
			  break;
		case 2:
			  shape = input_circle();
			  break;
		case 3:
			  shape = input_square();
			  break;
		case 4:
			  shape = input_rectangle();
			  break;
		case 5:
			  shape = input_polygon();
			  break;
	}
	append_shape(&shapes, shape);
	printf("\n");
}

/**
 * Displays the list of shapes
 */
void display_shapes() {
	Node *current = shapes;
	while (current != NULL) {
		print_shape(current->value);
		current = current->next;
	}
	printf("\n");
}
//endregion

int main() {
	printf("Welcome to VectorEditor - Written by Adele Chamoux & Paul Leflon, INT-1\n");
	int running = 1;
	Command *cmd = create_command(); // Holds the user's last inputted command
	Area *area = create_area(40, 20);
	while (running) {
		read_from_stdin(cmd);
		if (read_exec_command(cmd, area)) // read_exec_command returns 1 if the exit command was inputted
			running = 0;
		 // We reset the command's parameters sizes
		 // So that previous parameters are not taken into account.
		cmd->int_size = 0;
		cmd->str_size = 0;
	}
	free_cmd(cmd);
	delete_area(area);
	return 0;
}
