#include <stdio.h>
#include <stdlib.h>
#include "../headers/point.h"


// create_point allows to dynamically allocate a structured Point whose coordinates are given in parameter
Point* create_point(int px, int py) {
    Point* point = malloc(sizeof(Point));
    if (point == NULL) {
        return NULL; // in case of an error
    }
    point->pos_x = px;
    point->pos_y = py;
    return point;
}


// delete_point allows to free the memory allocated to the point given in parameter.
void delete_point(Point * point){
    if (point != NULL) {
        free(point);
    }
}


// print_point allows to display on the screen the information of a Point in the following form: POINT [p(pos_x, pos_y)]
void print_point(Point * p){
    if (p!=NULL){
        printf("POINT %d %d", p -> pos_x, p -> pos_y);
    }

}