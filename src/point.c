#include <stdio.h>
#include "point.h"

// create_point allows to dynamically allocate a structured Point whose coordinates are given in parameter
Point *create_point(int px, int py){
    Point p = {px, py};
    return p;
}

// delete_point allows to free the memory allocated to the point given in parameter.
void delete_point(Point * point){
    free(Point);
}

// print_point allows to display on the screen the information of a Point in the following form: POINT [p(pos_x, pos_y)]
void print_point(Point * p){
    printf("POINT %d %d", pos_x, pos_y);
}