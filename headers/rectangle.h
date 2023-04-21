#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"

typedef struct {
	Point *origin;
	int width;	
    int height;
} Rectangle;

Rectangle* create_rectangle(Point *origin, int width, int height);
void delete_rectangle(Rectangle *rectangle);
void print_rectangle(Rectangle *rectangle);


#endif
