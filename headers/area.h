#ifndef AREA_H
#define AREA_H
#include "Shapes/Shape.h"
#define SHAPE_MAX 100 // Maximum number of shapes
#define BOOL int


struct area {
    unsigned int width; // Number of pixels in width or number of columns (y-axis)
    unsigned int height; // Number of pixels in height or number of lines (x axis)
    BOOL** mat; // pixel size matrix (width * height)
    Shape* shapes[SHAPE_MAX]; // array of shapes
    int nb_shape; // number of shapes in the shapes array (logical size)
};
typedef struct area Area;


Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);



#endif