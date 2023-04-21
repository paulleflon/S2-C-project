#include <stdio.h>
#include <stdlib.h>
#include "../headers/Point.h"

Point* create_point(int x, int y) {
    Point *point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

void delete_point(Point *point){
	free(point);
}

void print_point(Point *point){
	printf("POINT %d %d\n", point->x, point->y);
}
