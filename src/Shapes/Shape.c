#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Shape.h"
#include "../../headers/id.h"

Shape* create_empty_shape(SHAPE_TYPE type) {
	Shape *shape = (Shape*)malloc(sizeof(Shape));
	shape->ptrShape = NULL;
	shape->id = get_next_id();
	shape->type = type;
	return shape;
}

Shape* create_point_shape(int x, int y) {
	Shape *shape = create_empty_shape(point);
	Point *p = create_point(x, y);
	shape->ptrShape = p;
	return shape;
}

Shape* create_line_shape(int x1, int y1, int x2, int y2) {
	Shape *shape = create_empty_shape(line);
	Point *p1 = create_point(x1, y1);
	Point *p2 = create_point(x2, y2);
	Line *l = create_line(p1, p2);
	shape->ptrShape = l;
	return shape;
}

Shape* create_square_shape(int x, int y, int length) {
	Shape *shape = create_empty_shape(square);
	Point *origin = create_point(x, y);
	Square *s = create_square(origin, length);
	shape->ptrShape = s;
	return shape;
}

Shape* create_rectangle_shape(int x, int y, int width, int height) {
	Shape *shape = create_empty_shape(rectangle);
	Point *origin = create_point(x, y);
	Rectangle *rect = create_rectangle(origin, width, height);
	shape->ptrShape = rect;
	return shape;
}
Shape* create_circle_shape(int x, int y, int radius) {
	Shape *shape = create_empty_shape(circle);
	Point *origin = create_point(x, y);
	Circle *c = create_circle(origin, radius);
	shape->ptrShape = c;
	return shape;
}

Shape* create_polygon_shape(int coords[], int n) {
	Shape *shape = create_empty_shape(polygon);
	Polygon *poly = create_polygon(coords, n);
	shape->ptrShape = poly;
	return shape;
}

void delete_shape(Shape *shape) {
	switch (shape->type) {
		case point:
			delete_point(shape->ptrShape);
			break;
		case line:
			delete_line(shape->ptrShape);
			break;
		case square:
			delete_square(shape->ptrShape);
			break;
		case rectangle:
			delete_rectangle(shape->ptrShape);
			break;
		case circle:
			delete_circle(shape->ptrShape);
			break;
		case polygon:
			delete_polygon(shape->ptrShape);
			break;
	}
}

void print_shape(Shape *shape) {
	printf("#%d: ", shape->id);
	switch (shape->type) {
		case point:
			print_point(shape->ptrShape);
			break;
		case line:
			print_line(shape->ptrShape);
			break;
		case square:
			print_square(shape->ptrShape);
			break;
		case rectangle:
			print_rectangle(shape->ptrShape);
			break;
		case circle:
			print_circle(shape->ptrShape);
			break;
		case polygon:
			print_polygon(shape->ptrShape);
			break;
	}
}
