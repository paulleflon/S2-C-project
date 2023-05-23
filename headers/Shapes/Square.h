/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Square.c
 */

#ifndef SQUARE_H
#define SQUARE_H
#include "Point.h"

//creation of the Square structure
typedef struct Square {
    Point *origin;
    int length;
} Square;

//functions defined in the source
Square* create_square(Point *point, int length);
void delete_square(Square *square);
void print_square(Square *square);

#endif
