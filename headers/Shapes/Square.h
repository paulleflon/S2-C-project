/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Square.c
 */

#ifndef SQUARE_H
#define SQUARE_H
#include "Point.h"

/** Represents a simple Square */
// We could have used a Rectangle instead of reimplementing a whole structure.
typedef struct Square {
    Point *origin;
    int length;
} Square;

/**
 * Dynamically allocates a Square
 * @param point The top-left vertex of the Square
 * @param length the length of the Square
 * @return A pointer to the allocated Square
 */
Square* create_square(Point *point, int length);
/**
 * Frees the memory allocated to the Square and its origin
 * @param square The Square to free
 * @return There is nothing to return
 */
void delete_square(Square *square);
/**
 * Prints the Square in the format "SQUARE X Y LENGTH"
 * @param square The Square to print
 * @return There is nothing to return
 */
void print_square(Square *square);


#endif
