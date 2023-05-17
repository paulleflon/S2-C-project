#ifndef AREA_H
#define AREA_H
#include "Shapes/Shape.h"
#define SHAPE_MAX 100
#define BOOL int

typedef struct Area {
	unsigned int width;
	unsigned int height;
	BOOL** mat;
	Shape* shapes[SHAPE_MAX];
	int nb_shape;
} Area;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
void draw_area(Area* area);
void print_area(Area* area);

#endif