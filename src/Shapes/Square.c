/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file regroups the functions for the shape "square"
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Square.h"

Square* create_square(Point *point, int length) {
    Square *square = (Square*)malloc(sizeof(Square));
	square->origin = point;
	square->length = length;
    return square;
}

void delete_square(Square *square) {
	free(square->origin);
	free(square);
}

void print_square(Square *square) {
    printf("SQUARE %d %d %d\n", square->origin->x, square->origin->y, square->length);
}
