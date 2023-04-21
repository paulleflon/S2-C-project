#include <stdio.h>
#include <stdlib.h>
#include "headers/Shape.h"
#define string char*


Shape **shapes;
int shape_count = 0;

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

Shape* input_point() {
	printf("Enter the informations of the point:\n");
	printf("Enter the coordinates x y: ");
	int x, y;
	scanf("%d %d", &x, &y);
	return create_point_shape(x, y);
}

Shape* input_line() {
	int x1, y1, x2, y2;
	printf("Enter the informations of the line:\n");
	printf("Enter the first point x1 y1: ");
	scanf("%d %d", &x1, &y1);
	printf("Enter the second point x2 y2: ");
	scanf("%d %d", &x2, &y2);
	return create_line_shape(x1, y1, x2 ,y2);
}

Shape* input_circle() {
	int x, y, r;
	printf("Enter the informations of the circle:\n");
	printf("Enter the center point x y: ");
	scanf("%d %d", &x, &y);
	printf("Enter the radius of the circle: ");
	scanf("%d", &r);
	return create_circle_shape(x, y, r);
}

Shape* input_square() {
	int x, y, l;
	printf("Enter the informations of the square:\n");
	printf("Enter the origin point x y: ");
	scanf("%d %d", &x, &y);
	printf("Enter the length of the square: ");
	scanf("%d", &l);
	return create_square_shape(x, y, l);

}

Shape* input_rectangle() {
	int x, y, w, h;
	printf("Enter the informations of the rectangle:\n");
	printf("Enter the origin point x y: ");
	scanf("%d %d", &x, &y);
	printf("Enter the width and height: ");
	scanf("%d %d", &w, &h);
	return create_rectangle_shape(x, y, w, h);
}

Shape* input_polygon() {
	int n;
	int *coords;
	printf("Enter the informations of the polygon:\n");
	do {
		printf("Enter the number of vertices (min. 3): ");
		scanf("%d", &n);
	} while (n < 3);
	n*=2;
	coords = (int*)malloc(n * sizeof(int));
	int index = 0;
	for (int i = 0; i < n; i+=2) {
		printf("Enter the coordinates x y of the vertex #%d: ", index++);
		scanf("%d %d", &coords[i], &coords[i+1]);
	}
	return create_polygon_shape(coords, n);
}

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
	shape_count++;
	shapes = realloc(shapes, shape_count * sizeof(Shape));
	shapes[shape_count-1] = shape;
	printf("\n");
}

void display_shapes() {
	for (int i = 0; i < shape_count; i++)
		print_shape(shapes[i]);
	printf("\n");
}


int main() {
	int running = 1;
	while (running) {
		printf("Select an option:\n");
		string options[] = {"Add a shape", "Display the list of shapes", "Delete a shape", "Draw shapes", "Help", "Exit"};
		int choice = menu(options, 6);

		switch (choice) {
			case 0:
				add_shape();
				break;
			case 1:
				display_shapes();
				break;
			case 5:
				running = 0;
				break;
			default:
				printf("This feature is not implemented yet.\n");

		}
	}
	return 0;
}
