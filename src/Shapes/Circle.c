/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file regroups the functions for the shape "circle"
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Circle.h"

//allows to dynamically allocate a structured circle whose center is given in parameter
Circle* create_circle(Point *center, int radius) {
	Circle *circle = (Circle*)malloc(sizeof(Circle));
	circle->center = center;
	circle->radius = radius;
	return circle;
}

//allows to free the memory allocated to the circle given in parameter
void delete_circle(Circle *circle) {
	free(circle->center);
	free(circle);
}

//allows to display on the screen the information of a circle
void print_circle(Circle *circle) {
	printf("CIRCLE %d %d %d\n", circle->center->x, circle->center->y, circle->radius);
}