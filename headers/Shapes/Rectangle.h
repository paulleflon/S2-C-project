/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Rectangle.c
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"

//creation of the Rectangle structure
typedef struct Rectangle {
	Point *origin;
	int width;	
    int height;
} Rectangle;

//functions defined in the source
Rectangle* create_rectangle(Point *origin, int width, int height);
void delete_rectangle(Rectangle *rectangle);
void print_rectangle(Rectangle *rectangle);

#endif
