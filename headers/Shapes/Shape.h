/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Shape.c
 */

#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"
#include "Line.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"


typedef enum SHAPE_TYPE { point, line, square, circle, rectangle, polygon } SHAPE_TYPE;

/**
 * Shape structure containing any shape we already implemented, but abstracting all these types to a single one.
 * It also bundles in the id of the shape.
 */
typedef struct Shape {
	int id;
	SHAPE_TYPE type;
	void *ptrShape;
} Shape;

/**
 * Dynmically allocates a Shape structure, setting its id and its type, but not the actual shape (point, line, ...)
 * @param type The type of shape this Shape structure will contain
 * @return A pointer to the allocated Shape
 */
Shape* create_empty_shape(SHAPE_TYPE type);
/**
 * Dynamically allocates a Point shape
 * @param x The x coordinate of the Point
 * @param y The y coordinate of the Point
 * @return A pointer to the allocated Shape
 */
Shape* create_point_shape(int x, int y);
/**
 * Dynamically allocates a Line shape
 * @param x1 The x coordinate of the first end
 * @param y1 The y coordinate of the first end
 * @param x2 The x coordinate of the second end
 * @param y2 The y coordinate of the second end
 * @return A pointer to the allocated Shape
 */
Shape* create_line_shape(int x1, int y1, int x2, int y2);
/**
 * Dynamically allocates a Square shape
 * @param x The x coordinate of the origin
 * @param y The y coordinate of the origin
 * @param length The length of the Square's edge
 * @return A pointer to the allocated Shape
 */
Shape* create_square_shape(int x, int y, int length);
/**
 * Dynamically allocates a Rectangle shape
 * @param x The x coordinate of the origin
 * @param y The y coordinate of the origin
 * @param width The width of the Rectangle
 * @param height The y coordinate of the Rectangle
 * @return A pointer to the allocated Shape
 */
Shape* create_rectangle_shape(int x, int y, int width, int height);
/**
 * Dynamically allocates a Circle shape
 * @param x The x coordinate of the center
 * @param y The y coordinate of the center
 * @param radius The radius of the Circle
 * @return A pointer to the allocated Shape
 */
Shape* create_circle_shape(int x, int y, int radius);
/**
 * Dynamically allocates a Polygon shape
 * @param coords The coordinates of the polygon's vertices, in the shape `[x1, y1, x2, y2, ...]`
 * @param n The size of the `coords` array
 * @return A pointer to the allocated Shape
 */
Shape* create_polygon_shape(int coords[], int n);
/**
 * Frees the memory allocated to the Shape structure and the shape it contains
 * @param shape The shape to free
 * @return There is nothing to return
 */
void delete_shape(Shape *shape);
/**
 * Prints a shape in the format corresponding to its type
 * @param shape The shape to print
 * @return There is nothing to return
 */
void print_shape(Shape *shape);

#endif
