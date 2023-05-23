/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file regroups the functions for the shape "rectangle"
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Rectangle.h"

//allows to dynamically allocate a structured rectangle whose coordinates are given in parameter
Rectangle* create_rectangle(Point *origin, int width, int height) {
	Rectangle* rectangle = (Rectangle*)malloc(sizeof(Rectangle));
	rectangle->origin = origin;
	rectangle->width = width;
	rectangle->height = height;
	return rectangle;
}

//allows to free the memory allocated to the rectangle given in parameter
void delete_rectangle(Rectangle *rectangle) {
	free(rectangle->origin);
	free(rectangle);
}

//allows to display on the screen the information of a rectangle
void print_rectangle(Rectangle *rectangle) {
	printf("RECTANGLE %d %d %d %d\n", rectangle->origin->x, rectangle->origin->y, rectangle->width, rectangle->height);
}
