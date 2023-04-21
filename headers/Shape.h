#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"
#include "Line.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"
typedef enum SHAPE_TYPE { point, line, square, circle, rectangle, polygon } SHAPE_TYPE;


typedef struct Shape {
	int id;
	SHAPE_TYPE type;
	void *ptrShape;
} Shape;


Shape* create_empty_shape(SHAPE_TYPE type);
Shape* create_point_shape(int x, int y);
Shape* create_line_shape(int x1, int y1, int x2, int y2);
Shape* create_square_shape(int x, int y, int length);
Shape* create_rectangle_shape(int x, int y, int width, int height);
Shape* create_circle_shape(int x, int y, int radius);
Shape* create_polygon_shape(int coords[], int n);
void delete_shape(Shape *shape);
void print_shape(Shape *shape);
#endif
