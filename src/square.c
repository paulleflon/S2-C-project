#include <stdio.h>
#include <stdlib.h>
#include "../headers/Square.h"


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
    printf("SQUARE %d %d %d\n", square->origin->pos_x, square->origin->pos_y, square->length);
}
