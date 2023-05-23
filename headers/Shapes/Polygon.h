/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Polygon.c
 */

#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"

//creation of the Polygon structure
typedef struct Polygon {
    int n;
    Point **points;
} Polygon;

//functions defined in the source
Polygon *create_polygon(int coords[], int n);
void delete_polygon(Polygon *polygon);
void print_polygon(Polygon *polygon);

#endif
