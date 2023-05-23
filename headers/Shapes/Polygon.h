/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Polygon.c
 */

#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"

/** Represents a Polygon */
typedef struct Polygon {
    int n;
    Point **points;
} Polygon;

/**
 * Dynamically allocates a Polygon
 * @param coord The coordinates of all vertices of the Polygon
 * @param n The number of coordinates
 * @return A pointer to the allocated Polygon. It has no Point if the amount of passed coordinates is odd
 */
Polygon *create_polygon(int coords[], int n);
/**
 * Frees the memory allocated to the Polygon and its vertices
 * @param polygon The Polygon to free
 * @return There is nothing to return
 */
void delete_polygon(Polygon *polygon);
/**
 * Prints the Polygon in the format "POLYGON X1,Y1 X2,Y2 ... XN, YN"
 * @param polygon The Polygon to print
 * @return There is nothing to return
 */
void print_polygon(Polygon *polygon);

#endif
