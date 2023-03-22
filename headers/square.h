#ifndef SQUARE_H
#define SQUARE_H

typedef struct square{
    int length;
}Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);


#endif
