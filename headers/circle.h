#ifndef CIRCLE_H
#define CIRCLE_H

typedef struct circle{
    int radius;
}Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

#endif
