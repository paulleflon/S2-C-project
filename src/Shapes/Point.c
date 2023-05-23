/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file regroups the functions for the shape "point"
 */


#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Point.h"

//allows to dynamically allocate a structured point whose center is given in parameter
Point* create_point(int x, int y) {
    Point *point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

//allows to free the memory allocated to the point given in parameter
void delete_point(Point *point){
	free(point);
}

//allows to display on the screen the information of a point
void print_point(Point *point){
	printf("POINT %d %d\n", point->x, point->y);
}
