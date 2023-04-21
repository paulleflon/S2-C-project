#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"

typedef struct {
    Point *origin;
    int length;
} Square;

Square* create_square(Point *point, int length);
void delete_square(Square *square);
void print_square(Square *square);

#endif
