/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Area.c
 */

/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Area.c
 */

#ifndef AREA_H
#define AREA_H
#include "Shapes/Shape.h"
#define SHAPE_MAX 100
#define BOOL int

//creation of the Area structure
typedef struct Area {
	unsigned int width;
	unsigned int height;
	BOOL** mat;
	Shape* shapes[SHAPE_MAX];
	int nb_shape;
} Area;

//functions defined in the source
Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area *area, Shape *shape);
void clear_area(Area *area);
void erase_area(Area *area);
void delete_area(Area *area);
void draw_area(Area *area);
void print_area(Area *area);

#endif