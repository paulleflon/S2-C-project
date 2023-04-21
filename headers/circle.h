#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"

typedef struct Circle {
    Point *center;
    int radius;
} Circle;

Circle* create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

#endif
