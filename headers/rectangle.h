#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct rectangle{
    int width;
    int height;
}Rectangle;

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);


#endif