///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This header file contains Area related structures and function declarations

#ifndef AREA_H
#define AREA_H
#include "Shapes/Shape.h"
#define SHAPE_MAX 100
#define BOOL int

/**
 * Represents a drawable Area
 */
typedef struct Area {
	unsigned int width;
	unsigned int height;
	/**
	 * Matrix of the pixels of the Area.
	 * 1 stands for a filled pixel (displayed as #)
	 * 0 stands for an empty pixel (displayed as .)
	 */
	BOOL** mat;
	/** Contains all pointers to the shapes the Area contains */
	Shape* shapes[SHAPE_MAX];
	/** Amount of elements in the `shapes` array */
	int nb_shape;
} Area;

/**
 * Dynamically allocates an Area.
 * @param width The width of the Area
 * @param height The height of the Area
 * @return A pointer to the allocated Area
 */
Area* create_area(unsigned int width, unsigned int height);
/**
 * Appends a shape to the Area's shape array
 * @param area The area in which we want to append the shape
 * @param shape The shape to append
 * @return There is nothing to return
 */
void add_shape_to_area(Area *area, Shape *shape);
/**
 * Sets all the pixels of the area to 0
 * @param area The area to clear
 * @return There isn nothing to return
 */
void clear_area(Area *area);
/**
 * Empties the Area's shape array
 * @param area The area to clear
 * @return There is nothing to return
 */
// We decided not to clear the pixels when deleting the shapes. It could happen to be a handy feature.
void erase_area(Area *area);
/**
 * Frees the memory allocated to the Area, all its shapes, and its pixel matrix
 * @param area The Area to delete
 * @return There is nothing to return
 */
void delete_area(Area *area);
/**
 * Fills the Area's pixel matrix with respect to the shapes it contains
 * @param area The area to draw
 * @return There is nothing to return
 */
void draw_area(Area *area);
/**
 * Prints the pixels of the area in the terminal. (. for an empty pixel, # for a filled pixel)
 * @param area The area to print
 * @return There is nothing to return
 */
void print_area(Area *area);

#endif