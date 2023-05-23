///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This header file contains Rectangle related structures and function declarations

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"

/** Represents a simple Rectangle */
typedef struct Rectangle {
	/**
	 * The top-left vertex of the Rectangle
	 */
	Point *origin;
	int width;	
    int height;
} Rectangle;

/**
 * Dynamically allocates a Rectangle
 * @param origin The top-left vertex of the Rectangle
 * @param width The width of the Rectangle
 * @param height The height of the Rectangle
 * @return A pointer to the allocated Rectangle
 */
Rectangle* create_rectangle(Point *origin, int width, int height);
/**
 * Frees the memory allocated to the Rectangle and its origin
 * @param rectangle The Rectangle to free
 * @return There is nothing to return
 */
void delete_rectangle(Rectangle *rectangle);
/**
 * Prints the Rectangle in the format "RECTANGLE X Y WIDTH HEIGHT"
 * @param rectangle The Rectangle to print
 * @return There is nothing to return
 */
void print_rectangle(Rectangle *rectangle);

#endif
