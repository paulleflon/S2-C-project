/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file regroups the functions for the shape "square"
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Square.h"

//allows to dynamically allocate a structured square whose coordinates are given in parameter
Square* create_square(Point *point, int length) {
    Square *square = (Square*)malloc(sizeof(Square));
	square->origin = point;
	square->length = length;
    return square;
}

//allows to free the memory allocated to the square given in parameter
void delete_square(Square *square) {
	free(square->origin);
	free(square);
}

//allows to display on the screen the information of a square
void print_square(Square *square) {
    printf("SQUARE %d %d %d\n", square->origin->x, square->origin->y, square->length);
}
