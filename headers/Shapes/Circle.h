/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Cirlce.c
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"

//creation of the Circle structure
typedef struct Circle {
    Point *center;
    int radius;
} Circle;

//functions defined in the source
Circle* create_circle(Point *center, int radius);
void delete_circle(Circle *circle);
void print_circle(Circle *circle);

#endif
