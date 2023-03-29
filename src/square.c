#include <stdio.h>
#include <stdlib.h>
#include "../headers/square.h"


Square *create_square(Point * point, int length){
    Square *square = (Square *) malloc(sizeof(Square)); // memory for the Square struct
    if (square != NULL){
        square -> p1 = point; // point is assigned to Square struct
        square -> length = length;// l is assigned to Square struct
        square -> p2 = point + length; // point is assigned to Square struct
        square -> p3 = point + length; // point is assigned to Square struct
        square -> p4 = point; // point is assigned to Square struct
    }
    return square;
}

void delete_square(Square * square){
    if (square != NULL){
        free(square);
    }
}

void print_square(Square * square){
    printf("SQUARE ");
}