/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Cirlce.c
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"

/** Represents a simple Circle */
typedef struct Circle {
    Point *center;
    int radius;
} Circle;

/**
 * Dynamically allocates a Line
 * @param center The center point of the circle
 * @param radius The radius of the circle
 * @return A pointer to the allocated Circle
 */
Circle* create_circle(Point *center, int radius);
/**
 * Frees the memory allocated to the Circle and its center
 * @param circle The Circle to free
 * @return There is nothing to return
 */
void delete_circle(Circle *circle);
/**
 * Prints the Circle in the format "CIRCLE X Y RADIUS"
 * @param circle The circle to print
 * @return There is nothing to return
 */
void print_circle(Circle *circle);

#endif
