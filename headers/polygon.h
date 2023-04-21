#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"

typedef struct Polygon {
    int n;
    Point **points;
} Polygon;

Polygon *create_polygon(int coords[], int n);
void delete_polygon(Polygon *polygon);
void print_polygon(Polygon *polygon);

#endif
