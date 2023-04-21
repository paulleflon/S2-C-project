#include <stdio.h>
#include <stdlib.h>
#include "../headers/Point.h"

// Dynamically allocates a structured Point
Point* create_point(int px, int py) {
    Point *point = malloc(sizeof(Point));
    point->pos_x = px;
    point->pos_y = py;
    return point;
}


// Frees the memory allocated to a Point
void delete_point(Point *point){
	free(point);
}


// Displays the informations of a Point 
void print_point(Point *point){
	printf("POINT %d %d\n", point->pos_x, point->pos_y);
}
