#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Circle.h"

Circle* create_circle(Point *center, int radius) {
	Circle *circle = (Circle*)malloc(sizeof(Circle));
	circle->center = center;
	circle->radius = radius;
	return circle;
}

void delete_circle(Circle *circle) {
	free(circle->center);
	free(circle);
}

void print_circle(Circle *circle) {
	printf("CIRCLE %d %d %d\n", circle->center->x, circle->center->y, circle->radius);
}